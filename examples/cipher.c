#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cipher.h>
#include <julius.h>

#define MAX_INPUT_SIZE 100

int main(int argc, char *argv []){
    char *msg = malloc(MAX_INPUT_SIZE);
    int shift;

    if (argc == 2) {
        shift = strtol(argv[1], NULL, 10);
        if (shift > 0) {
            printf("Enter a string to encrypt (with shift %d)\n", shift);
            fgets(msg, MAX_INPUT_SIZE, stdin);
            if ((strlen(msg) > 0) && (msg[strlen (msg) - 1] == '\n'))
                msg[strlen (msg) - 1] = '\0';
            
            encrypt(msg, shift);
            printf("\nResult: \n%s\n", msg);
        } else {
            usage();
        }
    } else {
        usage();
    }
    free(msg);
    return 0;
}

void usage() {
    printf("cipher [shifting>0]\n");
}