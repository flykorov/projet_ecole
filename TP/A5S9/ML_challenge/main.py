import matplotlib.pyplot as plt
import matplotlib.image as mpimg
import numpy as np
import pandas as pd
from sklearn import svm
from sklearn.model_selection import train_test_split, GridSearchCV
from sklearn.metrics import accuracy_score, confusion_matrix, ConfusionMatrixDisplay, classification_report
from sklearn.preprocessing import normalize


def emotion_accuracy(y_test, y_pred):
    dico = {'sad':[], 'surprise':[], 'neutral':[], 'fear':[], 'anger':[], 'disgust':[], 'happy':[]}
    for t, p in zip(y_test, y_pred):
        if t == p:
            dico[t].append(1)
        else:
            dico[t].append(0)

    for k, v in dico.items():
        dico[k] = sum(v) / len(v) * 100

    # plt.bar(dico.keys(), dico.values())
    # plt.show()

    return dico


path = "project_data/training_set/"
csv_data = "project_data/training_set.csv"

enregistrer_image = "img/"
img_matrice_de_confusion = "cm/"
img_bar = "bar/"

data_complet = pd.read_csv(csv_data)

anihiler_les_doublons = [155, 338, 248, 431, 528, 661]
data = data_complet.drop(index=anihiler_les_doublons)
data.reset_index(drop=True, inplace=True)


nom = data['id']
label = data['labels']
point = data.drop(['id', 'labels'], axis=1)
point_x = data.filter(like='x')
point_y = data.filter(like='y')

point_x_normalize = normalize(point_x)
point_y_normalize = normalize(point_y)
point_normalize = normalize(point)

jernel = ['poly', 'rbf']
C = [1, 2, 3, 5, 10, 20, 50, 100, 500, 1000]
D = [2, 3, 4, 5]
G = [0.1, 0.15, 0.2, 0.25, 0.3, 0.4, 0.5, 0.6, 0.8]

emotion = ['sad', 'surprise', 'neutral', 'fear', 'anger', 'disgust', 'happy']

X_train, X_test, y_train, y_test = train_test_split(point_normalize, label, test_size=0.2, random_state=42)

dico_em = {k:[] for k in jernel}


param = {'kernel':('poly', 'rbf'), 'C':[i^2 for i in range(1, 30, 5)], 
         'gamma':[i/100 for i in range(10, 60, 5)], 
         'degree':[2, 3, 4, 5]
          }

for k in jernel:
    print(f'\n\n{k}')
    for c in C:
        for d in D:
            for g in G:

                clf = svm.SVC(kernel=k, C=c, degree=d, gamma=g)
                clf.fit(X_train, y_train)
                y_pred = clf.predict(X_test)

                accuracy = accuracy_score(y_test, y_pred)
                print(f"Précision du modèle : {accuracy * 100:.2f}%")

                dico = emotion_accuracy(y_test, y_pred)
                print(dico)

                cm = confusion_matrix(y_test, y_pred, labels=clf.classes_)
                ConfusionMatrixDisplay(cm, display_labels=clf.classes_).plot()
                titre_cm = f'matrice de confusion de precision {accuracy * 100:.2f}% de {k} avec C = {c} et D = {d} et G = {g}'

                plt.title(titre_cm)

                kern = 'poly/'
                if k == 'rbf':
                    kern = 'rbf/'

                plt.savefig(enregistrer_image + kern + img_matrice_de_confusion + titre_cm + '.png')
                # plt.show()
                plt.clf()

                plt.bar(dico.keys(), dico.values())

                titre_bar = f'precision par emotion de precision {accuracy * 100:.2f}% de {k} avec C = {c} et D = {d} et G = {g}'
                plt.title(titre_bar)

                plt.savefig(enregistrer_image + kern + img_bar + titre_bar + '.png')
# svc = svm.SVC()
# clf = GridSearchCV(svc, param, scoring='accuracy')
# clf.fit(X_train, y_train)


# print(clf.best_params_)
# y_pred = clf.best_estimator_.predict(X_test)

# print(classification_report(y_test, y_pred))