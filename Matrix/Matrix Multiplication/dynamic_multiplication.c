#include <stdio.h>
int main()
{
  int rows, cols, rows2, cols2, i = 0, j = 0, k = 0, sum = 0;
  printf("Enter the number of rows and columns of matrix 1:");
  scanf("%d%d", &rows, &cols);

  printf("Enter number of rows and columns of matrix 2:");
  scanf("%d%d", &rows2, &cols2);

  if (cols != rows2)
    printf("The multiplication isn't possible.\n");
  else
  {
    int **a;
    a=(int **) malloc(rows*sizeof(int *));
    int **b;
    b=(int **) malloc(rows2*sizeof(int *));
    int **c;
    c=(int **) malloc(rows*sizeof(int *));

    for(i=0;i<rows;i++){
     a[i]=(int *) malloc(cols*sizeof(int));
     c[i]=(int *) malloc(cols2*sizeof(int));
   }
   for(i=0;i<rows2;i++){
     b[i]=(int *) malloc(cols2*sizeof(int));
  }

    printf("Enter elements of first matrix\n");
    for (i = 0; i < rows; i++)
    {
      for(j = 0; j < cols; j++)
      {
        printf("Enter data for row: %d col: %d", i, j);
        scanf("%d", (*(a+i)+j));
      }
    }
    printf("Enter elements of second matrix\n");
    for (i = 0; i < rows; i++)
    {
      for(j = 0; j < cols; j++)
      {
        printf("Enter data for row: %d col: %d", i, j);
        scanf("%d", (*(b+i)+j));
      }
    }

    for (i = 0; i < rows; i++) {
      for (j = 0; j < cols2; j++) {
        for (k = 0; k < rows2; k++) {
          sum = sum + *(*(a+i)+k) * *(*(b+k)+j);
        }
          *(*(c+i)+j) = sum;
        sum = 0;
      }
    }

    printf("Product of the matrices:\n");

    for (i = 0; c < rows; i++) {
      for (j = 0; d < cols2; j++)
        printf("%d\t", *(*(c+i)+j));
      printf("\n");
    }
  }

  return 0;
}
