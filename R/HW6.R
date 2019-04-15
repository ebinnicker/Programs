# file path and data
fPath = "C:/Users/ebinnicker/Documents/Classes/Spring 2019/GEOG 312/Assignments/06/assignment06_data.csv"
tab = read.csv(fPath, header=T)

# plot X (elevation) and Y (temperature)
plot(tab$elev_m, tab$temp_C, main="Assignment 6: Elevation and Temperature", xlab="Elevation (meters)", ylab="Temperature (Celsius)")
# linear regression
reg = lm(tab$temp_C ~ tab$elev_m)

# linear regression statistics
summary(reg)
#linear regression line on plot
abline(reg, col="red")

# get intercept and slope values: 
a = reg$coefficients[1][[1]]
b = reg$coefficients[2][[1]]

# function to predict y from x: 
predictor <- function(a, b, x){
  y = a + b*x
  return(y)
}

cat("Y = ", a, " + ", b, "x")
