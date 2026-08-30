import pandas as pd

sal = pd.read_csv("Salaries.csv")

tab = sal.groupby("JobTitle")

a = tab.count()

nom = sal["JobTitle"]
nom = list(set(nom))
nom = sorted(nom)

nb = a["Id"]
res = sorted(nb)

plugro = res[-5:]
sol = [x for x, y in enumerate(nb) if y in plugro]

nom = [nom for i, nom in enumerate(nom) if i in sol]

plugro.reverse()
nom.reverse()
soluce = pd.DataFrame(plugro, index=nom, columns='JobTitle'.split())

print(soluce['JobTitle'])