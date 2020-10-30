#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100

void longestCommonSubsequence(char *x,char *y,char *z);

int main(void) {
	char x[SIZE], y[SIZE], z[SIZE];

	printf("Enter 2 strings of characters\n");
	scanf("%s%s", x, y);

	longestCommonSubsequence(x,y,z);

	printf("The longest common subsequence is :\n%s", z);

	return 0;
}

void longestCommonSubsequence(char x[SIZE],char y[SIZE],char z[SIZE]){
	int i,n,m,j,k;
	int T[100][100] = {{0}};

	m = strlen(x);
	n = strlen(y);

	for(i = 1; i <= m; i++){
		for(j = 1; j <= n; j++){
			if(x[i-1] == y[j-1])
				T[i][j] = T[i-1][j-1] + 1;
			else {
				if(T[i-1][j] > T[i][j-1])
					T[i][j] = T[i-1][j];
				else
					T[i][j] = T[i][j-1];
			}
		}
	}

	i = m;
	j = n;
	k = 0;

	while(i > 0 && j > 0){
		if(x[i-1] == y[j-1]) {
			z[k++] = x[i-1];
			i--;
			j--;
		}
		else if(T[i-1][j] > T[i][j-1])
			i--;
		else
			j--;
	}

	printf("Longest Common Subsequence Matrix:\n");
	for(i = 0;i < m; i++){
		for(j = 0; j < n; j++)
			 printf("%d\t",T[i][j]);
		printf("\n");
	}

}
