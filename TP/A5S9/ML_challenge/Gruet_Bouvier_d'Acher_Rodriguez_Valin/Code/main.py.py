# -*- coding: utf-8 -*-
"""
Created on Sun Sep 15 10:28:05 2024

@author: Valin
"""
#import matplotlib.pyplot as plt
#import numpy as np
import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.svm import SVC
from sklearn.metrics import classification_report
from sklearn.metrics import accuracy_score
from sklearn.pipeline import Pipeline

####################################################################### Architecture globale du modéle #######################################################################
# Chargement des données -> Supprésion des valeurs abérantes -> Extraction des landmarks -> Division de la base de donnée en train et test (80/20) -> Normalisation des données -> Entrainement d'un modéle de SVM (Support Vector Machine) 
####################################################################################################################################################################################


################################## A Compléter si besoin ###################################
PATH = "project_data/project_data/training_set.csv" # Chemin vers le dataset d'entrainement
PATH_VALIDATION = "project_data/test_final/test_final/test_data.csv"
NOMBRE_LANDMARKS = 64 # 64 landmarks

# Pipeline de normalisation et PCA
pipeline = Pipeline([
    ('scaler', StandardScaler()),  # Normalisation des données
    ('svm', SVC(kernel='linear', C=3.916744597312221, degree=8, gamma= 2.2475103435398593)) # Modéle SVM avec les hyper-paramétres fine-tuner
])
###############################################################################################


# Chargement des données
data_full = pd.read_csv(PATH)

# Supprésion des valeurs abérentes
anihiler_les_doublons = [155, 338, 248, 431, 528, 661]
data = data_full.drop(index=anihiler_les_doublons)
data.reset_index(drop=True, inplace=True)

# Extraction des landmarks et des Labels
X = data[[f' x_{i}' for i in range(NOMBRE_LANDMARKS)] + [f' y_{i}' for i in range(NOMBRE_LANDMARKS)]]  
y = data['labels']

# Diviser les données en ensembles d'entraînement et de test
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.20, random_state=43)

# Pré-traitement des données et Entrainement
pipeline.fit(X_train, y_train)

# Résultats si besoin 
# accuracy = pipeline.score(X_test, y_test)
# print(f"Accuracy: {accuracy:.2f}")


# Appliquer le model sur les données de validation
data_to_predict = pd.read_csv(PATH_VALIDATION)
X_to_pred = data_to_predict[[f' x_{i}' for i in range(NOMBRE_LANDMARKS)] + [f' y_{i}' for i in range(NOMBRE_LANDMARKS)]]
df_prediction = pd.DataFrame(pipeline.predict(X_to_pred), columns=["labels"])
df_prediction.to_csv('result.csv', index=False)
