#include<stdio.h>

char LUT[26] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 
                3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 
                4, 10};

int main(void){
    char inp[46];
    int val = 0;
    printf("Enter a word: ");
    scanf("%s", inp);
    for(int i=0; inp[i]; i++){
        val += LUT[(inp[i]|0x20)-97];
    }
    printf("Scrabble value: %i\n", val);
}
