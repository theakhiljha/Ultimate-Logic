# Python3 code to demonstrate working of
# Words Frequency in String Shorthands
# Using Counter() + split()
from collections import Counter

# initializing string
test_str = 'AKHIL IS THE BEST!'

# printing original string
print("The original string is : " + str(test_str))

# Words Frequency in String Shorthands
# Using Counter() + split()
res = Counter(test_str.split())

# printing result
print("The words frequency : " + str(dict(res)))
