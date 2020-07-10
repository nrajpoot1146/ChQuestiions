
# read string from user
inputString = input("Enter a string : ")

# iterate each character from string

print("new string: ", end = "")
for x in inputString:
    if (not x.isalpha()): # if character is not a alphabet
        print("*", end = "") # print *
    else:
        print(x, end = "") # print character