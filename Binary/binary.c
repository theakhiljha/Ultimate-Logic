//The code takes a number in decimal as input and returns the number in binary

#include<stdio.h>

int main()
{
    int n;
    printf("Enter a number in decimal: ");
    scanf("%d", &n);

    long long int bin=0;
    int position=1;     //This will allow us to keep count of the position
    while(n!=0)
    {
        int temp=n%2;
        bin+=temp*position;
        n/=2;
        position*=10;
    }
    printf("The number in binary is: %lld\n", bin);
    return 0;
}