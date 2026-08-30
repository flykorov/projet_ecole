import pandas as pd

sal = pd.read_csv("Salaries.csv")
person = 'JOSEPH DRISCOLL'

tab = {x:y for x, y in zip(sal['EmployeeName'], sal['TotalPayBenefits'])}

print(tab[person])