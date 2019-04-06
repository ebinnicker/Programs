user = input("Enter a string of positive integers seperated by spaces: ")
print()

num = user.split()

t = 0
while t <len(num):
    num[t] = int(num[t])
    t+= 1
    
for n in num:
    print(n*'*')