n = input("Enter the name:: ")
reverseString = [] 
i = len(n)
while i > 0:
    reverseString += n[ i - 1 ] 
    i = i - 1
reverseString = ''.join(reverseString)
print("ReversedString::", reverseString)    
