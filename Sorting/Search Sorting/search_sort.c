#include<stdio.h>

int ls(int n,int num[],int x)
{
    int i;
    for(i=0;i<n;++i)
    {
        if(num[i]==x)
            break;
    }
    if(i<n)
    {
        printf("Number found at interval %d",i+1);
    }
    else
    {
        printf("Number not found");
    }
    return 0;
}


int main()
{
    int s;
   int i, j, r, temp, num[25];
   printf("Enter range: ");
   scanf("%d",&r);
   printf("Enter %d Numbers: \n", r);
   for(i=0;i<r;i++)
    {
        scanf("%d",&num[i]);
    } 
    
    printf("Element to be searched:  ");
    scanf("%d:",&s);
    ls(r,num,s);
    
   for(i=0;i<r;i++)
   {
      for(j=i+1;j<r;j++)
      {
        if(num[i]>num[j])
         {
            temp=num[i];
            num[i]=num[j];
            num[j]=temp;
         }
      }
   }

   printf("\nSorted: ");
   for(i=0;i<r;i++)
    {
      printf("%d\t",num[i]);
    }
    
}
