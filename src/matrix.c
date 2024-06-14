#include <stdio.h>
#include <stdlib.h>
#include <matrix/matrix.h>

int main() {
    system("clear");

    int rows = 3;
    int columns = 3;
    int mtri[9] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    float mtrf[9] = {0.1, 1.2, 2.3, 3.4, 4.5, 5.6, 6.7, 7.8, 8.9};
    double mtrd[9] = {0.9, 1.8, 2.7, 3.6, 4.5, 5.4, 6.3, 7.2, 8.1};
    char mtrc[27] = "abcdefghijklmnopqrstuvwxyz";

    printf("int matrix:\n");

    intMatrix *mi = malloc(sizeof(mi));
    newIntMatrix(mi, rows, columns, mtri);
    printIntMatrix(mi);

    printf("\n\nchar matrix:\n");

    charMatrix *mc = malloc(sizeof(mc));
    newCharMatrix(mc, rows, columns, mtrc);
    printCharMatrix(mc);

    printf("\n\nmi+mc:\n");

    charMatrix *mimc = malloc(sizeof(mimc));
    mimc = addToIntChar(mi, mc);
    printCharMatrix(mimc);

    freeIntMatrix(mi);
    freeCharMatrix(mc);
    freeCharMatrix(mimc);

    return 0;
}
