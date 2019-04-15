# linear regression

# define file path:
fPath = "/Users/ebinnicker/GEOG312/"

# read in CSV file:
tab = read.csv(fPath, header=T)

# plot X and Y:
plot(tab$X, tab$Y)

# take linear regression:
reg = lm(tab$Y ~ tab$X)

# view statistics of linear regression:
summary(reg)

# plot linear regression line:
abline(reg, col="red")

# get intercept and slope values: 
a = reg$coefficients[1][[1]]
b = reg$coefficients[2][[1]]

# build a function to predict y from x: 
predictor <- function(a, b, x){
  y = a + b*x
  return(y)
}

# test function: 
predictor(a, b, x=2000)
