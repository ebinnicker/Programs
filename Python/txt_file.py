#for loop here counts how many characters based on the length of each line, how many words by splitting the list by a space
#and counts how many sentences based on how many periods, question marks, and exclamation points appear in each line. The sum of each quantity in each line
#is displayed in the output.



file_name = input("Enter a filename: ")
# gettysburg.txt    OR      five-letter-words.txt
input_file = open(file_name, 'r')

lines = input_file.readlines()
characters = 0
sentences = 0
words = []

for line in lines:
    characters = len(line) + characters
    words += line.strip().split()
    if '.' in line:
        sentences = sentences + 1
    if '!' in line:
        sentences = sentences + 1
    if '?' in line:
        sentences = sentences + 1

print()
print("Characters:", characters)
print("Sentences:", sentences)
print("Words:", len(words))
    

input_file.close()
