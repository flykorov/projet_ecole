import pandas as pd

sal = pd.read_csv("Salaries.csv")

sal = pd.DataFrame(sal, index='0 1 2 3 4'.split())

print(sal)