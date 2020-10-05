#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define SIZE 50
int main(void) {
	char s[SIZE];
	setbuf(stdout, NULL);
	return EXIT_SUCCESS;
}

int characterCount(char *a){
	if(*a == '\0'){
		return 0;
	}
	else{
		return 1 + characterCount(a+1);
	}
}

int RussianProductMethod(int x, int y){
	if(x == 0){
		return 0;
	}
	else{
		return ((x%2) * y) + RussianProductMethod(x/2, y*2);
	}
}
void toBinaryString(int x){
	if(x/2 == 0){
		printf("%d", x);
	}
	else{
		toBinaryString(x/2);
		printf("%d", x/2);
	}
}
void TowerOfHanoi(int n, char source, char auxillary, char target){
	if(n == 1){
		printf("Shift %d from %c to %c\n", n, source, target);
	}
	else{
		TowerOfHanoi(n-1, source, target, auxillary);
		printf("Shift %d from %c to %c\n", n, source, target);
		TowerOfHanoi(n-1, auxillary, source, target);
	}
}
int CountTowerOfHanoiSteps(int n, char source, char auxillary, char target){
	int x,y;
	if(n == 1){
		return 1;
	}
	else{
		x = CountTowerOfHanoiSteps(n-1, source, target, auxillary);
		y = CountTowerOfHanoiSteps(n-1, auxillary, source, target);
		return (1 + x + y);
	}
}
int countSumOfOddNumbersInArray(int *a, int n){

	if(n == 0){
		return 0;
	}
	else{
		return ((a[n-1]%2) * a[n-1]) + countSumOfOddNumbersInArray(a+1, n-1);
	}
}
int isPrimeNumber(int n, int d){
	if(n < 2){
		return 0; //Not Prime
	}
	else if(d == 1){
		return 1; //Prime
	}
	else{
		if(n%d == 0){
			return 0; //Not Prime
		}
		else{
			return isPrimeNumber(n, d-1); // isPrimeNumber recursive call
		}
	}

}
int largestElement(int *a, int n){
	int x,y;
	if(n == 0){
		return 0;
	}
	else if(n == 1){
		return a[0];
	}
	else{
		x = a[n-1];
		y = largestElement(a, n-1);
		return (x > y)? x : y;
	}
}
void recursiceSplitMinAndMaxSearch(int *a, int l, int h, int *xmin, int *xmax){
	if(l == h){
		*xmin = a[l];
		*xmax = a[h];
	}
	else if(l == h-1){
		if(a[l] > a[h]){
			*xmin = a[h];
			*xmax = a[l];
		}
		else{
			*xmin = a[l];
			*xmax = a[h];
		}
	}
	else{
		int x,y,p,q;
		int m = (l+h)/2;
		recursiceSplitMinAndMaxSearch(a,l,m,&x,&p);
		recursiceSplitMinAndMaxSearch(a,m+1,h,&y,&q);
		*xmin = (x > y)? y : x;
		*xmax = (p > q)? p : q;
	}
}

int fibonacciSeries(int n){

	if(n == 0 || n == 1){
		return n;
	}
	else{
		return fibonacciSeries(n-1) + fibonacciSeries(n-2);
	}
}
int check(int *a, int r){
	int i;
	for(i = 0; i < r; i++){
		if(a[i] == a[r] || abs(r-i) == abs(a[r] - a[i])){
			return 0;
		}
	}
	return 1;
}
void printSolution(int *a, int n){
	int i;
	for(i = 0; i < n; i++){
	printf("%d\t",a[i]);
	}
	printf("\n");
}

void NQueens(int *a, int n, int r){
	int i;
	for(i = 0; i < n; i++){
		a[r] = i;
		if(check(a,r)){
			if(r+1 < n){
				NQueens(a, n,r+1);
			}
			else{
				printSolution(a,n);
			}
		}
	}
}

char* PreToPostString(char *pre, char *post){
	if(isalpha(*pre) || isdigit(*pre)){
		strncat(post, pre, 1);
		return pre;
	}
	else{
		char *p = PreToPostString(pre + 1, post);
		p = PreToPostString(p + 1, post);
		strncat(post, pre, 1);
		return p;
	}
}
char* PreToInfixString(char *pre, char *post){
	char *p;
	if(isalpha(*pre) || isdigit(*pre)){
		strncat(post, pre, 1);
		return pre;
	}
	else{
		strcat(post, "(");
		p = PreToInfixString(pre + 1, post);
		strncat(post, pre, 1);
		p = PreToInfixString(p + 1, post);
		strcat(post, ")");
		return p;
	}
}
