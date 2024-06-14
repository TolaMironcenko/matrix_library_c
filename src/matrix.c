#include <stdio.h>
#include <stdlib.h>
#include <matrix/matrix.h>

int main() {
    system("clear");

    int rows = 3;
    int columns = 2;
    char mtri[6] = "qwerty";

    printf("int matrix:\n");

    charMatrix *mi = malloc(sizeof(mi));
    newCharMatrix(mi, rows, columns, mtri);
    printCharMatrix(mi);

    printf("\n\ntransponsed:\n");
    transponseCharMatrix(mi);
    printCharMatrix(mi);

    freeCharMatrix(mi);

    return 0;
}
