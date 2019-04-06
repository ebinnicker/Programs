# A program to play Blackjack Dice. 

import random

def roll_die():
    return random.randint(1, 11)

def player():
    ''' 
        Implements what happens on player's turn. 
        Returns total and blackjack, which represents
        the player's total score and whether the
        player hit Blackjack, respectively.
    '''
    
    blackjack = False
    total = 0
    
    print('************ YOUR TURN ************')

    r1 = roll_die()
    r2 = roll_die()
    print("Roll: %d %d" %(r1,r2))
    total = r1 + r2
    print("Total:", total)
    
    #if-else statement here determines if blackjack is reached first round it you win and continues
    #if not, then it continues to allowing the user to roll until they decide to stay or the total is greater-than or equal-to 21
    if total == 21:
        blackjack == True
        print()
        print("Blackjack!")
    elif total > 21:
        print()
    else:
        udec = input("((s))tay or ((r))oll? ")
        print()
        while udec == 'r' and total <21:
            roll = roll_die()
            print("Roll:", roll)
            total = total + roll
            print("Total:", total)
            if total < 21:
                udec = input("((s))tay or ((r))oll? ")
            print()
        
    return total, blackjack

def dealer():
    ''' 
        Implements what happens on the dealer's turn. 
        Returns total which represents the dealer's
        total score.
    '''
   
    print("********** DEALER'S TURN **********")
  
    total = 0
    cont = ''
    r1 = roll_die()
    r2 = roll_die()
    print("Roll: %d %d" %(r1,r2))
    total = r1 + r2
    print("Total:", total)
    
    #this while loop will continue to roll for the dealer until the total is greater than 16 and the user presses 'enter' to continue through the turn.
    while total <= 16 and cont == '':
        cont = input("Press <enter> to continue...")
        roll = roll_die()
        total = total + roll
        print()
        print("Roll:", roll)
        print("Total:", total)
    return total

def main():
    ''' 
        The main driver of the program. Connects the 
        player() and dealer() functions together to
        play Blackjack Dice.
    '''
    
    # The user (or player) plays first.
    player_total, blackjack = player()
    #if-elif-else statement here is for the condition that the user gets blackjack, or the user busts and does not need the dealers turn to determine a winner.
    #The else portion is for the dealer's turn for determining winners based on each players total
    if blackjack == True:
        print("Blackjack!")
        print()
        print('*'*12 + ' GAMEOVER '+'*'*12)
        print("You win!")
    elif player_total > 21:
        print ("Bust!")
        print()
        print('*'*12 + ' GAMEOVER ' + '*'*12)
        print("Dealer wins!") 
    else:
        dealer_total = dealer()
        if dealer_total > 21:
            print()
            print("Bust!")
            print()
            print('*'*12 + ' GAMEOVER ' + '*'*12)
            print("You win!")
        elif dealer_total == 21:
            print()
            print('*'*12 + ' GAMEOVER ' + '*'*12)
            print("Dealer wins")
        elif dealer_total == player_total:
            print()
            print('*'*12 + ' GAMEOVER ' + '*'*12)
            print("Dealer wins")            
        elif dealer_total > player_total:
            print()
            print('*'*12 + ' GAMEOVER ' + '*'*12)
            print("Dealer wins")
        elif player_total > dealer_total:
            print()
            print('*'*12 + ' GAMEOVER ' + '*'*12)
            print("You win!")        

    
main()