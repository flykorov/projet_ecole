str(iris)

petal <- iris$Petal.Length[iris$Species == "virginica"]
print(petal)

affirmation <- t.test(petal, mu=5.7)

print(affirmation)

moy = mean(petal)

risque <- power.t.test(n=length(petal), delta=5.7-moy, sd=sd(petal), type='one.sample', alternative='two.sided')

print(risque)

remplace <- power.t.test(power=0.8, delta=5.7-moy, sd=sd(petal), type='one.sample', alternative='two.sided')

print(remplace)
