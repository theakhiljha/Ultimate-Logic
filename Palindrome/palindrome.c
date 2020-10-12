#include<stdio.h>
int palindrome(int num)
{
    int temp, rem, sum=0;
    temp = num;
    while(num!=0)
    {
        rem = num%10;
        sum = sum*10 + rem;
        num /= 10;
    }
    if (sum == temp)
     return 0;
    else 
    return 1;
}
 int main()
 {
    int n;
    printf("Enter the number::");
    scanf("%d", &n);
    if(palindrome(n)==0)
    printf("%d is a palindrome::\n", n);
    else
        printf("%d is not a palindrome::\n", n);
 return 0;
}