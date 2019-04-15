# Summary
# automate calculation of spatial center, standard distance, 
# and graphic output

# Inputs: CSV files
# Outputs: PDF scatter plots with spatial center and standard distance


################################################################################
# hardcoded constants 
################################################################################
# specify directory containing CSV tables:
fDir = "C:/Users/ebinnicker/Documents/Classes/Spring 2019/GEOG 312/code"

# list CSV table files names:
fNames = list.files(fDir, pattern=".csv")
fPaths = paste0(fDir, fNames)


################################################################################
# Write out one PDF file with multiple pages:
################################################################################
# define PDF file path:
pdfPath = paste0(fDir, "pdfOut.pdf")
pdf(pdfPath)
# note: jpeg function will write out jpg files:

for (i in 1:length(fPaths)){
  # read in table:
  tab = read.csv(fPaths[i])
  
  # plot locations of samples:
  x = tab$X
  y = tab$Y
  plot(x, y)
  
  # calculate spatial center (arith. mean):
  xC = mean(x)
  yC = mean(y)
  points(xC, yC, pch=16)
  
  # calculate standard distance:
  Sd = sqrt(sum((x-xC)^2)+sum((y-yC)^2))
  
  # plot standard distance as a circle: 
  par(new=T)
  symbols(xC, yC, circles=Sd,
          xlim=range(x),
          ylim=range(y),
          xlab="",
          ylab="",
          main=fNames[i])
}

# close PDF device:
dev.off()



# Write out one PDF for each plot:
# define PDF file paths:
pdffNames = sub(".csv", ".pdf", fNames)
pdfPaths = paste0(fDir, pdffNames)

# for each CSV file:
for (i in 1:length(fPaths)){
  # set up PDF output:
  pdf(pdfPaths[i])
  
  # read in table:
  tab = read.csv(fPaths[i])
  
  # plot locations of samples:
  x = tab$X
  y = tab$Y
  plot(x, y)
  
  # calculate spatial center (arith. mean):
  xC = mean(x)
  yC = mean(y)
  points(xC, yC, pch=16)
  
  # calculate standard distance:
  Sd = sqrt(sum((x-xC)^2)+sum((y-yC)^2))
  
  # plot standard distance as a circle: 
  par(new=T)
  symbols(xC, yC, circles=Sd,
          xlim=range(x),
          ylim=range(y),
          xlab="",
          ylab="",
          main=fNames[i])
  
  dev.off()
}


# generate 80 hashes (code should not be more than 80 chars per line)
paste0(rep("#", 80), collapse="")
