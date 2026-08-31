str(iris)

virginica <- iris$Sepal.Width[iris$Species == "virginica"]
setosa <- iris$Sepal.Width[iris$Species == "setosa"]

affirmation <- t.test(virginica, mu=mean(setosa))

print(affirmation)

print(mean(virginica))
print(mean(setosa))
