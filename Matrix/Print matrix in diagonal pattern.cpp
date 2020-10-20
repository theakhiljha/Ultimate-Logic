// C++ program to print matrix in diagonal order 
#include <bits/stdc++.h> 
using namespace std; 
const int MAX = 100; 

void printMatrixDiagonal(int mat[MAX][MAX], int n) 
{ 
	// Initialize indexes of element to be printed next 
	int i = 0, j = 0; 

	// Direction is initially from down to up 
	bool isUp = true; 

	// Traverse the matrix till all elements get traversed 
	for (int k = 0; k < n * n;) { 
		// If isUp = true then traverse from downward 
		// to upward 
		if (isUp) { 
			for (; i >= 0 && j < n; j++, i--) { 
				cout << mat[i][j] << " "; 
				k++; 
			} 

			// Set i and j according to direction 
			if (i < 0 && j <= n - 1) 
				i = 0; 
			if (j == n) 
				i = i + 2, j--; 
		} 

		// If isUp = 0 then traverse up to down 
		else { 
			for (; j >= 0 && i < n; i++, j--) { 
				cout << mat[i][j] << " "; 
				k++; 
			} 

			// Set i and j according to direction 
			if (j < 0 && i <= n - 1) 
				j = 0; 
			if (i == n) 
				j = j + 2, i--; 
		} 

		// Revert the isUp to change the direction 
		isUp = !isUp; 
	} 
} 

int main() 
{ 
	int mat[MAX][MAX] = { { 1, 2, 3 }, 
						{ 4, 5, 6 }, 
						{ 7, 8, 9 } }; 

	int n = 3; 
	printMatrixDiagonal(mat, n); 
	return 0; 
} 
