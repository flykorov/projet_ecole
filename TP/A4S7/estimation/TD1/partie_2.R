str(iris)

iris_length <- iris$Sepal.Length

taille <- length(iris_length)

moyenne <- mean(iris_length)

ecart_type <- sd(iris_length)

intervalle_confiance <- t.test(iris_length)

print(paste("La nombre de l'echantillon est", taille))
print(paste("La moyenne de taille d'un iris est de", moyenne))
print(paste("L'écart type d'un iris est de", ecart_type))
print(paste("L'intervalle de confiance de la base iris est de", ecart_type))

