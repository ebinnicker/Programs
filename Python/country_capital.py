import csv
import random


#this portion of the code reads teh Country_capital.csv file and creates a list of capitals and list of countries
file = open('Country_capital.csv')
rows = csv.DictReader(file)
capital = []
country = []
for r in rows:
    ca = r['Capital city']
    capital.append(ca)
    co = r['Country']
    country.append(co)

def rd():
    #this function gives a random country for the user to enter the capital. The function also keeps score of how many the user gets correct
    
    score = 0
    rnd = 1
    while rnd <=10:
        print()
        print("ROUND", rnd)
        rnd +=1    
        question = random.choice(country)
        i = country.index(question)
        answer = capital[i]
        user = input("Enter the capital of "+ question + ": ")
        if answer == user:
            print('CORRECT')
            score +=1
        else:
            print('INCORRECT')
            print("Correct Answer: " + answer)
    return score
def main():
    #This fuction is the main driver of the program and prints the introduction and the closing statement of the users score
    
    print("*********************************")    
    print("Welcome to GUESS THAT CAPITAL!!")
    print("NOTE: Answers are case sensitive")
    print("*********************************")
    score = rd()
    print()
    print("You got" , score, "out of 10")
    
main()

