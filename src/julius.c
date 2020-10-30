#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

/* Chiffre in place to_encrypt avec le chiffrement de César (décalage shift) */
void encrypt(char *to_encrypt, int shift){
    int i, j;
    
    // on parcourt la chaîne de charactères à chiffrer
    for (i = 0; i < (int)strlen(to_encrypt); i++){

        // on effectue le décalage shift fois
        for (j = 0; j < shift; j++){

            // on vérifie que le charactère est une lettre
            if (isalpha(to_encrypt[i])) {

                // on effectue une fois le décalage
                if (to_encrypt[i] == 'z')
                    to_encrypt[i] = 'a';
                else if (to_encrypt[i] == 'Z')
                    to_encrypt[i] = 'A';
                else
                    to_encrypt[i] = (char)(((int)to_encrypt[i]) + 1);
            }
        }
    }
}

/* Déchiffre in place to_decrypt avec le chiffrement de César (décalage shift) */
void decrypt(char *to_decrypt, int shift){
    int i, j;

    // on parcourt la chaîne de charactères à chiffrer
    for (i = 0; i < (int)strlen(to_decrypt); i++){

        // on effectue le décalage shift fois
        for (j = 0; j < shift; j++){

            // on vérifie que le charactère est une lettre
            if (isalpha(to_decrypt[i])) {

                // on effectue une fois le décalage dans l'autre sens
                if (to_decrypt[i] == 'a')
                    to_decrypt[i] = 'z';
                else if (to_decrypt[i] == 'A')
                    to_decrypt[i] = 'Z';
                else
                    to_decrypt[i] = (char)(((int)to_decrypt[i]) - 1);
            }
        }
    }
}