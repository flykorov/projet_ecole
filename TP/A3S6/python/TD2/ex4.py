import pandas as pd

sal = pd.read_csv("Salaries.csv")

print(round((sal['BasePay'].mean()),2))
