using System;  
class Test { 
    static int factorial(int n) 
    { 
        if (n == 0) 
            return 1; 
        return n * factorial(n - 1); 
    } 
    public static void Main() 
    { 
        int num = 5; 
        Console.WriteLine("Factorial of "
                          + num + " is " + factorial(5)); 
    } 
} 
