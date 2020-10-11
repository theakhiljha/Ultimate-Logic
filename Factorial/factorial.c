#include <stdio.h>
int main()
{
    int n,i,fact=1;
    printf("Enter an integer::");
    scanf("%d",&n);
    if (n<0)
    printf("factorial  doesn't exist for negative numbers!!!!");
    else
    {
        for ( i = 1; i <= n; i++)
        {
            fact *= i;
        }
        printf("factorial of %d =%d", n, fact);
    }
    return 0;
}