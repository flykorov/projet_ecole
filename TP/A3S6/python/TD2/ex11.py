import pandas as pd

sal = pd.read_csv("Salaries.csv")

tab = sal.groupby("JobTitle")
print(len(tab.count()))