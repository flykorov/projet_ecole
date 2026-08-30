import pandas as pd
from transformers import AutoTokenizer
import re

# Fonction de prétraitement du texte
def PreProcessText(text):
    if not isinstance(text, str):
        raise ValueError("L'entrée doit être une chaîne de caractères (str).")

    # Conversion en minuscule (optionnel pour DistilBERT)
    text = text.lower()

    # Suppression des retours à la ligne
    text = text.replace("\n", " ")

    # Enlever les accents
    text = re.sub(r'[áàâäãå]', 'a', text)
    text = re.sub(r'[éèêë]', 'e', text)
    text = re.sub(r'[íìîï]', 'i', text)
    text = re.sub(r'[óòôöõ]', 'o', text)
    text = re.sub(r'[úùûü]', 'u', text)
    text = re.sub(r'[ç]', 'c', text)
    text = re.sub(r'[ñ]', 'n', text)

    # Retirer les liens
    text = re.sub(r'http\S+|www\S+', '', text)

    # Suppression des adresses IP
    text = re.sub(r'\b(?:\d{1,3}\.){3}\d{1,3}\b', '', text)

    # Suppression des dates et heures
    text = re.sub(r'\b(?:\d{1,2}:\d{2}(?::\d{2})?,?\s)?(?:\d{1,2}[/-]\d{1,2}[/-]\d{2,4}|[a-zA-Z]+\s\d{1,2},?\s\d{4})', '', text)

    # Suppression des caractères spéciaux inutiles
    text = re.sub(r'[^a-zA-Z0-9\s.,!?]', '', text)

    # Suppression des espaces multiples
    text = re.sub(r'\s+', ' ', text).strip()

    return text

# Classe de prétraitement pour DistilBERT
class TextProcessingPipeline:
    def __init__(self, tokenizer_name="distilbert-base-uncased"):
        self.tokenizer = AutoTokenizer.from_pretrained(tokenizer_name)

    def preprocess(self, df, limit=None):
        """Applique le prétraitement au dataframe et limite la taille si nécessaire."""
        if 'id' not in df.columns or 'comment_text' not in df.columns:
            raise ValueError("Les colonnes 'id' et 'comment_text' doivent être présentes dans le dataframe.")

        if limit is not None:
            df = df.head(limit)  # Limiter les données

        df['processed_text'] = df['comment_text'].apply(PreProcessText)
        return df

    def tokenize(self, df):
        """
        Applique la tokenization sur la colonne `processed_text` et ajoute des colonnes de tokens.
        """
        if 'processed_text' not in df.columns:
            raise ValueError("La colonne 'processed_text' est manquante. Assurez-vous de prétraiter les données avant la tokenization.")

        # Tokenization avec Hugging Face
        tokenized_data = self.tokenizer(
            df['processed_text'].tolist(),
            padding=True,
            truncation=True,
            max_length=512,
            return_tensors="pt"
        )

        # Ajout des tokens en tant que nouvelles colonnes dans le dataframe
        df['input_ids'] = tokenized_data['input_ids'].tolist()
        df['attention_mask'] = tokenized_data['attention_mask'].tolist()

        return df

    def run_pipeline(self, df, limit=None):
        """Exécute le pipeline complet (prétraitement + tokenisation) avec une limite optionnelle."""
        df = self.preprocess(df, limit=limit)
        df = self.tokenize(df)
        return df
