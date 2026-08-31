import matplotlib.pyplot as plt
import matplotlib.image as mpimg
import numpy as np
import pandas as pd
from sklearn import svm
from sklearn.model_selection import train_test_split, GridSearchCV
from sklearn.metrics import classification_report, accuracy_score, confusion_matrix, ConfusionMatrixDisplay, classification_report
from sklearn.preprocessing import normalize
from skimage.feature import local_binary_pattern
from skimage.color import rgb2gray
from sklearn.preprocessing import StandardScaler
from sklearn.svm import SVC
from mtcnn.mtcnn import MTCNN
import cv2
from PIL import Image
from mtcnn import MTCNN

# extraire les visages des photos
def extraire_visage(dir_entrer, dir_sortie):

	detector = MTCNN()
	for i in name_test:
		img = mpimg.imread(dir_entrer + i)
		result = detector.detect_faces(img)
		x, y, width, height = result[0]['box']

		face_image = img[y:y+height, x:x+width]
		image = Image.fromarray(face_image)
		image.save(dir_sortie + i)


# création de l'histogrames avec le LBP
def extract_lbp_features(image, poids, P=8, R=2):
    
    hist = []
    for i, p in zip(image, poids):
        lbp = local_binary_pattern(i, P, R, method='nri_uniform')

        n_bins = int(lbp.max() + 1)

        histogram, _ = np.histogram(lbp, bins=np.arange(0, n_bins + 1), range=(0, n_bins), density=False)
        for i in histogram:
            hist.append(i * p)

    return hist

# subdivision des images 
def subdiviser_image(image, nb_ligne=7, nb_colonne=6, taille_ligne=21, taille_colonne=18):
    image_resized = cv2.resize(image, (nb_colonne*taille_colonne, nb_ligne*taille_ligne))

    image_decouper = []
    for i in range(nb_ligne):
        for j in range(nb_colonne):
            bou = image_resized[i * taille_ligne : (i+1) * taille_ligne, j * taille_colonne : (j+1) * taille_colonne]
            image_decouper.append(bou)


    return image_decouper


path = "project_data/training_set/"
csv_data = "project_data/training_set.csv"

data_complet = pd.read_csv(csv_data)

anihiler_les_doublons = [155, 338, 248, 431, 528, 661]
data = data_complet.drop(index=anihiler_les_doublons)
data.reset_index(drop=True, inplace=True)


nom = data['id']
label = data['labels']

dossier_normal = 'visage/normal/'

# extrait les visages des images du dossier de données de train
# prend 30 min
# extraire_visage(path, dossier_normal)

images = []

# matrice des poids
poids = [0, 1, 1, 1, 1, 0, 
         2, 2, 1, 1, 2, 2,
         2, 4, 4, 4, 4, 2,
         0, 1, 0, 0, 1, 0,
         1, 1, 2, 2, 1, 1,
         1, 2, 4, 4, 2, 1,
         0, 1, 2, 2, 1, 0
    ]

taille_ligne = 35
taille_colonne = 30

# conversion des fichiers de base
for i in nom:
    img = mpimg.imread(dossier_normal + i)
    img = (rgb2gray(img) * 255).astype(np.uint8)

    img = subdiviser_image(img, taille_ligne=taille_ligne, taille_colonne=taille_colonne)
    
    img = extract_lbp_features(img, poids)

    images.append(img)


X_train, X_test, y_train, y_test = train_test_split(images, label, test_size=0.2, random_state=42)

model = SVC(kernel='rbf', C=6.5, gamma='scale', random_state=42)
model.fit(X_train, y_train)

y_pred = model.predict(X_test)

accuracy = accuracy_score(y_test, y_pred)
print(f"Précision du modèle SVM : {accuracy:.4f}")

print("Rapport de classification:")
print(classification_report(y_test, y_pred))

print("Matrice de confusion:")
print(confusion_matrix(y_test, y_pred))


# path des fichiers
dir_test = "test_final/testing_set/"
dir_csv = "test_final/test_data.csv"
dir_resized = "visage/test/"


data_test = pd.read_csv(dir_csv)

name_test = data_test['id']

# extrait les visages des images du dossier de données de test_final
# prend 10 min
# extraire_visage(dir_test, dir_resized)

# création des données pour le test_final
images_test = []
for i in name_test:
    img = mpimg.imread(dir_resized + i)
    img = (rgb2gray(img) * 255).astype(np.uint8)

    img = subdiviser_image(img, taille_ligne=35, taille_colonne=30)
    
    img = extract_lbp_features(img, poids)

    images_test.append(img)

# prédiction pour le test_final
y_pred_test = model.predict(images_test)


# Conversion des résultats en fichier csv
df_prediction = pd.DataFrame(y_pred_test, columns=["labels"])
df_prediction.to_csv('result.csv', index=False)
