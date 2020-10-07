#include <stdio.h>

int main()
{
    int n, a, b, d, e, c;
    printf("Enter a three digit no. : ");
    scanf("%d", &n);
    a = n % 100;
    b = a % 10;  // last digit
    d = a / 10;  // second digit
    e = n / 100; //third digit
    c = 100*b + 10*d + e ;
    printf("The reverse is : %d\n", c);
    return 0;
}
