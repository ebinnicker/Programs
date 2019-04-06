def translate(word):
    #this function takes a string and translates it depending on each character within the string
    #if a vowel is detected it is not edited. If it is a consonant it repeats the letter while seperating it with an 'o'
    
    modified_word = ''
    i = 0
    while i<len(word):
        if word[i] in 'aeiou ':
            modified_word = modified_word + word[i]
        else:
            modified_word = modified_word + word[i] + "o" + word[i]
        i += 1 
    print("Translated Version:", modified_word)
    
def main():
    #this function is the driver of the program and allows the user to input their word and is then translated 
    
    word = input("Enter your input: ")
    print (word)
    translate(word) 
    
main()