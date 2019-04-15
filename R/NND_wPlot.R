# specify directory containing CSV tables (used tables from lecture 16):
fDir = "/Users/ebinnicker/GEOG312/"

# list CSV table files names:
fNames = list.files(fDir, pattern=".csv")
fPaths = paste0(fDir, fNames)

tab = read.csv(fPaths[1], header=T)

# assign table columns variables:
x = tab$X
y = tab$Y
site = as.vector(tab$Site)

# plot data:
col = rainbow(length(site), v=0.8)
plot(x,y,type="n")
text(x,y,site,col=col)

# calc distance from A to B
sqrt((x[1]-x[2])^2 + (y[1]-y[2])^2)
segments(x[1], y[1], x[2], y[2], col=col[1])

# calc distance from A to all points:
dist = sqrt((x[1]-x)^2 + (y[1]-y)^2)
segments(x[1], y[1], x, y, col=col)

# take the index of the nearest NEIGHBOR:
nnInd = order(dist)[2]

# take the distance to the nearest NEIGHBOR:
nnDist = dist[nnInd]

# set variables as vectors so they are not overwritten in the j for loop:
nnInd = vector()
nnDist = vector()

# for each point within the table, calculate the nearest neighbor
# and the distance to the nearest neighbor: 
for (j in 1:length(site)){
  
  # calc distance from A to all points:
  dist = sqrt((x[j]-x)^2 + (y[j]-y)^2)
  
  # take the index of the nearest NEIGHBOR:
  nn = order(dist)[2]
  
  # fill in near neighbor index vector:
  nnInd[j] = nn
  
  # take the distance to the nearest NEIGHBOR:
  nnDist[j] = dist[nn]
  
}

# plot the nearest neighbors:
plot(x, y, type="n")
text(x, y, site, col=col)
segments(x, y, x[nnInd], y[nnInd], col=col)
text((x+x[nnInd])/2, (y+y[nnInd])/2, round(nnDist, 2), col=col, pos=4)

# Calculate NND:
NND = mean(nnDist)




# looping through each file:

# specify directory containing CSV tables:
fDir = "/Users/ebinnicker/GEOG312/"

# list CSV table files names:
fNames = list.files(fDir, pattern=".csv")
fPaths = paste0(fDir, fNames)

# set variable NND as a vector:
NND = vector()

# loop through each input table:
for (i in 1:length(fPaths)){ 
  
  # read in CSV table:
  tab = read.csv(fPaths[i], header=T)
  
  # assign table columns variables:
  x = tab$X
  y = tab$Y
  site = as.vector(tab$Site)
  
  # set variables as vectors:
  nnInd = vector()
  nnDist = vector()
  
  # for each point within the table, calculate the nearest neighbor
  # and the distance to the nearest neighbor: 
  for (j in 1:length(site)){
    
    # calc distance from A to all points:
    dist = sqrt((x[j]-x)^2 + (y[j]-y)^2)
    
    # take the index of the nearest NEIGHBOR:
    nn = order(dist)[2]
    
    # fill in nearest neighbor index vector:
    nnInd[j] = nn
    
    # take the distance to the nearest neighbor:
    nnDist[j] = dist[nn]
    
  }
  
  # plot the nearest neighbors:
  col = rainbow(length(site), v=0.8)
  plot(x, y, type="n")
  text(x, y, site, col=col)
  segments(x, y, x[nnInd], y[nnInd], col=col)
  text((x+x[nnInd])/2, (y+y[nnInd])/2, round(nnDist, 2), col=col, pos=4)
  
  # Calculate NND:
  NND[i] = mean(nnDist)
  
}

# print the NND of each table:
print(NND)
