#read.csv() for data and assign columns to a variable
lat=rnorm(30,32,0.01)
lon = rnorm(30,-50,0.01)
temp = rnorm(30, 22, 2)

lat_mean=mean(lat)
lon_mean=mean(lon)

#weighted spatial center
lat_weightedMean=sum(lat*temp)/sum(temp)
lon_weightedMean=sum(lon*temp)/sum(temp)

plot(lon,lat, cex=2*temp/max(temp), pch=16)

#points on top of plot
points(lon_mean, lat_mean, col="red", pch=16, cex=2)
points(lon_weightedMean, lat_weightedMean, col="blue", pch=16, cex=2)

#use packages
install.packgages('foreign')
library(foreign)



?barplot()