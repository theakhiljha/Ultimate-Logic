#include <stdio.h>
int i = 0, j = 0;
void add(int a[3][3], int b[3][3], int c[3][3], int r, int c, int i, int j){
  if (i < r){
    if(j < c) {
        c[i][j] = a[i][j] + b[i][j];
      }
      add(a[3][3], b[3][3], c[3][3], r, c, i++, j++);
    }
    else
      {
        for (i = 0; i < r; ++i)
            for (j = 0; j < c; ++j) {
                printf("%d   ", c[i][j]);
            }
      }

}
int main() {
    int r, c, a[100][100], b[100][100], sum[100][100], i, j;
    printf("Enter the number of rows (between 1 and 100): ");
    scanf("%d", &r);
    printf("Enter the number of columns (between 1 and 100): ");
    scanf("%d", &c);

    printf("\nEnter elements of 1st matrix:\n");
    for (i = 0; i < r; ++i)
        for (j = 0; j < c; ++j) {
            printf("Enter element a%d%d: ", i + 1, j + 1);
            scanf("%d", &a[i][j]);
        }

    printf("Enter elements of 2nd matrix:\n");
    for (i = 0; i < r; ++i)
        for (j = 0; j < c; ++j) {
            printf("Enter element a%d%d: ", i + 1, j + 1);
            scanf("%d", &b[i][j]);
        }


    // printing the result
    printf("\nSum of two matrices: \n");
    for (i = 0; i < r; ++i)
        for (j = 0; j < c; ++j) {
            printf("%d   ", sum[i][j]);
            if (j == c - 1) {
                printf("\n\n");
            }
        }

    return 0;
}
