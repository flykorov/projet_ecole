import pandas as pd

sal = pd.read_csv("Salaries.csv")
person = 'NATHANIEL FORD'

tab = {x:y for x, y in zip(sal['TotalPayBenefits'], sal['EmployeeName'])}
print(tab[max(sal['TotalPayBenefits'])])