tab = read.csv("C:/Users/ebinnicker/Documents/Classes/Spring 2019/GEOG 312/Assignments/04/assignment04_grass.csv",header = TRUE)

#define unique group IDs
groupIDs = unique(grass$group)

#define population mean and output
pop_mean = mean(tab$temp_C)
cat("\nPop Mean:", pop_mean)

ssw = 0
for (j in 1:length(groupIDs)){
  
  # set row index equal to k
  k = which(tab$group == groupIDs[j])
  
  # define group sample 
  S = tab$temp_C[k]
  cat("\nGroup", j)
  
  #define sample mean and output
  mean = mean(S)
  cat("\nx mean:", mean)
  
  #define sample std dev and output
  sd = sd(S)
  cat("\ns:", sd)
  
  #define sample std dev squared and output
  sd2 = (sd(S))^2
  cat("\nsd:", sd2)
  
  ssw = ssw + (sd2*29)
  ssb = ssb + (30*(mean-mean(tab$temp_C))*(mean-mean(tab$temp_C)))
  
  #define SSW and output
  SSW = 29*sd2
  cat("\nSSW:", SSW)
  
  
}

# SSW output
cat("SSW:", ssw)
# MSW calc and output
msw = ssw /(180-6)
cat("MSW:", msw)
# SSB output
cat("SSB:", ssb)
# MSB calc and output
msb = ssb/5
cat("MSB:", msb)





