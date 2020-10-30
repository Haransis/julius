#include <stdio.h>
#include <julius.h>

#define TO_CIPHER "Hello world !"
#define SHIFT 2

int main() {
    char * cipher;
    char * decipher;

    printf("\n*****Encrypting %s*****\n", TO_CIPHER);
    cipher = encrypt(TO_CIPHER, SHIFT);
    printf("Result is %s\n\n", cipher);

    printf("*****Decrypting %s****\n", cipher);
    decipher = decrypt(cipher, SHIFT);
    printf("Result is %s\n\n", decipher);
    
    return 0;
}