#include <string.h>
#include <stdlib.h>
#include <ctype.h>

/* Chiffre to_encrypt avec le chiffrement de César (décalage shift) */
char * encrypt(const char *to_encrypt, int shift){
    int i, j;

    //alloue la mémoire suffisante à result
    char *result = malloc (strlen(to_encrypt));

    // copie to_encrypt dans result
    strcpy(result, to_encrypt);
    
    // on parcourt la chaîne de charactères à chiffrer
    for (i = 0; i < (int)strlen(result); i++){

        // on effectue le décalage shift fois
        for (j = 0; j < shift; j++){

            // on vérifie que le charactère est une lettre
            if (isalpha(result[i])) {

                // on effectue une fois le décalage
                if (result[i] == 'z')
                    result[i] = 'a';
                else if (result[i] == 'Z')
                    result[i] = 'A';
                else
                    result[i] = (char)(((int)result[i]) + 1);
            }
        }
    }
    return result;
}

/* Déchiffre to_decrypt avec le chiffrement de César (décalage shift) */
char * decrypt(const char *to_decrypt, int shift){
    int i, j;

    //alloue la mémoire suffisante à result    
    char *result = malloc (strlen(to_decrypt));

    // copie to_encrypt dans result
    strcpy(result, to_decrypt);
    
    // on parcourt la chaîne de charactères à chiffrer
    for (i = 0; i < (int)strlen(result); i++){

        // on effectue le décalage shift fois
        for (j = 0; j < shift; j++){

            // on vérifie que le charactère est une lettre
            if (isalpha(result[i])) {

                // on effectue une fois le décalage dans l'autre sens
                if (result[i] == 'a')
                    result[i] = 'z';
                else if (result[i] == 'A')
                    result[i] = 'Z';
                else
                    result[i] = (char)(((int)result[i]) - 1);
            }
        }
    }
    return result;
}