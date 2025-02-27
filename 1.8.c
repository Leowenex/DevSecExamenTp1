#include <stdio.h>

void safewrite(int tab[], int size, signed char ind, int val) {
    if (ind >= 0 && ind < size)
        tab[ind] = val;
    else
        printf("Hors limites\n");
}
