import numpy as np
import tensorflow as tf

# Create needed objects
sgd = tf.keras.optimizers.SGD(learning_rate=0.2, momentum=0.9)
var = tf.Variable(np.array([-2.0,-7.0]))
cost = lambda: 5 * (var[0]**2) + (var[1]**2)/2 - 3 * (var[0] + var[1])

# Perform optimization
iterations = -1
temp = var.numpy()
epsilon = 1e-9

while(True): 
  sgd.minimize(cost, var_list=[var])
  
  if np.all(abs(var.numpy() - temp) < epsilon):
      break
  iterations=iterations+1
  temp = var.numpy()
  
  
print('Minimizer:', var.numpy()) 
print('Iterations:', iterations)
print('Minimum:', cost().numpy()) 