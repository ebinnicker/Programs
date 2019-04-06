import random

def roll_dice():
    #Returns the rolls of two dice
    dice = []
    for die in range(2):
        dice += [random.randint(1,6)]
    return dice

def draw_die(value):
    #the draw_die draws the dice line by line into a list to be printed in a later function
    
    border = '+-------+'
    empty = '|       |'
    one_left = '| *     |'
    one_mid = '|   *   |'
    one_right = '|     * |'
    left_right = '| *   * |'
    
    pip1 = [border, empty, one_mid, empty, border]
    pip2 = [border, one_left, empty, one_right, border]
    pip3 = [border, one_left, one_mid, one_right, border]
    pip4 = [border, left_right, empty, left_right, border]
    pip5 = [border, left_right, one_mid, left_right, border]
    pip6 = [border, left_right, left_right, left_right, border]
    die = ['', pip1, pip2, pip3, pip4, pip5, pip6]
    return die[value]

def show_dice(dice):
    #show_dice function takes the drawn dice and prints them in the output correctly
    
    value1 = dice[0]
    value2 = dice[1]
    die1 = draw_die(value1)
    die2 = draw_die(value2)
    print(die1[0] +'   '+ die2[0])
    print(die1[1] +'   '+ die2[1])
    print(die1[2] +'   '+ die2[2])
    print(die1[3] +'   '+ die2[3])
    print(die1[4] +'   '+ die2[4])
    
    
    
def main():
    #the main function is the logic of the game and determines if the player wins or loses based on the sum of the dice
    #On the first roll, if the sum is 7 or 11 the user wins and if the sum is 2, 3, or 12 the user loses. Otherwise, the sum
    #becomes the point to try to roll. The player continues to roll to try to get the point. If the user rolls a 7 they lose and the game ends.
    
    print('Craps: A Popular Dice Game')
    end = False
    input('Press <Enter> to roll the dice.')
    dice  = roll_dice()
    show_dice(dice)
    point = sum(dice)
    point_list = [point]
    print('You rolled a %d on your first roll.' %(point))
    if point == 7 or point == 11:
        print("You win!")
    elif point==2 or point==3 or point==12:
        print("You lose!")
        end == True
    else:
        print()
        print("That's your point. Roll it again before you roll 7 and lose!")
        print()
        input("Press <Enter> to roll the dice.")
        dice = roll_dice()
        show_dice(dice)
        point = sum(dice)
        print('You rolled a %d' %(point)) 
        while end == False:                      
            if point==point_list[0]:
                print("You win!")
                end = True
            elif point==7:
                print("You lose!")
                end = True
            else:
                print()
                input("Press <Enter> to roll the dice.")
                dice = roll_dice()
                show_dice(dice)
                point = sum(dice)
                print("You rolled a %d" %(point))
                end = False

    
main()