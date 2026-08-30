import pandas as pd

sal = pd.read_csv("Salaries.csv")

tab = {x:y for x, y in zip(sal['TotalPayBenefits'], sal['EmployeeName'])}
print(f'{tab[min(sal["TotalPayBenefits"])]} {min(sal["TotalPayBenefits"])}')