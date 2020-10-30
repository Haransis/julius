#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <julius.h>

#define TO_CIPHER "Hello world !"
#define SHIFT 2

int main() {
    char * msg = malloc(strlen(TO_CIPHER)+1);
    strcpy(msg, TO_CIPHER);

    printf("\n*****Encrypting %s*****\n", TO_CIPHER);
    encrypt(msg, SHIFT);
    printf("Result is %s\n\n", msg);

    printf("*****Decrypting %s****\n", msg);
    decrypt(msg, SHIFT);
    printf("Result is %s\n\n", msg);
    
    free(msg);
    return 0;
}