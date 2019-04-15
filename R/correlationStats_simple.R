# Correlation statistics:

# XY vectors
x = c(0, 3, 6, 9)
y = c(1, 3, 2, 0)

#  plot:
plot(x, y)

# standard deviation of X and Y:
s_x = sd(x)
s_y = sd(y)

# variance is the square of standard deviation:
s_x^2
var(x)
var(y)

# covariance (can use var(x,y,) as well):
s_xy = cov(x, y)

# correlation coefficent:
r = var(x, y)/(sd(x)*sd(y))
r = cor(x, y)

# test for significance of correlation:
cor.test(x, y)

# examine how t.statistic varies with changes in r:
r = seq(-1, 1, length.out=100)
n = 20
t = (r*sqrt(n-2))/sqrt(1-r^2)
plot(r, t, type="l")
