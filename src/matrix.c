#include <stdio.h>
#include <stdlib.h>
#include <libcmatrix/matrix.h>

int main() {
    system("clear");

    int arr1[4] = {1, 2, 3, 4};
    float arr2[4] = {4, 6, 5, 2};

    intMatrix *m1 = malloc(sizeof(m1));
    newIntMatrix(m1, 2, 2, arr1);
    floatMatrix *m2 = malloc(sizeof(m2));
    newFloatMatrix(m2, 2, 2, arr2);

    printf("m1:\n");
    printIntMatrix(m1);
    printf("\nm2:\n");
    printFloatMatrix(m2);
    printf("\nres:\n");
    printIntMatrix(transformFromFloatToInt(m2));
    int *arr11 = toIntArrayFloat(m2);
    for (int i = 0; i < 4; i++) {
        printf("%d   ", arr11[i]);
    }
    printf("\n");

    // powIntMatrix(m1, 2);
    // printf("\n\npowed matrix:\n");
    // printIntMatrix(m1);

    // printFloatMatrix(multiplyFloatWithIntMatrix(m2, m1));


    freeIntMatrix(m1);
    freeFloatMatrix(m2);
    return 0;
}
