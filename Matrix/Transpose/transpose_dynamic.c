#include <stdio.h>
int main() {
    int i=0, j=0, rows, cols;
    printf("Enter rows and columns: ");
    scanf("%d %d", &rows, &cols);
    int **a;
    a=(int **) malloc(rows*sizeof(int *));
    for(i=0;i<rows;i++)
    {
     a[i]=(int *) malloc(cols*sizeof(int));
    }
    printf("Enter the elements of matrix\n");
    for (i = 0; i < rows; i++)
    {
      for(j = 0; j < cols; j++)
      {
        printf("Enter data for row: %d col: %d", i, j);
        scanf("%d", (*(a+i)+j));
      }
    }
    int **transpose_a;
    transpose_a=(int **) malloc(cols*sizeof(int *));
    for(i=0;i<cols;i++)
    {
     a[i]=(int *) malloc(rows*sizeof(int));
    }

    for (i = 0; i < rows; ++i)
        for (j = 0; j < cols; ++j) {
            *(*(transpose_a+j)+i)= *(*(a+i)+j);
        }
    printf("\nTranspose of the matrix:\n");
    for (i = 0; i < cols; ++i)
        for (j = 0; j < rows; ++j) {
            printf("%d  ", *(*(transpose_a+j)+i));
            if (j == r - 1)
                printf("\n");
        }
    return 0;
}
