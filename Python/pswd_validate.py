def validate(password):
    ''' 
	Type Contract:(str)> str
	
	Checks whether the string s fits the 
        criteria for a valid password.
		
	Example:
	F1#
	> not valid
	ABd1234@1 
	> valid
    ''' 
    a = False
    b = False
    c = False
    d = False
    e = True
    f = False
    g = True
   
   
    #for statement takes each letter of password and determines what type of character it is
    for letter in password:
        if letter.isupper():
            a = True
        elif letter.islower():
            b = True
        elif letter.isdigit():
            c = True
        elif letter == '$' or letter=='#' or letter == '@':
            d = True
        else: 
            e = False
        
    if (len(password) >= 6) and (len(password) <= 12):
        f = True
    else:
        g = False

    #if each type of character is present and the lenght is accpetable, then it is a valid password
    if (a == True) and (b == True) and (c == True) and (d == True) and (f == True):
        print("valid")
    else:
        print("not valid")

def main():
    ''' The program driver. '''

    cmd = ' '
    
    # process the user commands
    cmd = input('> ')
    while  cmd != 'quit':
        password = cmd 
        validate(password)
        cmd = input('> ')


main()
