library(rpart)
library(rpart.plot)
tree = rpart(Species ~., data=iris)
rpart.plot(tree) #plot tree
print(tree$variable.importance)

#predict
head(predict(tree,iris)) #predict (model, data) : gave probability in each class
head(predict(tree,iris,type = "class")) # give the prediction's class from most probability number

#matrix
library(caret)
res <- predict(tree,iris,type = "class")
confusionMatrix(res, iris$Species)

#--------------------
# Train-Test Split
#--------------------

#train-test split
library(dplyr)
iris.train <- sample_frac(iris, 0.6)
training.ind <- as.integer(rownames(iris.train))
iris.test <- iris[-training.ind,]

index = sample(1:nrow(iris), 90)
iris.train <- iris[index,]
iris.test <- iris[-index,]


summary(iris.train) #check train set
summary(iris.test) #check test set

tree_h <- rpart(Species ~ ., data = iris.train)  #train model from train set
res_h <- predict(tree_h,iris.test,type = "class") #evaluate on test set
print(confusionMatrix(res_h, iris.test$Species))


#--------------------
#Facing fitting problem
#--------------------

#using pruning
tree_h2 <- rpart(Species ~ ., data =iris.train,control = rpart.control(cp =0.001))
# overfitting caused when the tree is so big and complex
# could change complexity parameter (cp) if low -> tree be more simple
# not garantee that acc. gonna be better
res_h2 <-predict(tree_h2,iris.test,type ="class")
print(confusionMatrix(res_h2,iris.test$Species))

#manual tuning
control <- trainControl(method="boot",number=1)
metric <- "Accuracy"
cp <- c(0.001,0.01,0.1,1,5,10,15,20)
tunegrid <- expand.grid(.cp=cp)
tree_manual <- train(Species~., data=iris.train, method="rpart", metric=metric, tuneGrid=tunegrid, trControl=control)
print(tree_manual)
    # return Accuracy in each cp
    # using cp that gave high acc. high kappa

#Random Search
control <- trainControl(method="boot",number=1, search = "random")
metric <- "Accuracy"
tree_rand <- train(Species~., data=iris.train, method="rpart", metric=metric, tuneLength = 15, trControl=control)
print(tree_rand)
plot(tree_rand)
# we command 15 step of cp randomly
# after 3 step it get same acc. so it stop, as it show in graph 