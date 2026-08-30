import pandas as pd
import numpy as np
import math

sal = pd.read_csv("Salaries.csv")

print(sal.loc[sal['BasePay']])

# t = [2011, 2012, 2013, 2014]

# t2 = list([x,y] for x, y in zip(sal['Year'], sal['BasePay']))
# tab = {k:[v for l, v in t2 if k == l and not math.isnan(v)] for k in t}

# print('Year')
# print(round(sum(tab[2011])/len(tab[2011]), 6))
# print(round(sum(tab[2012])/len(tab[2012]), 6))
# print(round(sum(tab[2013])/len(tab[2013]), 6))
# print(round(sum(tab[2014])/len(tab[2014]), 6))