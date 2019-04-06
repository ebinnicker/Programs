#define samples:
a = c(2,5,3,8,4)
b = c(3,7,1,4,1)
c = c(10,11,5,15,12)

#put samples into table
combined=data.frame(cbind(a,b,c))
print(combined)
summary(combined)

?stack
stacked = stack(combined)
print(stacked)

anova = aov(values ~ ind, data=stacked)
print(anova)

summary(anova)

