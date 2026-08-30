import sys
import os

# Ajouter le chemin du répertoire racine du projet
project_root = os.path.abspath("..")
sys.path.append(project_root)

import torch
from torch.utils.data import DataLoader, Dataset
import pandas as pd
from fastapi import FastAPI, Request
from pydantic import BaseModel
from utils.pipeline import TextProcessingPipeline
from utils.dataset import ToxicityDataset
from fastapi.responses import JSONResponse
from typing import List

# Initialiser l'application FastAPI
app = FastAPI()

# Gestionnaire global pour capturer les erreurs
@app.exception_handler(Exception)
async def global_exception_handler(request: Request, exc: Exception):
    # Log l'erreur complète dans la console pour la déboguer
    print(f"URL: {request.url}")
    print(f"Erreur : {repr(exc)}")
    return JSONResponse(
        status_code=500,
        content={"message": "Une erreur interne s'est produite.", "detail": repr(exc)},
    )

# Charger le modèle
device = torch.device("cuda" if torch.cuda.is_available() else "cpu")
print(f"Device utilisé : {device}")
model = torch.load("roberta_toxicity_10000Samples_V4_Blanced_Train.pt")
model.to(device)
model.eval()

# Définir la structure des données d'entrée
class TextInput(BaseModel):
    id: str
    text: str

@app.post("/predict")
async def predict(input: TextInput):
    # Étape 1 : Créer le DataFrame avec les colonnes `id` et `text`
    df = pd.DataFrame([{"id": input.id, "comment_text": input.text}])

    # Étape 2 : Appliquer la pipeline pour prétraiter les données
    pipeline = TextProcessingPipeline()
    tokenized_df = pipeline.run_pipeline(df)

    # Ajouter une colonne fictive pour les cibles (obligatoire pour ToxicityDataset)
    target_columns = ["toxic"]  # Noms fictifs des colonnes cibles
    for col in target_columns:
        tokenized_df[col] = 0  # Valeurs arbitraires car elles ne sont pas utilisées pour la prédiction

    # Étape 3 : Créer le Dataset personnalisé
    dataset = ToxicityDataset(tokenized_df, target_columns)

    # Étape 4 : Créer un DataLoader
    dataloader = DataLoader(dataset, batch_size=1)

    # Étape 5 : Effectuer la prédiction
    for batch in dataloader:
        input_ids = batch["input_ids"].to(device)
        attention_mask = batch["attention_mask"].to(device)

        # Passer les données dans le modèle
        with torch.no_grad():
            outputs = model(input_ids=input_ids, attention_mask=attention_mask)
        
        logits = outputs.logits
        # Si logits est un scalaire (0-dimensionnel), ne pas indexer
        if logits.ndimension() == 0:
            probabilities = torch.sigmoid(logits).item()
        else:
            probabilities = torch.sigmoid(logits).squeeze().item()
        prediction = "toxic" if probabilities  > 0.5 else "non-toxic"

        # Retourner la réponse
        return {
            "id": input.id,
            "prediction": prediction,
            "confidence": float(probabilities),
        }


## Pour pouvoir traiter des batch de commentaires : 

# Définir la structure des données d'entrée pour plusieurs textes
class TextInputs(BaseModel):
    inputs: List[TextInput]

@app.post("/predict_batch")
async def predict_batch(inputs: TextInputs):
    # Étape 1 : Créer un DataFrame avec les colonnes `id` et `text`
    data = [{"id": input.id, "comment_text": input.text} for input in inputs.inputs]
    df = pd.DataFrame(data)

    # Étape 2 : Appliquer la pipeline pour prétraiter les données
    pipeline = TextProcessingPipeline()
    tokenized_df = pipeline.run_pipeline(df)

    # Ajouter une colonne fictive pour les cibles (obligatoire pour ToxicityDataset)
    target_columns = ["toxic"]  # Noms fictifs des colonnes cibles
    for col in target_columns:
        tokenized_df[col] = 0  # Valeurs arbitraires car elles ne sont pas utilisées pour la prédiction

    # Étape 3 : Créer le Dataset personnalisé
    dataset = ToxicityDataset(tokenized_df, target_columns)

    # Étape 4 : Créer un DataLoader
    dataloader = DataLoader(dataset, batch_size=1)

    # Étape 5 : Effectuer la prédiction pour chaque entrée
    predictions = []
    for idx, batch in enumerate(dataloader):
        input_ids = batch["input_ids"].to(device)
        attention_mask = batch["attention_mask"].to(device)

        # Passer les données dans le modèle
        with torch.no_grad():
            outputs = model(input_ids=input_ids, attention_mask=attention_mask)
        
        logits = outputs.logits
        # Si logits est un scalaire (0-dimensionnel), ne pas indexer
        if logits.ndimension() == 0:
            probabilities = torch.sigmoid(logits).item()
        else:
            probabilities = torch.sigmoid(logits).squeeze().item()
        prediction = "toxic" if probabilities > 0.5 else "non-toxic"

        # Ajouter le résultat à la liste
        predictions.append({
            "id": str(df.iloc[idx]["id"]),
            "prediction": prediction,
            "confidence": float(probabilities),
        })

    # Retourner la réponse avec toutes les prédictions
    return {"predictions": predictions}
