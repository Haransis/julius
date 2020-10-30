#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cipher.h>
#include <julius.h>

#define MAX_INPUT_SIZE 100

int main(int argc, char *argv []){
    char *msg = malloc(MAX_INPUT_SIZE + 2); // +2 car fgets ajoute un '\n' et NULL
    int shift;

    if (argc == 2) {
        shift = strtol(argv[1], NULL, 10);
        if (shift > 0) {
            printf("Enter a string to encrypt (with shift %d)\n", shift);
            fgets(msg, MAX_INPUT_SIZE, stdin);
            
            // On retire '\n' s'il y a lieu
            if ((strlen(msg) > 0) && (msg[strlen (msg) - 1] == '\n'))
                msg[strlen (msg) - 1] = '\0';
            
            // On vérifie si l'entrée utilisateur ne dépasse pas la taille autorisée
            if (!(feof(stdin) || (strlen(msg) != 0 && msg[strlen(msg)-1] == '\n'))){
                printf("\nToo long message. Maximum length is %d\n", MAX_INPUT_SIZE);
                return 1;
            }
            
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