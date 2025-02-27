#include <stdio.h>

/** Code Fourni :
    int offset, len; // entiers signés
    // vérifier d'abord que offset et len sont positifs
    if (offset < 0 || len <= 0)
    return -EINVAL;
    // si offset + len dépasse le seuil MAXSIZE, ou en cas de dépassement,
    // retourner un code d'erreur
    if ((offset + len > MAXSIZE) || (offset + len < 0))
    return -EFBIG; // offset + len déborde
    // supposer à partir de maintenant que len + offset n'a pas débordé ...
*/

int main(void) {
    int offset, len; // entiers signés
    // vérifier d'abord que offset et len sont positifs
    if (offset < 0 || len <= 0)
        return -EINVAL;
    // si offset + len dépasse le seuil MAXSIZE, ou en cas de dépassement,
    // retourner un code d'erreur
    if ((offset + len > MAXSIZE) || (offset + len < 0))
        return -EFBIG; // offset + len déborde

    // Meilleure vérification de débordement
    if ((unsigned)offset > MAXSIZE || (unsigned)len > MAXSIZE - (unsigned)offset) {
        return -EFBIG;
    }
    /* supposer à partir de maintenant que len + offset n'a pas débordé ... */
}