import pandas as pd 
import numpy as np 

"""
x_train = pd.read_csv('x_train.csv', header=None)
y_train = pd.read_csv('y_train.csv', header=None)

new_x_train = []
new_y_train = y_train.to_numpy().flatten()

for (_, X), (_, Y) in zip(x_train.iterrows(), y_train.iterrows()):

    x = X.to_numpy()
    y = Y.to_numpy()

    for i in range(5):
        
        new_x_train.append(np.concatenate((x[i:], y[:i])))
        

new_x_train = pd.DataFrame(new_x_train)
new_y_train = pd.DataFrame(new_y_train)

new_x_train.to_csv('new_x_train.csv', header=None, index=False)
new_y_train.to_csv('new_y_train.csv', header=None, index=False)

"""
x_valid = pd.read_csv('x_valid.csv', header=None)


resultat = []


for _, row in x_valid.iterrows():

    r = []
    for i in range(5):
        res = 1 # model_tf.predict(row)

        temp = row.to_numpy()[1:]
        temp = np.append(temp, res)
        row = pd.DataFrame(temp)
        
        r.append(res)
    resultat.append(r)

print(resultat)

