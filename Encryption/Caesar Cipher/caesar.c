#include <stdio.h>
#include <ctype.h>


int main()
{
    char message[100];
    char ch;
    int n, i, size;

    
    printf("Enter message to be encrypted: ");
    fgets(message, sizeof(message), stdin);
    getchar();
    printf("Enter shift amount (1-25): ");
    scanf(" %d", &n);
    
    
    for(i = 0; message[i] != '\0'; i++)
    {
        if( isupper(message[i]) )
        {
            ch = message[i];
            message[i] = ((ch-'A') + n)%26 + 'A';
        }
        if( islower(message[i]) )
        {
            ch = message[i];
            message[i] = ((ch-'a') + n)%26 + 'a';
        }
    }

    printf("Encrypted message: %s\n", message);
}
