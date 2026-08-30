import numpy as np

def normalize_features(a):
	moyenne = np.mean(a, axis=1, keepdims=True)
	ecart_type = np.std(a, axis=1, keepdims=True)
	res = np.array([np.round((a[i]-moyenne[i])/ecart_type[i], 2) for i in range(len(a))])

	return res 


a = np.array([[11.17, 99.8 , 99.39, 29.82, 85.58],
       [86.79, 25.27, 38.78, 60.27, 57.96],
       [14.43,  6.82, 56.97, 82.43, 21.58],
       [42.73, 74.65, 58.13, 47.49, 25.94],
       [79.84, 84.1 ,  2.98, 28.59, 16.6 ]])
a = normalize_features(a)
print (a)