#include <assert.h>
#include <stdio.h>

/* Code Original :
void compute(int x, int y) {
    int z, u;
    u = x;
    z = 0;
    while (z < y) {
        z = z + 1;
        u = u + 1;
    }
    return u;
    4
}
int main() {
    int a;
    a = compute(5, 3);
    tab[a] = 0;
    return 0;
}
*/

int compute(int x, int y) {  // Correction : la fonction doit retourner un int
    int z, u;
    u = x;
    z = 0;
    while (z < y) {
        z = z + 1;
        u = u + 1;
    }
    return u;
}

int main() {
    int a;
    int tab[33]; // Supposons un tableau défini
    a = compute(5, 3);
    // Insertion de l’assertion pour vérifier que a est dans les bornes de tab
    assert(a >= 0 && a < 33);
    tab[a] = 0;
    return 0;
}