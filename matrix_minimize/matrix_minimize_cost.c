/*
Question:
There are n people who need to be assigned to n jobs, one person per job.
The cost of assigning person i to job j is C[i,j]. Find an assignment that
minimizes the total cost.
 Job 0 Job 1 Job 2 Job 3
Person 0 9 2 7 8
Person 1 6 4 3 7
Person 2 5 8 1 8
Person 3 7 6 9 4
Generate their costs and select the cheapest one. */

/*Solution using Brute Force Method */

#include <stdio.h>
int est()
{
    int c[4][4] = 
    {
        {9, 2, 7, 8},
        {6, 4, 3, 7},
        {5, 8, 1, 8},
        {7, 6, 9, 4}
    };
    
     int min = 100; 
     int price = 0;
     for (int i = 0; i < 4; i++)
     {
         price = c[0][i];
         for (int j = 0; j < 4; j++)
         {
         if (j != i)
         {
         price += c[1][j];
         for (int k = 0; k < 4; k++)
            {
             if (k != j && k != i)
                 {
                 price += c[2][k];
                 for (int l = 0; l < 4; l++)
                     {
                     if (l != i && l != j && l != k)
                        {
                            price += c[3][l];
                            printf("%d %d %d %d: %d+%d+%d+%d = %d \n",i, j, k, l, c[0][i], c[1][j], c[2][k], c[3][l], price);
                            if (price < min)
                                {
                                    min = price;
                                }
                             price -= c[3][l];
                        }
                     }
                 price -= c[2][k]; 
                 }
            }
         price -= c[1][j];
         }
     }
     price -= c[0][i];
     }
     printf("\nCheapest Cost: %d", min);
}

int main()
{
    est();
}
