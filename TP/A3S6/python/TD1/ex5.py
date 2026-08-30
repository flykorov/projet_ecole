import numpy as np

def vector_ops(a, b):
	produit_scalaire = a.dot(b)
	
	normeA = np.linalg.norm(a)
	normeB = np.linalg.norm(b)
	cosinus = produit_scalaire/(normeB*normeA)

	difference = np.subtract(a, b)
	euclidienne = np.linalg.norm(difference)

	return produit_scalaire, cosinus, euclidienne

a = np.array([ 4,  4, 87, 17, 92, 47, 30, 38, 41, 10])
b = np.array([23, 98, 68, 39,  7, 24, 16,  1, 98, 91])

dot_product, cosine_similarity, euclidean_distance = vector_ops(a, b)
print (round(dot_product, 2), round(cosine_similarity, 2), round(euclidean_distance, 2))