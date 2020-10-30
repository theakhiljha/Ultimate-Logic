#include <stdio.h>
#include <stdlib.h>

int mult(int a, int b);

int main(){

	int a = 2;
	int b = -7;
	int answer = mult(a, b);

	printf("%d x %d = %d \n", a, b, answer);
	return 0;
}
int mult(int a, int b){

	if(a == 0 || b ==0)
		return 0;

	if(a == 1)
		return b;

	if(b == 1)
		return a;

	if(a == -1)
		return -b;

	if(b == -1)
		return -a;

	if((a >0 && b > 0)  || a < 0 && b < 0)
		return mult(abs(a), abs(b)-1) + abs(a);
	else if(a < 0 && b > 0)
		return mult(a, b-1) + a;
	else
		return mult(a-1, b) + b;
}
