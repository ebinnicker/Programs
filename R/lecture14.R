#Wilcoxon Rank Sum Test
g1 = c(57,62,55,68,75,65,45)
g2 = c(66,72,59,66,67,71,55)

tab = data.frame(g1,g2)

?boxplot
boxplot(tab)

stacked = stack(tab)

# test if samples are drawn from the same populations:
wilcox.test(values~ind, data=stacked, exact=FALSE)





#Kruskal-Wallis Test

g1 = c(57,62,55,68,75,65,45)
g2 = c(66,72,59,66,67,71,55)
g3 = c(33,44,34,55,45,50,58)

tab = data.frame(g1,g2,g3)

boxplot(tab)

kruskal.test(tab)



