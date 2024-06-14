#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>

// ---------------- structures -------------------
typedef struct intMatrix {
    int rows;
    int columns;
    int **m;
} intMatrix;
typedef struct floatMatrix {
    int rows;
    int columns;
    float **m;
} floatMatrix;
typedef struct doubleMatrix {
    int rows;
    int columns;
    double **m;
} doubleMatrix;
typedef struct charMatrix {
    int rows;
    int columns;
    char **m;
} charMatrix;
// -------------------------------------------------

// -------------------------- create functions ----------------------------------------------------------------
void newIntMatrix(intMatrix *m1, const int rows, const int columns, int *matrixArray) {
    m1->rows = rows;
    m1->columns = columns;
    m1->m = (int**)malloc(rows * sizeof(int));
    int matrixArrayIterator = 0;
    for (int i = 0; i < rows; i++) {
        m1->m[i] = (int*)malloc(columns * sizeof(int));
        for (int j = 0; j < columns; j++) {
            m1->m[i][j] = matrixArray[matrixArrayIterator];
            matrixArrayIterator++;
        }
    }
}
void newFloatMatrix(floatMatrix *m1, const int rows, const int columns, float *matrixArray) {
    m1->rows = rows;
    m1->columns = columns;
    m1->m = (float**)malloc(rows * sizeof(int));
    int matrixArrayIterator = 0;
    for (int i = 0; i < rows; i++) {
        m1->m[i] = (float*)malloc(columns * sizeof(int));
        for (int j = 0; j < columns; j++) {
            m1->m[i][j] = matrixArray[matrixArrayIterator];
            matrixArrayIterator++;
        }
    }
}
void newDoubleMatrix(doubleMatrix *m1, const int rows, const int columns, double *matrixArray) {
    m1->rows = rows;
    m1->columns = columns;
    m1->m = (double**)malloc(rows * sizeof(int));
    int matrixArrayIterator = 0;
    for (int i = 0; i < rows; i++) {
        m1->m[i] = (double*)malloc(columns * sizeof(int));
        for (int j = 0; j < columns; j++) {
            m1->m[i][j] = matrixArray[matrixArrayIterator];
            matrixArrayIterator++;
        }
    }
}
void newCharMatrix(charMatrix *m1, const int rows, const int columns, char *matrixArray) {
    m1->rows = rows;
    m1->columns = columns;
    m1->m = (char**)malloc(rows * sizeof(int));
    int matrixArrayIterator = 0;
    for (int i = 0; i < rows; i++) {
        m1->m[i] = (char*)malloc(columns * sizeof(int));
        for (int j = 0; j < columns; j++) {
            m1->m[i][j] = matrixArray[matrixArrayIterator];
            matrixArrayIterator++;
        }
    }
}
// ----------------------------------------------------------------------------------------------------------------

// ------- print functions --------------------------
void printIntMatrix(intMatrix *m1) {
    for (int i = 0; i < m1->rows; i++) {
        for (int j = 0; j < m1->columns; j++) {
            printf("%d\t", m1->m[i][j]);
        }
        printf("\n");
    }
}
void printFloatMatrix(floatMatrix *m1) {
    for (int i = 0; i < m1->rows; i++) {
        for (int j = 0; j < m1->columns; j++) {
            printf("%f\t", m1->m[i][j]);
        }
        printf("\n");
    }
}
void printDoubleMatrix(doubleMatrix *m1) {
    for (int i = 0; i < m1->rows; i++) {
        for (int j = 0; j < m1->columns; j++) {
            printf("%f\t", m1->m[i][j]);
        }
        printf("\n");
    }
}
void printCharMatrix(charMatrix *m1) {
    for (int i = 0; i < m1->rows; i++) {
        for (int j = 0; j < m1->columns; j++) {
            printf("%c\t", m1->m[i][j]);
        }
        printf("\n");
    }
}
// ---------------------------------------------------

// ----------- free(delete functions) ----------
void freeIntMatrix(intMatrix *m1) {
    for (int i = 0; i < m1->rows; i++) {
        free(m1->m[i]);
    }
    free(m1->m);
}
void freeFloatMatrix(floatMatrix *m1) {
    for (int i = 0; i < m1->rows; i++) {
        free(m1->m[i]);
    }
    free(m1->m);
}
void freeDoubleMatrix(doubleMatrix *m1) {
    for (int i = 0; i < m1->rows; i++) {
        free(m1->m[i]);
    }
    free(m1->m);
}
void freeCharMatrix(charMatrix *m1) {
    for (int i = 0; i < m1->rows; i++) {
        free(m1->m[i]);
    }
    free(m1->m);
}
// ----------------------------------------------

// ------- add functions ------------------
void addIntMatrix(intMatrix *m1, intMatrix *m2) {
    if (m1->rows == m2->rows && m1->columns == m2->columns) {
        for (int i = 0; i < m1->rows; i++) {
            for (int j = 0; j < m1->columns; j++) {
                m1->m[i][j] = m1->m[i][j] + m2->m[i][j];
            }
        }
        return;
    }
    printf("matrices cannot be added because they are of different lengths.\n");
    return;
}
floatMatrix *addToIntFloat(intMatrix *m1, floatMatrix *m2) {
    if (m1->rows == m2->rows && m1->columns == m2->columns) {
        floatMatrix *res = malloc(sizeof(res));
        float resarray[m1->rows * m1->columns];
        int resarrayiterator = 0;
        for (int i = 0; i < m1->rows; i++) {
            for (int j = 0; j < m1->columns; j++) {
                resarray[resarrayiterator] = m1->m[i][j] + m2->m[i][j];
                resarrayiterator++;
            }
        }
        newFloatMatrix(res, m1->rows, m1->columns, resarray);
        return res;
    }
    printf("matrices cannot be added because they are of different lengths.\n");
    return NULL;
}
doubleMatrix *addToIntDouble(intMatrix *m1, doubleMatrix *m2) {
    if (m1->rows == m2->rows && m1->columns == m2->columns) {
        doubleMatrix *res = malloc(sizeof(res));
        double resarray[m1->rows * m1->columns];
        int resarrayiterator = 0;
        for (int i = 0; i < m1->rows; i++) {
            for (int j = 0; j < m1->columns; j++) {
                resarray[resarrayiterator] = m1->m[i][j] + m2->m[i][j];
                resarrayiterator++;
            }
        }
        newDoubleMatrix(res, m1->rows, m1->columns, resarray);
        return res;
    }
    printf("matrices cannot be added because they are of different lengths.\n");
    return NULL;
}
charMatrix *addToIntChar(intMatrix *m1, charMatrix *m2) {
    if (m1->rows == m2->rows && m1->columns == m2->columns) {
        charMatrix *res = malloc(sizeof(res));
        char resarray[m1->rows * m1->columns];
        int resarrayiterator = 0;
        for (int i = 0; i < m1->rows; i++) {
            for (int j = 0; j < m1->columns; j++) {
                resarray[resarrayiterator] = m1->m[i][j] + m2->m[i][j];
                resarrayiterator++;
            }
        }
        newCharMatrix(res, m1->rows, m1->columns, resarray);
        return res;
    }
    printf("matrices cannot be added because they are of different lengths.\n");
    return NULL;
}
void addFloatMatrix(floatMatrix *m1, floatMatrix *m2) {
    if (m1->rows == m2->rows && m1->columns == m2->columns) {
        for (int i = 0; i < m1->rows; i++) {
            for (int j = 0; j < m1->columns; j++) {
                m1->m[i][j] = m1->m[i][j] + m2->m[i][j];
            }
        }
        return;
    }
    printf("matrices cannot be added because they are of different lengths.\n");
    return;
}
void addToFloatInt(floatMatrix *m1, intMatrix *m2) {
    if (m1->rows == m2->rows && m1->columns == m2->columns) {
        for (int i = 0; i < m1->rows; i++) {
            for (int j = 0; j < m1->columns; j++) {
                m1->m[i][j] = m1->m[i][j] + m2->m[i][j];
            }
        }
        return;
    }
    printf("matrices cannot be added because they are of different lengths.\n");
    return;
}
floatMatrix *rAddToFloatInt(floatMatrix *m1, intMatrix *m2) {
    if (m1->rows == m2->rows && m1->columns == m2->columns) {
        floatMatrix *res = malloc(sizeof(res));
        float resarray[m1->rows * m1->columns];
        int resarrayiterator = 0;
        for (int i = 0; i < m1->rows; i++) {
            for (int j = 0; j < m1->columns; j++) {
                resarray[resarrayiterator] = m1->m[i][j] + m2->m[i][j];
                resarrayiterator++;
            }
        }
        newFloatMatrix(res, m1->rows, m1->columns, resarray);
        return res;
    }
    printf("matrices cannot be added because they are of different lengths.\n");
    return NULL;
}
void addToFloatDouble(floatMatrix *m1, doubleMatrix *m2) {
    if (m1->rows == m2->rows && m1->columns == m2->columns) {
        for (int i = 0; i < m1->rows; i++) {
            for (int j = 0; j < m1->columns; j++) {
                m1->m[i][j] = m1->m[i][j] + m2->m[i][j];
            }
        }
        return;
    }
    printf("matrices cannot be added because they are of different lengths.\n");
    return;
}
floatMatrix *rAddToFloatDouble(floatMatrix *m1, doubleMatrix *m2) {
    if (m1->rows == m2->rows && m1->columns == m2->columns) {
        floatMatrix *res = malloc(sizeof(res));
        float resarray[m1->rows * m1->columns];
        int resarrayiterator = 0;
        for (int i = 0; i < m1->rows; i++) {
            for (int j = 0; j < m1->columns; j++) {
                resarray[resarrayiterator] = m1->m[i][j] + m2->m[i][j];
                resarrayiterator++;
            }
        }
        newFloatMatrix(res, m1->rows, m1->columns, resarray);
        return res;
    }
    printf("matrices cannot be added because they are of different lengths.\n");
    return NULL;
}
void addDoubleMatrix(doubleMatrix *m1, doubleMatrix *m2) {
    if (m1->rows == m2->rows && m1->columns == m2->columns) {
        for (int i = 0; i < m1->rows; i++) {
            for (int j = 0; j < m1->columns; j++) {
                m1->m[i][j] = m1->m[i][j] + m2->m[i][j];
            }
        }
        return;
    }
    printf("matrices cannot be added because they are of different lengths.\n");
    return;
}
void addToDoubleInt(doubleMatrix *m1, intMatrix *m2) {
    if (m1->rows == m2->rows && m1->columns == m2->columns) {
        for (int i = 0; i < m1->rows; i++) {
            for (int j = 0; j < m1->columns; j++) {
                m1->m[i][j] = m1->m[i][j] + m2->m[i][j];
            }
        }
        return;
    }
    printf("matrices cannot be added because they are of different lengths.\n");
    return;
}
doubleMatrix *rAddToDoubleInt(doubleMatrix *m1, intMatrix *m2) {
    if (m1->rows == m2->rows && m1->columns == m2->columns) {
        doubleMatrix *res = malloc(sizeof(res));
        double resarray[m1->rows * m1->columns];
        int resarrayiterator = 0;
        for (int i = 0; i < m1->rows; i++) {
            for (int j = 0; j < m1->columns; j++) {
                resarray[resarrayiterator] = m1->m[i][j] + m2->m[i][j];
                resarrayiterator++;
            }
        }
        newDoubleMatrix(res, m1->rows, m1->columns, resarray);
        return res;
    }
    printf("matrices cannot be added because they are of different lengths.\n");
    return NULL;
}
floatMatrix *addToDoubleFloat(doubleMatrix *m1, floatMatrix *m2) {
    if (m1->rows == m2->rows && m1->columns == m2->columns) {
        floatMatrix *res = malloc(sizeof(res));
        float resarray[m1->rows * m1->columns];
        int resarrayiterator = 0;
        for (int i = 0; i < m1->rows; i++) {
            for (int j = 0; j < m1->columns; j++) {
                resarray[resarrayiterator] = m1->m[i][j] + m2->m[i][j];
                resarrayiterator++;
            }
        }
        newFloatMatrix(res, m1->rows, m1->columns, resarray);
        return res;
    }
    printf("matrices cannot be added because they are of different lengths.\n");
    return NULL;
}
void addCharMatrix(charMatrix *m1, charMatrix *m2) {
    if (m1->rows == m2->rows && m1->columns == m2->columns) {
        for (int i = 0; i < m1->rows; i++) {
            for (int j = 0; j < m1->columns; j++) {
                m1->m[i][j] = m1->m[i][j] + m2->m[i][j];
            }
        }
        return;
    }
    printf("matrices cannot be added because they are of different lengths.\n");
    return;
}
// ----------------------------------------

// ----------- sub functions ----------------------------
void subIntMatrix(intMatrix *m1, intMatrix *m2) {
    if (m1->rows == m2->rows && m1->columns == m2->columns) {
        for (int i = 0; i < m1->rows; i++) {
            for (int j = 0; j < m1->columns; j++) {
                m1->m[i][j] = m1->m[i][j] - m2->m[i][j];
            }
        }
        return;
    }
    printf("matrices cannot be added because they are of different lengths.\n");
    return;
}
floatMatrix *subFromIntFloat(intMatrix *m1, floatMatrix *m2) {
    if (m1->rows == m2->rows && m1->columns == m2->columns) {
        floatMatrix *res = malloc(sizeof(res));
        float resarray[m1->rows * m1->columns];
        int resarrayiterator = 0;
        for (int i = 0; i < m1->rows; i++) {
            for (int j = 0; j < m1->columns; j++) {
                resarray[resarrayiterator] = m1->m[i][j] - m2->m[i][j];
                resarrayiterator++;
            }
        }
        newFloatMatrix(res, m1->rows, m1->columns, resarray);
        return res;
    }
    printf("matrices cannot be added because they are of different lengths.\n");
    return NULL;
}
doubleMatrix *subFromIntDouble(intMatrix *m1, doubleMatrix *m2) {
    if (m1->rows == m2->rows && m1->columns == m2->columns) {
        doubleMatrix *res = malloc(sizeof(res));
        double resarray[m1->rows * m1->columns];
        int resarrayiterator = 0;
        for (int i = 0; i < m1->rows; i++) {
            for (int j = 0; j < m1->columns; j++) {
                resarray[resarrayiterator] = m1->m[i][j] - m2->m[i][j];
                resarrayiterator++;
            }
        }
        newDoubleMatrix(res, m1->rows, m1->columns, resarray);
        return res;
    }
    printf("matrices cannot be added because they are of different lengths.\n");
    return NULL;
}
charMatrix *subFromIntChar(intMatrix *m1, charMatrix *m2) {
    if (m1->rows == m2->rows && m1->columns == m2->columns) {
        charMatrix *res = malloc(sizeof(res));
        char resarray[m1->rows * m1->columns];
        int resarrayiterator = 0;
        for (int i = 0; i < m1->rows; i++) {
            for (int j = 0; j < m1->columns; j++) {
                resarray[resarrayiterator] = m1->m[i][j] - m2->m[i][j];
                resarrayiterator++;
            }
        }
        newCharMatrix(res, m1->rows, m1->columns, resarray);
        return res;
    }
    printf("matrices cannot be added because they are of different lengths.\n");
    return NULL;
}
void subFloatMatrix(floatMatrix *m1, floatMatrix *m2) {
    if (m1->rows == m2->rows && m1->columns == m2->columns) {
        for (int i = 0; i < m1->rows; i++) {
            for (int j = 0; j < m1->columns; j++) {
                m1->m[i][j] = m1->m[i][j] - m2->m[i][j];
            }
        }
        return;
    }
    printf("matrices cannot be added because they are of different lengths.\n");
    return;
}
void subFromFloatInt(floatMatrix *m1, intMatrix *m2) {
    if (m1->rows == m2->rows && m1->columns == m2->columns) {
        for (int i = 0; i < m1->rows; i++) {
            for (int j = 0; j < m1->columns; j++) {
                m1->m[i][j] = m1->m[i][j] - m2->m[i][j];
            }
        }
        return;
    }
    printf("matrices cannot be added because they are of different lengths.\n");
    return;
}
floatMatrix *rSubFromFloatInt(floatMatrix *m1, intMatrix *m2) {
    if (m1->rows == m2->rows && m1->columns == m2->columns) {
        floatMatrix *res = malloc(sizeof(res));
        float resarray[m1->rows * m1->columns];
        int resarrayiterator = 0;
        for (int i = 0; i < m1->rows; i++) {
            for (int j = 0; j < m1->columns; j++) {
                resarray[resarrayiterator] = m1->m[i][j] - m2->m[i][j];
                resarrayiterator++;
            }
        }
        newFloatMatrix(res, m1->rows, m1->columns, resarray);
        return res;
    }
    printf("matrices cannot be added because they are of different lengths.\n");
    return NULL;
}
void subFromFloatDouble(floatMatrix *m1, doubleMatrix *m2) {
    if (m1->rows == m2->rows && m1->columns == m2->columns) {
        for (int i = 0; i < m1->rows; i++) {
            for (int j = 0; j < m1->columns; j++) {
                m1->m[i][j] = m1->m[i][j] - m2->m[i][j];
            }
        }
        return;
    }
    printf("matrices cannot be added because they are of different lengths.\n");
    return;
}
floatMatrix *rSubFromFloatDouble(floatMatrix *m1, doubleMatrix *m2) {
    if (m1->rows == m2->rows && m1->columns == m2->columns) {
        floatMatrix *res = malloc(sizeof(res));
        float resarray[m1->rows * m1->columns];
        int resarrayiterator = 0;
        for (int i = 0; i < m1->rows; i++) {
            for (int j = 0; j < m1->columns; j++) {
                resarray[resarrayiterator] = m1->m[i][j] - m2->m[i][j];
                resarrayiterator++;
            }
        }
        newFloatMatrix(res, m1->rows, m1->columns, resarray);
        return res;
    }
    printf("matrices cannot be added because they are of different lengths.\n");
    return NULL;
}
void subDoubleMatrix(doubleMatrix *m1, doubleMatrix *m2) {
    if (m1->rows == m2->rows && m1->columns == m2->columns) {
        for (int i = 0; i < m1->rows; i++) {
            for (int j = 0; j < m1->columns; j++) {
                m1->m[i][j] = m1->m[i][j] - m2->m[i][j];
            }
        }
        return;
    }
    printf("matrices cannot be added because they are of different lengths.\n");
    return;
}
void subFromDoubleInt(doubleMatrix *m1, intMatrix *m2) {
    if (m1->rows == m2->rows && m1->columns == m2->columns) {
        for (int i = 0; i < m1->rows; i++) {
            for (int j = 0; j < m1->columns; j++) {
                m1->m[i][j] = m1->m[i][j] - m2->m[i][j];
            }
        }
        return;
    }
    printf("matrices cannot be added because they are of different lengths.\n");
    return;
}
doubleMatrix *rSubFromDoubleInt(doubleMatrix *m1, intMatrix *m2) {
    if (m1->rows == m2->rows && m1->columns == m2->columns) {
        doubleMatrix *res = malloc(sizeof(res));
        double resarray[m1->rows * m1->columns];
        int resarrayiterator = 0;
        for (int i = 0; i < m1->rows; i++) {
            for (int j = 0; j < m1->columns; j++) {
                resarray[resarrayiterator] = m1->m[i][j] - m2->m[i][j];
                resarrayiterator++;
            }
        }
        newDoubleMatrix(res, m1->rows, m1->columns, resarray);
        return res;
    }
    printf("matrices cannot be added because they are of different lengths.\n");
    return NULL;
}
floatMatrix *subFromDoubleFloat(doubleMatrix *m1, floatMatrix *m2) {
    if (m1->rows == m2->rows && m1->columns == m2->columns) {
        floatMatrix *res = malloc(sizeof(res));
        float resarray[m1->rows * m1->columns];
        int resarrayiterator = 0;
        for (int i = 0; i < m1->rows; i++) {
            for (int j = 0; j < m1->columns; j++) {
                resarray[resarrayiterator] = m1->m[i][j] + m2->m[i][j];
                resarrayiterator++;
            }
        }
        newFloatMatrix(res, m1->rows, m1->columns, resarray);
        return res;
    }
    printf("matrices cannot be added because they are of different lengths.\n");
    return NULL;
}
void subCharMatrix(charMatrix *m1, charMatrix *m2) {
    if (m1->rows == m2->rows && m1->columns == m2->columns) {
        for (int i = 0; i < m1->rows; i++) {
            for (int j = 0; j < m1->columns; j++) {
                m1->m[i][j] = m1->m[i][j] - m2->m[i][j];
            }
        }
        return;
    }
    printf("matrices cannot be added because they are of different lengths.\n");
    return;
}
// ------------------------------------------------------
