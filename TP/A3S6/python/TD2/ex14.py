import pandas as pd

sal = pd.read_csv("Salaries.csv")

tab = sal['JobTitle']
res = [mot for mot in tab if mot.find("CHIEF") != -1  or mot.find("Chief") != -1]
print(len(res))