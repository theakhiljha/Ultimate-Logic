#include <stdio.h>

void insertion_sort(int A[],int n)
{
	int i,j,x;
	for(i=1;i<n;i++)
	{
		x=A[i];
		j=i-1;
		while(j>-1 && A[j]>x)
		{
			
			A[j+1]=A[j];
			j--;
		}
		A[j+1]=x;
	}
}

int main()
{
	int A[]={65,6,33,4,9,56,1,-3};
	int n=8;
	printf("Before Sorting: \n");
	for(int k=0;k<n;k++)
	{
		printf("%d\t",A[k]);
	}
	insertion_sort(A,n);
	printf("\nAfter Sorting: \n");
	for(int j=0;j<n;j++)
	{
		printf("%d\t",A[j]);
	}
	return 0;
}
