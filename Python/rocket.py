

def point(size):
    #function point builds the point of the rocket and the base of the rocket
    #based on size entered by user
    
    i = 0
    while i < (size*2 - 1):
        space = (size *2 -1) 
        a = '/**\\'    
        for i in range(size*2 - 1):
            print((space * ' ') + a)
            a = '/' + a + '\\'
            space = space - 1
        i = i + 1

def middle1 (size): 
    #builds the top half of each core section that points upward. 
    #size based on user input
    
    j = 0
    while j < size:
        deci = size - 1
        b = '/\\'
        for j in range(size):
            print('|'+ (deci*'.') + b + ((deci * '.')*2) + b + (deci * '.')+'|')
            deci = deci - 1
            b = b + '/\\'
        j = j + 1
    

def middle2 (size):
    #builds the bottom half of each core section that points downward
    #size based on user input
    
    k = 0
    while size > k:
        deci = 0
        c = '\\/'
        for k in range(size):  
            print('|' + (deci * '.') + (c*size) + (deci * '.') + (deci * '.') + (c*size) + (deci * '.') + '|') 
            size = size - 1
            deci = deci +1
        k = k + 1
    
def main():
    #main driver of function. Calls previously stated functions to build complete rocket
    #size is based on user input
    
    size = int(input("size: "))
    print()
    point(size)
    print ('+' + ((size*2)* '=*') + '+')
    middle1(size)
    middle2(size)
    print ('+' + ((size*2)* '=*') + '+')
    middle1(size)
    middle2(size)
    print ('+' + ((size*2)* '=*') + '+')
    point(size)
    
main()
