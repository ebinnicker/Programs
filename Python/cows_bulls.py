import random

def welcome():
    # prints the welcome portion of the program
    
    print('-----------------------------')
    print( '| Welcome to Cows and Bulls |')
    print( '-----------------------------')
    print()


def main():
    # generates a random number that does not contain a repeated digit
    # user then guesses the number after being given if there is a bull or cow
    # bull suggests a number is correct but in the wrong position
    # cow suggests a number is correct and in the corrrect position
    # how many guesses it took is then show in the output
    
    welcome()
    
    number = ''
    n1 = random.randint(0,9)
    number = number + str(n1)
    
    n2 = random.randint(0,9)
    while n1 == n2:
        n2 = random.randint(0,9)
    number= number + str(n2)
    
    n3 = random.randint(0,9)
    while (n3 == n1) or (n3 == n2):
        n3 = random.randint(0,9)
    number = number + str(n3)
    
    count = 1
    guess = input("Guess #%d: "%(count))
    
    while guess != number:
        cow = 0
        bull = 0        
        if guess[0] == number[0]:
            cow  = cow + 1
        if guess[1] == number[1]:
            cow = cow + 1
        if guess[2] == number[2]:
            cow = cow + 1
        if (guess[0] == number[1]) or (guess[0] == number[2]):
            bull = bull + 1
        if (guess[1] == number[0]) or (guess[1]== number[2]):
            bull = bull + 1
        if (guess[2] == number[0]) or (guess[2] == number[1]):
            bull = bull + 1
        count = count + 1
        print(cow ,"cows,",bull,"bulls")
        print()
          
        guess = input("Guess #%d: "%(count))
    
    if guess == number: 
        print("3 cows, 0 bulls")
        print()
        print("You got it!")
        print("It took you %d guesses to guess the secret number %s." %(count,number))
        
 
main()
    
    
