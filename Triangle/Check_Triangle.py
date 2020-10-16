#-----------------------------CHECK TRIANGLE------------------------------------
# Problem description: Check if the given three numbers form a triangle
# Main code:

a=float(input())
b=float(input())
c=float(input())
def istri(a,b,c):
    if(((a+b)>c) and ((a+c)>b) and ((b+c)>a)):
        return True
    else:
        return False
print (istri(a,b,c))
