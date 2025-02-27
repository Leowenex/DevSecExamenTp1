#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

/** Code Original :
int main() {
    char t1[255], *p, *q, *r;
    char n;
    scanf("%s", t1);    // Lire le contenu de t1
    scanf("%i", n);     // Lire la valeur de n
    if (n < 255) {
        p = malloc(n);
        q = p;
        strcpy(p, t1);
        printf("%s", q);  // Afficher le contenu de p
        free(q);
    }
    r = malloc(120);
    ...
    printf("%s", p);    // Afficher le contenu de p
    return 0;
}
*/

int main() {
    char t1[255];
    // On ajoute deux variable pour la lecture de n
    char t2[255];
    char *endPtr;
    char *p = NULL, *q = NULL, *r = NULL;

    // On remplace scanf par getc pour améliorer la sécurité et gérer les espaces
    printf("Entrez votre mot : ");
    fgets(t1, 255, stdin);

    // On remplace scanf par fgets et strol pour récupérer la valeur
    printf("Entrez la longueur de votre chaine de copie : ");
    fgets(t2, 4, stdin);
    long n = strtol(t2, &endPtr, 10);

    if (n < (int)(strlen(t1) + 1) || n >= 255) {  
        fprintf(stderr, "Taille n incorrecte : doit etre >= %lu et < 255\n", strlen(t1) + 1);
        exit(EXIT_FAILURE);
    }

    p = malloc(n);
    if (p == NULL) {
        perror("malloc p");
        exit(EXIT_FAILURE);
    }

    q = p;

    // On utilise strncpy pour limiter la copie à la longueur de p
    strncpy(p, t1, n - 1);
    p[n - 1] = '\0';
    printf("%s\n", q);  // Affichage correct

    //On retire le free pour que p puisse être utilisé plus tard dans le programme
    //free(q);
    //p = NULL;

    r = malloc(120);
    if (r == NULL) {
        perror("malloc r");
        exit(EXIT_FAILURE);
    }

    // Utilisation de r ...

    // Libérer r après utilisation
    free(r);

    printf("%s", p);

    // On free p après sa dernière utilisation
    free(q);
    p = NULL;

    return 0;
}
