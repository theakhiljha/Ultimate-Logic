# this code checks if a triangle has an angle of 90 degrees (i.e. if the triangle is a right-angled triangle)
print("Please input the three sides of the right-angled triangle. Note that a and b are the shorter sides, while c is the longest side (also known as the hypotenuse).")

a = float(input("Side a: "))
b = float(input("Side b: "))
c = float(input("Side c: "))

def Right_Angled_Triangle(a, b, c):
    if (a**2 + b**2 == c**2):
        return("This is a right-angled triangle!")
    else:
        return("This is not a right-angled triangle!")

print(Right_Angled_Triangle(a, b, c))
