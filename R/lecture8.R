# generate 100 normally-distributed grades:
grades = rnorm(n=100, mean=70, sd=20)
print(grades)

# can't have grades > 100:
grades[grades>100] = 100

plot(grades)
hist(grades)
boxplot(grades)
qqnorm(grades)

# what is the probability of getting an A, if an A is greater 90?
length(grades[grades > 90])/length(grades)

# create a function of the probability of getting an A:
goodGrade <- function(X, threshold){
  prob = length(X[X>threshold])/length(X)
  return(prob)
}

# run our function:
goodGradeProb = goodGrade(X=grades, threshold=70)
print(goodGradeProb)

# qnorm is the qunatile function for the normal distribution:
qnorm(p=0.90, mean=70, sd=20)

# what is the probability of "grades" being greater than the 90th percentile?
length(grades[grades>qnorm(p=0.90, mean=70, sd=20)])/length(grades)

# R has many distributions: 
?distributions 


####
# HW#2
lat = rnorm(30, 32, 0.01)
lon = rnorm(30, -50, 0.01)
temp = rlnorm(3, 22, 2)

lat_mean = mean(lat)
lon_mean = mean(lon)

lat_weightedMean = sum(lat*temp)/sum(temp)
lon_weightedMean = sum(lon*temp)/sum(temp)

plot(lon, lat, cex=2*temp/max(temp), col=rgb(0,0,0,0.5), pch=16)

points(lon_mean, lat_mean, col="red", pch=3, cex=2)

points(lon_weightedMean, lat_weightedMean, col="blue", pch=3, cex=2)

# how to download and laod a package in R:
install.packages("foreign")
library(foreign)

# if you are getting weird problems with your data
# e.g. your data have quotations around them, you probably
# have an non-numeric character in your column.

# try
x = c("1", "2", "3")
as.numeric(as.vector(x))