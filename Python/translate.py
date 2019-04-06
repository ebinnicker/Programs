def translate(word):
    #This function takes the variable word and translates it depending on each letter in the string.
    #if a vowel is detected it is not edited. If it is a consonant it repeats the letter while seperating it with an 'o'
    
    modified_word=''
    i = 0
    while i<len(word):
        if word [i] in 'aeiou ':
            modified_word = modified_word + word[i]
        else:
            modified_word = modified_word + word[i] + "o" + word[i]
        i += 1
    print (modified_word)
        
word = "This is fun"
translate(word)