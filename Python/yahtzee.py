# Computes the probability of the various hands in Yahtzee.

import random

def roll_dice():
    #Returns 5 randomly rolled dice.
    dice = []
    for i in range(5):
        dice += [random.randint(1,6)]
    return dice

 
def three_of_a_kind(dice):
    #Returns True if the dice are three of a kind.
    
    if dice [0] == dice[1] == dice[2]:
        return True
    elif dice[1] == dice[2] == dice[3]:
        return True
    elif dice[2] == dice[3] == dice[4]:
        return True
    
def four_of_a_kind(dice):
    #Returns True if the dice are four of a kind
    
    if dice[0] == dice[1] == dice[2] == dice[3]:
        return True
    elif dice[1] == dice[2] == dice[3] == dice[4]:
        return True
    
def full_house(dice):
    #Returns True if the dice is a full house (3 of one kind and a pair of another kind)
    
    if dice[0] == dice[1] == dice[2] and dice[3] == dice[4]:
        return True
    elif dice[0] == dice[1] and dice[2] == dice[3] == dice[4]:
        return True 

     
def small_straight(dice):
    #Returns True if the dice is a small straight (four sequential dice)
    
    if (dice[0] + 1) == dice[1] and (dice[0]+2) == dice[2] and (dice[0]+3) == dice[3]:
        return True
    elif dice[4] == (dice[3] + 1) and dice[4] == (dice[2]+2) and dice[4] == (dice[1]+3):
        return True
         
def large_straight(dice):
    #Returns True if the dice is a large straight (five sequential dice)
    
    if dice == [1,2,3,4,5]:
        return True
    elif dice == [2,3,4,5,6]:
        return True
 
def yahtzee(dice):
    #Returns True if the dice is a yahtzee (five of a kind)
    
    ''' Returns True or False if the dice represent Yahtzee'''
    if dice[0] == dice[1] == dice[2] == dice[3] == dice[4]:
        return True


def main():
    #main driver of the program. Rolls the dice and calls the other functions to determine if any of the 7 hands occur. 
    #Also determines the percentage each hand occured based on the number of times the the dice was rolled (user determined)
    user_input = input('> ')
    while user_input != 'quit':
        dice_rolls = int(user_input)
        yahtzee_count = 0
        four_of_a_kind_count = 0
        three_of_a_kind_count = 0
        two_of_a_kind_count = 0
        full_house_count = 0
        large_straight_count = 0
        small_straight_count = 0
        misc_count = 0
    
        for i in range(dice_rolls):
            dice = roll_dice()
            dice.sort()
            if yahtzee(dice):
                yahtzee_count += 1
            elif four_of_a_kind(dice):
                four_of_a_kind_count += 1
            elif large_straight(dice):
                large_straight_count += 1
            elif small_straight(dice):
                small_straight_count += 1
            elif full_house(dice):
                full_house_count += 1
            elif three_of_a_kind(dice):
                three_of_a_kind_count += 1
            else:
                misc_count += 1
        
        yah_per = (yahtzee_count/dice_rolls)*100.0
        four_per = (four_of_a_kind_count/dice_rolls)*100.0
        large_per = (large_straight_count/dice_rolls)*100.0
        full_per = (full_house_count/dice_rolls)*100.0
        small_per = (small_straight_count/dice_rolls)*100.0
        three_per = (three_of_a_kind_count/dice_rolls)*100
        mis_per = (misc_count/dice_rolls)*100     
        print('yahtzee:', yahtzee_count, '(%.1f %%)' %(yah_per))
        print('four of a kind:', four_of_a_kind_count, '(%.1f %%)' %(four_per))
        print('large straight:', large_straight_count, '(%.1f %%)' %(large_per))
        print('full house:', full_house_count, '(%.1f %%)' %(full_per))
        print('small straight:', small_straight_count, '(%.1f %%)' %(small_per))
        print('three of a kind:', three_of_a_kind_count, '(%.1f %%)' %(three_per))
        print('misc:', misc_count, '(%.1f %%)' %(mis_per))
        user_input = input('> ')

main()