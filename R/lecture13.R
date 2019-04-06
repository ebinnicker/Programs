grass_class = read.csv("C:/Users/ebinnicker/Documents/Classes/Spring 2019/GEOG 312/Assignments/03/class_grass.csv",header = TRUE)
lot_class = read.csv("C:/Users/ebinnicker/Documents/Classes/Spring 2019/GEOG 312/Assignments/03/class_lot19.csv",header = TRUE)
sidewalk_class = read.csv("C:/Users/ebinnicker/Documents/Classes/Spring 2019/GEOG 312/Assignments/03/class_sidewalk.csv",header = TRUE)




dirPath = "/Users/ebinnicker/Documents/Classes/Spring 2019/GEOG 312/Assignments/03"
fName = list.files(dirPath, ".csv")
fPath = paste0(dirPath, "/", fName)

tab = read.csv(fPath[1], header=T)

tab = tab[order(tab$group),]

z.test <- function(mnS,mnP, sdS, nS, nP){
  Z = (mnS-mnP)/((sdS/sqrt(nS))*(sqrt((nP-nS)/nP-1)))
  return(Z)
}


head(tab)

boxplot(tab$temp_C)

length(unique(tab$group))

bp = boxplot(tab$temp_C~tab$group,
        ylab="Temperature(C)",
        col=rainbow(length(unique(tab$group))),
        las=2)

#plots a linear line
?abline
abline(h=mean(tab$temp_C),
       col=2,
       lty=2)

#Z-SCORE FOR EACH GROUP
#define unique group IDs:
groupIDs = unique(tab$group)

#define population variable P
P = tab$temp_C

#for every group:
j=1

z.score = vector()
for (j in 1:length(groupIDs)){
  #set row index equal to k:
  k = which(tab$group == groupIDs[j])
  #define group sample:
  S = tab$temp_C[k]

  z.score[j] = z.test(mnS=mean(S),mnP=mean(P), sdS=sd(S), nS=length(S), nP=length(P))
  
 }

#print Z-score vector
print(z.score)

cbind(groupIDs, z.score)

#plots text on scatter plot
text(x=c(1:length(groupIDs)), 
     y=bp$stats[1,]-0.5,
     label=round(z.score,1)
