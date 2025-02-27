#include <stdio.h>

/** Code fourni :
unsigned int i, nrep;
nrep = packet_get_int();
response = malloc(nrep * sizeof(char*));
if (response != NULL)
    for (i = 0; i < nrep; i++)
        response[i] = packet_get_string(NULL);
*/

unsigned int i, nrep;
nrep = packet_get_int();

// On vérifie que { nrep * (taille d'un pointeur) } ne cause pas un wrap.
if (nrep > SIZE_MAX / sizeof(char*)) {
    // Erreur : dépassement potentiel
    return -EFBIG;
}

response = malloc(nrep * sizeof(char*));
if (response != NULL)
    for (i = 0; i < nrep; i++)
        response[i] = packet_get_string(NULL);