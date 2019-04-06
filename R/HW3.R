grass_sample = read.csv("C:/Users/ebinnicker/Documents/Classes/Spring 2019/GEOG 312/Assignments/03/sample_grass.csv",header = TRUE)
lot_sample = read.csv("C:/Users/ebinnicker/Documents/Classes/Spring 2019/GEOG 312/Assignments/03/sample_lot.csv",header = TRUE)
sidewalk_sample = read.csv("C:/Users/ebinnicker/Documents/Classes/Spring 2019/GEOG 312/Assignments/03/sample_sidewalk.csv",header = TRUE)

print(grass_sample)
print(lot_sample)
print(sidewalk_sample)

grass_S = (grass_sample[,2])
sampleMean_grass = mean(grass_S)
print(sampleMean_grass)

lot_S = (lot_sample[,2])
sampleMean_lot = mean(lot_S)
print(sampleMean_lot)

sidewalk_S = (sidewalk_sample[,2])
sampleMean_sidewalk = mean(sidewalk_S)
print(sampleMean_sidewalk)



grass_class = read.csv("C:/Users/ebinnicker/Documents/Classes/Spring 2019/GEOG 312/Assignments/03/class_grass.csv",header = TRUE)
lot_class = read.csv("C:/Users/ebinnicker/Documents/Classes/Spring 2019/GEOG 312/Assignments/03/class_lot19.csv",header = TRUE)
sidewalk_class = read.csv("C:/Users/ebinnicker/Documents/Classes/Spring 2019/GEOG 312/Assignments/03/class_sidewalk.csv",header = TRUE)

grass_pop = (grass_class[,4])
popMean_grass = mean(grass_pop)
print(popMean_grass)

lot_pop = (lot_class[,4])
popMean_lot = mean(lot_pop)
print(popMean_lot)

sidewalk_pop = (sidewalk_class[,4])
popMean_sidewalk = mean(sidewalk_pop)
print(popMean_sidewalk)

sd_grass = sd(grass_S)
print(sd_grass)
sd_lot= sd(lot_S)
print(sd_lot)
sd_sidewalk = sd(sidewalk_S)
print(sd_sidewalk)

t_grass = ((sampleMean_grass - popMean_grass)/(sd_grass/(sqrt(14))))
print(t_grass)
t_lot = ((sampleMean_lot - popMean_lot)/(sd_lot/sqrt(14)))
print(t_lot)
t_sidewalk = ((sampleMean_sidewalk - popMean_sidewalk)/(sd_sidewalk/sqrt(14)))
print(t_sidewalk)






table1= read.csv("C:/Users/ebinnicker/Documents/Classes/Spring 2019/GEOG 312/Assignments/03/table1.csv",header = TRUE)

hist(table1,
        main = "Sample and Population Comparison",
        xlab = "Statistics",
        col = c("red","green","blue")
        )
