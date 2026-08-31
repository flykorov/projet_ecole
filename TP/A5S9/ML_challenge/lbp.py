from skimage.feature import local_binary_pattern
from sklearn.preprocessing import StandardScaler
from sklearn.model_selection import train_test_split
from sklearn.svm import SVC
from sklearn.metrics import accuracy_score, classification_report, confusion_matrix
from skimage.color import rgb2gray

import matplotlib.pyplot as plt
import matplotlib.image as mpimg
import numpy as np
import pandas as pd


def extract_lbp_features(image, P=8, R=1):
    """
    Extrait les caractéristiques LBP d'une image.
    
    Parameters:
        image (ndarray): Image en niveaux de gris.
        P (int): Nombre de points autour du pixel central.
        R (int): Rayon du cercle sur lequel les points sont échantillonnés.

    Returns:
        features (ndarray): Histogramme des descripteurs LBP.
    """
    image = rgb2gray(image)
    lbp = local_binary_pattern(image, P, R, method='uniform')
    # Calculer l'histogramme des descripteurs LBP
    n_bins = int(P * (P - 1) / 2 + 3)
    hist, _ = np.histogram(lbp, bins=np.arange(0, n_bins + 1), density=True)
    return hist

dossier_img = 'visage/normal/'
path = "project_data/training_set/"
csv_data = "project_data/training_set.csv"

data_complet = pd.read_csv(csv_data)

anihiler_les_doublons = [155, 338, 248, 431, 528, 661]
data = data_complet.drop(index=anihiler_les_doublons)
data.reset_index(drop=True, inplace=True)


nom = data['id']
label = data['labels']



images = []

for i in nom:
    img = mpimg.imread(dossier_img + i)
    images.append(img)

X = [extract_lbp_features(image) for image in images]
y = label

scaler = StandardScaler()
X_scaled = scaler.fit_transform(X)

X_train, X_test, y_train, y_test = train_test_split(X_scaled, y, test_size=0.2, random_state=42)


model = SVC(kernel='rbf', C=100)
model.fit(X_train, y_train)

y_pred = model.predict(X_test)

accuracy = accuracy_score(y_test, y_pred)
print(f"Précision du modèle SVM : {accuracy:.4f}")



print("Rapport de classification:")
print(classification_report(y_test, y_pred))

print("Matrice de confusion:")
print(confusion_matrix(y_test, y_pred))