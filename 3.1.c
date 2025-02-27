#include <assert.h>
#include <stdio.h>

/* Code Original :

int main() {
    int x;
    int tab[33];
    x = 1;
    while (x < 24)
        x = x * 2;
    tab[x] = 0;
    return 0;
}

*/

int main(void) {
    int x;
    int tab[33];
    x = 1;
    while (x < 24)
        x = x * 2;
    // Insertion de l’assertion pour vérifier que x est dans les bornes de tab
    assert(x >= 0 && x < 33);
    tab[x] = 0;
    return 0;
}