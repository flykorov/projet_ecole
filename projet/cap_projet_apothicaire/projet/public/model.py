import tensorflow as tf
import sys
import json

def ouvrir_fic(nom='public/matrice.txt'):
    with open(nom, 'r') as fic:
        mat = fic.readline().split()
        return [[int(i) for i in mat]]

def ecrire_res(res, nom='public/resultat.txt'):
    with open(nom, 'w') as fic:
        fic.write(res)

# mat = ouvrir_fic()

def prediction(mat):
    model = tf.keras.models.load_model('projet/CAP/IA_phishing_final')
    return model.predict(mat)

argv = sys.argv[1]
ecrire_res(argv)

matrice = json.loads(argv)

res = prediction(matrice)

print(res)