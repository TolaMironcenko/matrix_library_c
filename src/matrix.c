#include <stdio.h>
#include <stdlib.h>
#include <libcmatrix/matrix.h>

int main() {
    system("clear");

    int rows = 3;
    int columns = 2;
    int mtri[6] = {1, 2, 3, 4, 5, 6};

    printf("int matrix:\n");

    intMatrix *mi = malloc(sizeof(mi));
    newIntMatrix(mi, rows, columns, mtri);
    printIntMatrix(mi);
    printf("\n\n");
    setValueToInt(mi, 1, 1, 1000);
    printIntMatrix(mi);
    // intMatrix *mi1 = copyIntMatrix(mi);
    // printIntMatrix(mi);
    // printf("\n\n");
    // printIntMatrix(mi1);

    printf("\n\n%d  %d\n", getValueFromInt(mi, 1, 1), getValueFromInt(mi, 2, 2));

    freeIntMatrix(mi);
    // freeIntMatrix(mi1);
    return 0;
}
