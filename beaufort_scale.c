#include <stdio.h>
int main()
{
    int s;
    printf("Enter wind speed(in knots): ");
    scanf("%d",&s);
    if (s<=1)
        printf("Calm\n");
    else if (s <= 3) 
        printf("Light air\n");
    else if (s <= 27) 
        printf("Breeze\n");
    else if (s <= 47) 
        printf("Gale\n");
    else if (s <= 63) 
        printf("Storm\n");
    else if (s > 63) 
        printf("Hurricane\n");
    
}