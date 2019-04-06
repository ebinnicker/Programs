fDir = "C:/Users/ebinnicker/Documents/Classes/Spring 2019/GEOG 312/Assignments/05/"
fNames = list.files(fDir, pattern=".csv")
fPaths = paste0(fDir, fNames)

install.packgages('class')
library(class)
?knn

for (i in 1:length(fPaths)){
  # read in table:
  tab = read.csv(fPaths[i])
  
  # plot locations of samples:
  x = tab$lat_dd
  y = tab$lon_dd
  plot(x, y)
  
  # calculate spatial center (arith. mean):
  xC = mean(x)
  cat("\nx mean", xC)
  yC = mean(y)
  cat("\ny mean", yC)
  points(xC, yC, pch=16)
  
  # calculate standard distance:
  Sd = sqrt(sum((x-xC)^2)+sum((y-yC)^2))
  cat("\nSD", Sd)
  
  # output result
  print(fPaths[i])
  
  # plot standard distance as a circle: 
  par(new=T)
  symbols(xC, yC, circles=Sd,
          xlim=range(x),
          ylim=range(y),
          xlab="",
          ylab="",
          main=fNames[i])
  
  
  # Question 5
  n = nrow(tab)
  A = 0.0000128
  density = n/A
  cat("\nDensity:", density)
  
  NNDr = 0.5 * (1/(sqrt(density)))
  cat("\nNNDr:", NNDr)
  
  popNND = 0.26136/(sqrt((n*n)/A))
  cat("\npopNND:", popNND)
  
}
  


?knn()
  
