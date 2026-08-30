"""
Pipeline de pre-traitement des données pour le Projet de NLP. La pipeline a spécifiquement été disingé pour l'utilisation du model RoBERTa
Entrée : Un dataframe de train ou de test avec au moin la colonne : "comment_text"
Sortie : Le même dataframe avec l'ajout des colonnes : "processed_text", "input_ids" et "attention_mask"
input_ids & attention_mask peuvent être directement utilisées comme entrée du model RoBERTa
"""

# Imports : 
import pandas as pd
from transformers import RobertaTokenizer
import re


# Conservation de la ponctuation car RoBERTa pré-entraîné avec la ponctuation
def PreProcessText(text):
    # Vérification que l'entrée est une chaîne de caractères
    if not isinstance(text, str):
        raise ValueError("L'entrée doit être une chaîne de caractères (str).")
    
    # Conversion en minuscule - Pas forcément néssésaire car RoBERTa pré-entraîné avec les majuscules aussi
    # text = text.lower()
    
    # Suppression des retours à la ligne
    text = text.replace("\n", " ")
    
    # On enleve les accents (j'espere que j'en ai pas oublie)
    text = re.sub(r'[áàâäãå]', 'a', text)
    text = re.sub(r'[éèêë]', 'e', text)
    text = re.sub(r'[íìîï]', 'i', text)
    text = re.sub(r'[óòôöõ]', 'o', text)
    text = re.sub(r'[úùûü]', 'u', text)
    text = re.sub(r'[ç]', 'c', text)
    text = re.sub(r'[ñ]', 'n', text)
    
    # Retirer les liens : 
    text = re.sub(r'http\S+|www\S+', '', text)
    
    # Suppression des adresses IP
    text = re.sub(r'\b(?:\d{1,3}\.){3}\d{1,3}\b', '', text)
    
    # Suppression des dates et heures dans des formats variés
    text = re.sub(
        r'\b(?:\d{1,2}:\d{2}(?::\d{2})?,?\s)?'  # Heure : "21:51" ou "21:51:30", optionnelle
        r'(?:\d{1,2}[/-]\d{1,2}[/-]\d{2,4}|'    # Date format court : "11/01/2016" ou "11-01-16"
        r'\w+\s\d{1,2},?\s\d{4})'               # Date avec mois en lettres : "January 11, 2016"
        r'(?:\s\(UTC\))?',                      # Fuseau horaire optionnel : "(UTC)"
        '', text, flags=re.IGNORECASE
    )
    
    # Suppression des balises "(talk)"
    text = re.sub(r'\(talk\)', '', text, flags=re.IGNORECASE)
    
    # Suppression des caractères spéciaux inutiles (conserver les !, ?, ., ,)
    text = re.sub(r'[^a-zA-Z0-9\s.,!?]', '', text)
    
    # Suppression des espaces multiples
    text = re.sub(r'\s+', ' ', text).strip()
    
    return text
    
    
class TextProcessingPipeline:
    def __init__(self, tokenizer_name="roberta-base"):
        self.tokenizer = RobertaTokenizer.from_pretrained(tokenizer_name)
    
    def preprocess(self, df):
        """
        Applique le prétraitement au dataframe et ajoute une colonne `processed_text`.
        """
        # Vérification des colonnes obligatoires
        if 'id' not in df.columns or 'comment_text' not in df.columns:
            raise ValueError("Les colonnes 'id' et 'comment_text' doivent être présentes dans le dataframe.")
        
        # Application du prétraitement
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

    def run_pipeline(self, df):
        """
        Exécute le pipeline complet (prétraitement + tokenization).
        """
        df = self.preprocess(df)
        df = self.tokenize(df)
        return df