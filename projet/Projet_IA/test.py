from sklearn.datasets import load_digits
digits = load_digits()
print(digits.data.shape)

import matplotlib.pyplot as plt
# plt.gray()

a = plt.imread("huit.png");
print(a)
plt.imshow(a)
plt.matshow(digits.images[0])
plt.matshow(digits.images[10])
plt.matshow(digits.images[20])
plt.matshow(digits.images[30])


plt.show()