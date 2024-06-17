#ifndef MATRIX_H
#define MATRIX_H

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
void addToCharInt(charMatrix *m1, intMatrix *m2) {
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
charMatrix *rAddToCharInt(charMatrix *m1, intMatrix *m2) {
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
void subFromCharInt(charMatrix *m1, intMatrix *m2) {
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
charMatrix *rSubFromCharInt(charMatrix *m1, intMatrix *m2) {
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
// ------------------------------------------------------

// --------------- transpose functions ------------------
void transponseIntMatrix(intMatrix *m1) {
    int resarray[m1->rows * m1->columns];
    int rows = m1->columns;
    int columns = m1->rows;
    int resarrayiterator = 0;
    for (int i = 0; i < m1->columns; i++) {
        for (int j = 0; j < m1->rows; j++) {
            resarray[resarrayiterator] = m1->m[j][i];
            resarrayiterator++;
        }
    }
    freeIntMatrix(m1);
    newIntMatrix(m1, rows, columns, resarray);
}
void transponseFloatMatrix(floatMatrix *m1) {
    float resarray[m1->rows * m1->columns];
    int rows = m1->columns;
    int columns = m1->rows;
    int resarrayiterator = 0;
    for (int i = 0; i < m1->columns; i++) {
        for (int j = 0; j < m1->rows; j++) {
            resarray[resarrayiterator] = m1->m[j][i];
            resarrayiterator++;
        }
    }
    freeFloatMatrix(m1);
    newFloatMatrix(m1, rows, columns, resarray);
}
void transponseDoubleMatrix(doubleMatrix *m1) {
    double resarray[m1->rows * m1->columns];
    int rows = m1->columns;
    int columns = m1->rows;
    int resarrayiterator = 0;
    for (int i = 0; i < m1->columns; i++) {
        for (int j = 0; j < m1->rows; j++) {
            resarray[resarrayiterator] = m1->m[j][i];
            resarrayiterator++;
        }
    }
    freeDoubleMatrix(m1);
    newDoubleMatrix(m1, rows, columns, resarray);
}
void transponseCharMatrix(charMatrix *m1) {
    char resarray[m1->rows * m1->columns];
    int rows = m1->columns;
    int columns = m1->rows;
    int resarrayiterator = 0;
    for (int i = 0; i < m1->columns; i++) {
        for (int j = 0; j < m1->rows; j++) {
            resarray[resarrayiterator] = m1->m[j][i];
            resarrayiterator++;
        }
    }
    freeCharMatrix(m1);
    newCharMatrix(m1, rows, columns, resarray);
}
// ------------------------------------------------------

// ---------------- multiply functions ----------------------------
void multiplyByIntNumInt(intMatrix *m1, const int num) {
    for (int i = 0; i < m1->rows; i++) {
        for (int j = 0; j < m1->columns; j++) {
            m1->m[i][j] = m1->m[i][j] * num;
        }   
    }
}
intMatrix *rMultiplyByIntNumInt(intMatrix *m1, const int num) {
    int resarray[m1->rows * m1->columns];
    int resarrayiterator = 0;
    for (int i = 0; i < m1->rows; i++) {
        for (int j = 0; j < m1->columns; j++) {
            resarray[resarrayiterator] = m1->m[i][j] * num;
            resarrayiterator++;
        }
    }
    intMatrix *res = malloc(sizeof(res));
    newIntMatrix(res, m1->rows, m1->columns, resarray);
    return res;
}
floatMatrix *multiplyByFloatNumInt(intMatrix *m1, const float num) {
    float resarray[m1->rows * m1->columns];
    int resarrayiterator = 0;
    for (int i = 0; i < m1->rows; i++) {
        for (int j = 0; j < m1->columns; j++) {
            resarray[resarrayiterator] = m1->m[i][j] * num;
            resarrayiterator++;
        }
    }
    floatMatrix *res = malloc(sizeof(res));
    newFloatMatrix(res, m1->rows, m1->columns, resarray);
    return res;
}
doubleMatrix *multiplyByDoubleNumInt(intMatrix *m1, const double num) {
    double resarray[m1->rows * m1->columns];
    int resarrayiterator = 0;
    for (int i = 0; i < m1->rows; i++) {
        for (int j = 0; j < m1->columns; j++) {
            resarray[resarrayiterator] = m1->m[i][j] * num;
            resarrayiterator++;
        }
    }
    doubleMatrix *res = malloc(sizeof(res));
    newDoubleMatrix(res, m1->rows, m1->columns, resarray);
    return res;
}
void multiplyByIntNumFloat(floatMatrix *m1, const int num) {
    for (int i = 0; i < m1->rows; i++) {
        for (int j = 0; j < m1->columns; j++) {
            m1->m[i][j] = m1->m[i][j] * num;
        }   
    }
}
floatMatrix *rMultiplyByIntNumFloat(floatMatrix *m1, const int num) {
    float resarray[m1->rows * m1->columns];
    int resarrayiterator = 0;
    for (int i = 0; i < m1->rows; i++) {
        for (int j = 0; j < m1->columns; j++) {
            resarray[resarrayiterator] = m1->m[i][j] * num;
            resarrayiterator++;
        }
    }
    floatMatrix *res = malloc(sizeof(res));
    newFloatMatrix(res, m1->rows, m1->columns, resarray);
    return res;
}
void multiplyByFloatNumFloat(floatMatrix *m1, const float num) {
    for (int i = 0; i < m1->rows; i++) {
        for (int j = 0; j < m1->columns; j++) {
            m1->m[i][j] = m1->m[i][j] * num;
        }   
    }
}
floatMatrix *rMultiplyByFloatNumFloat(floatMatrix *m1, const float num) {
    float resarray[m1->rows * m1->columns];
    int resarrayiterator = 0;
    for (int i = 0; i < m1->rows; i++) {
        for (int j = 0; j < m1->columns; j++) {
            resarray[resarrayiterator] = m1->m[i][j] * num;
            resarrayiterator++;
        }
    }
    floatMatrix *res = malloc(sizeof(res));
    newFloatMatrix(res, m1->rows, m1->columns, resarray);
    return res;
}
void multiplyByDoubleNumFloat(floatMatrix *m1, const double num) {
    for (int i = 0; i < m1->rows; i++) {
        for (int j = 0; j < m1->columns; j++) {
            m1->m[i][j] = m1->m[i][j] * num;
        }   
    }
}
floatMatrix *rMultiplyByDoubleNumFloat(floatMatrix *m1, const double num) {
    float resarray[m1->rows * m1->columns];
    int resarrayiterator = 0;
    for (int i = 0; i < m1->rows; i++) {
        for (int j = 0; j < m1->columns; j++) {
            resarray[resarrayiterator] = m1->m[i][j] * num;
            resarrayiterator++;
        }
    }
    floatMatrix *res = malloc(sizeof(res));
    newFloatMatrix(res, m1->rows, m1->columns, resarray);
    return res;
}
void multiplyByIntNumDouble(doubleMatrix *m1, const int num) {
    for (int i = 0; i < m1->rows; i++) {
        for (int j = 0; j < m1->columns; j++) {
            m1->m[i][j] = m1->m[i][j] * num;
        }   
    }
}
doubleMatrix *rMultiplyByIntNumDouble(doubleMatrix *m1, const int num) {
    double resarray[m1->rows * m1->columns];
    int resarrayiterator = 0;
    for (int i = 0; i < m1->rows; i++) {
        for (int j = 0; j < m1->columns; j++) {
            resarray[resarrayiterator] = m1->m[i][j] * num;
            resarrayiterator++;
        }
    }
    doubleMatrix *res = malloc(sizeof(res));
    newDoubleMatrix(res, m1->rows, m1->columns, resarray);
    return res;
}
void multiplyByDoubleNumDouble(doubleMatrix *m1, const double num) {
    for (int i = 0; i < m1->rows; i++) {
        for (int j = 0; j < m1->columns; j++) {
            m1->m[i][j] = m1->m[i][j] * num;
        }   
    }
}
doubleMatrix *rMultiplyByDoubleNumDouble(doubleMatrix *m1, const double num) {
    double resarray[m1->rows * m1->columns];
    int resarrayiterator = 0;
    for (int i = 0; i < m1->rows; i++) {
        for (int j = 0; j < m1->columns; j++) {
            resarray[resarrayiterator] = m1->m[i][j] * num;
            resarrayiterator++;
        }
    }
    doubleMatrix *res = malloc(sizeof(res));
    newDoubleMatrix(res, m1->rows, m1->columns, resarray);
    return res;
}
floatMatrix *multiplyByFloatNumDouble(doubleMatrix *m1, const float num) {
    float resarray[m1->rows * m1->columns];
    int resarrayiterator = 0;
    for (int i = 0; i < m1->rows; i++) {
        for (int j = 0; j < m1->columns; j++) {
            resarray[resarrayiterator] = m1->m[i][j] * num;
            resarrayiterator++;
        }
    }
    floatMatrix *res = malloc(sizeof(res));
    newFloatMatrix(res, m1->rows, m1->columns, resarray);
    return res;
}
void multiplyByIntNumChar(charMatrix *m1, const int num) {
    for (int i = 0; i < m1->rows; i++) {
        for (int j = 0; j < m1->columns; j++) {
            m1->m[i][j] = m1->m[i][j] * num;
        }   
    }
}
charMatrix *rMultiplyByIntNumChar(charMatrix *m1, const int num) {
    char resarray[m1->rows * m1->columns];
    int resarrayiterator = 0;
    for (int i = 0; i < m1->rows; i++) {
        for (int j = 0; j < m1->columns; j++) {
            resarray[resarrayiterator] = m1->m[i][j] * num;
            resarrayiterator++;
        }
    }
    charMatrix *res = malloc(sizeof(res));
    newCharMatrix(res, m1->rows, m1->columns, resarray);
    return res;
}

intMatrix *multiplyIntMatrix(intMatrix *m1, intMatrix *m2) {
    int resarray[m1->rows * m2->columns];
    int resarrayiterator = 0;
    for (int i = 0; i < m1->rows; i++) {
        for (int j = 0; j < m2->columns; j++) {
            resarray[resarrayiterator] = 0;
            for (int k = 0; k < m1->columns; k++) {
                resarray[resarrayiterator] += m1->m[i][k] * m2->m[k][j];
            }
            resarrayiterator++;
        }
    }
    intMatrix *res = malloc(sizeof(res));
    newIntMatrix(res, m1->rows, m2->columns, resarray);
    return res;
}
floatMatrix *multiplyIntWithFloatMatrix(intMatrix *m1, floatMatrix *m2) {
    float resarray[m1->rows * m2->columns];
    int resarrayiterator = 0;
    for (int i = 0; i < m1->rows; i++) {
        for (int j = 0; j < m2->columns; j++) {
            resarray[resarrayiterator] = 0;
            for (int k = 0; k < m1->columns; k++) {
                resarray[resarrayiterator] += m1->m[i][k] * m2->m[k][j];
            }
            resarrayiterator++;
        }
    }
    floatMatrix *res = malloc(sizeof(res));
    newFloatMatrix(res, m1->rows, m2->columns, resarray);
    return res;
}
doubleMatrix *multiplyIntWithDoubleMatrix(intMatrix *m1, doubleMatrix *m2) {
    double resarray[m1->rows * m2->columns];
    int resarrayiterator = 0;
    for (int i = 0; i < m1->rows; i++) {
        for (int j = 0; j < m2->columns; j++) {
            resarray[resarrayiterator] = 0;
            for (int k = 0; k < m1->columns; k++) {
                resarray[resarrayiterator] += m1->m[i][k] * m2->m[k][j];
            }
            resarrayiterator++;
        }
    }
    doubleMatrix *res = malloc(sizeof(res));
    newDoubleMatrix(res, m1->rows, m2->columns, resarray);
    return res;
}
charMatrix *multiplyIntWithCharMatrix(intMatrix *m1, charMatrix *m2) {
    char resarray[m1->rows * m2->columns];
    int resarrayiterator = 0;
    for (int i = 0; i < m1->rows; i++) {
        for (int j = 0; j < m2->columns; j++) {
            resarray[resarrayiterator] = 0;
            for (int k = 0; k < m1->columns; k++) {
                resarray[resarrayiterator] += m1->m[i][k] * m2->m[k][j];
            }
            resarrayiterator++;
        }
    }
    charMatrix *res = malloc(sizeof(res));
    newCharMatrix(res, m1->rows, m2->columns, resarray);
    return res;
}
floatMatrix *multiplyFloatMatrix(floatMatrix *m1, floatMatrix *m2) {
    float resarray[m1->rows * m2->columns];
    int resarrayiterator = 0;
    for (int i = 0; i < m1->rows; i++) {
        for (int j = 0; j < m2->columns; j++) {
            resarray[resarrayiterator] = 0;
            for (int k = 0; k < m1->columns; k++) {
                resarray[resarrayiterator] += m1->m[i][k] * m2->m[k][j];
            }
            resarrayiterator++;
        }
    }
    floatMatrix *res = malloc(sizeof(res));
    newFloatMatrix(res, m1->rows, m2->columns, resarray);
    return res;
}
floatMatrix *multiplyFloatWithIntMatrix(floatMatrix *m1, intMatrix *m2) {
     float resarray[m1->rows * m2->columns];
    int resarrayiterator = 0;
    for (int i = 0; i < m1->rows; i++) {
        for (int j = 0; j < m2->columns; j++) {
            resarray[resarrayiterator] = 0;
            for (int k = 0; k < m1->columns; k++) {
                resarray[resarrayiterator] += m1->m[i][k] * m2->m[k][j];
            }
            resarrayiterator++;
        }
    }
    floatMatrix *res = malloc(sizeof(res));
    newFloatMatrix(res, m1->rows, m2->columns, resarray);
    return res;
}
floatMatrix *multiplyFloatWithDoubleMatrix(floatMatrix *m1, doubleMatrix *m2) {
    float resarray[m1->rows * m2->columns];
    int resarrayiterator = 0;
    for (int i = 0; i < m1->rows; i++) {
        for (int j = 0; j < m2->columns; j++) {
            resarray[resarrayiterator] = 0;
            for (int k = 0; k < m1->columns; k++) {
                resarray[resarrayiterator] += m1->m[i][k] * m2->m[k][j];
            }
            resarrayiterator++;
        }
    }
    floatMatrix *res = malloc(sizeof(res));
    newFloatMatrix(res, m1->rows, m2->columns, resarray);
    return res;
}
doubleMatrix *multiplyDoubleMatrix(doubleMatrix *m1, doubleMatrix *m2) {
    double resarray[m1->rows * m2->columns];
    int resarrayiterator = 0;
    for (int i = 0; i < m1->rows; i++) {
        for (int j = 0; j < m2->columns; j++) {
            resarray[resarrayiterator] = 0;
            for (int k = 0; k < m1->columns; k++) {
                resarray[resarrayiterator] += m1->m[i][k] * m2->m[k][j];
            }
            resarrayiterator++;
        }
    }
    doubleMatrix *res = malloc(sizeof(res));
    newDoubleMatrix(res, m1->rows, m2->columns, resarray);
    return res;
}
doubleMatrix *multiplyDoubleWithIntMatrix(doubleMatrix *m1, intMatrix *m2) {
    double resarray[m1->rows * m2->columns];
    int resarrayiterator = 0;
    for (int i = 0; i < m1->rows; i++) {
        for (int j = 0; j < m2->columns; j++) {
            resarray[resarrayiterator] = 0;
            for (int k = 0; k < m1->columns; k++) {
                resarray[resarrayiterator] += m1->m[i][k] * m2->m[k][j];
            }
            resarrayiterator++;
        }
    }
    doubleMatrix *res = malloc(sizeof(res));
    newDoubleMatrix(res, m1->rows, m2->columns, resarray);
    return res;
}
floatMatrix *multiplyDoubleWithFloatMatrix(doubleMatrix *m1, floatMatrix *m2) {
    float resarray[m1->rows * m2->columns];
    int resarrayiterator = 0;
    for (int i = 0; i < m1->rows; i++) {
        for (int j = 0; j < m2->columns; j++) {
            resarray[resarrayiterator] = 0;
            for (int k = 0; k < m1->columns; k++) {
                resarray[resarrayiterator] += m1->m[i][k] * m2->m[k][j];
            }
            resarrayiterator++;
        }
    }
    floatMatrix *res = malloc(sizeof(res));
    newFloatMatrix(res, m1->rows, m2->columns, resarray);
    return res;
}
charMatrix *multiplyCharMatrix(charMatrix *m1, charMatrix *m2) {
    char resarray[m1->rows * m2->columns];
    int resarrayiterator = 0;
    for (int i = 0; i < m1->rows; i++) {
        for (int j = 0; j < m2->columns; j++) {
            resarray[resarrayiterator] = 0;
            for (int k = 0; k < m1->columns; k++) {
                resarray[resarrayiterator] += m1->m[i][k] * m2->m[k][j];
            }
            resarrayiterator++;
        }
    }
    charMatrix *res = malloc(sizeof(res));
    newCharMatrix(res, m1->rows, m2->columns, resarray);
    return res;
}
// ----------------------------------------------------------------

// ---------------- copy functions ------------------
intMatrix *copyIntMatrix(intMatrix *m1) {
    int resarray[m1->rows * m1->columns];
    int resarrayiterator = 0;
    for (int i = 0; i < m1->rows; i++) {
        for (int j = 0; j < m1->columns; j++) {
            resarray[resarrayiterator] = m1->m[i][j];
            resarrayiterator++;
        }
    }
    intMatrix *res = malloc(sizeof(res));
    newIntMatrix(res, m1->rows, m1->columns, resarray);
    return res;
}
floatMatrix *copyFloatMatrix(floatMatrix *m1) {
    float resarray[m1->rows * m1->columns];
    int resarrayiterator = 0;
    for (int i = 0; i < m1->rows; i++) {
        for (int j = 0; j < m1->columns; j++) {
            resarray[resarrayiterator] = m1->m[i][j];
            resarrayiterator++;
        }
    }
    floatMatrix *res = malloc(sizeof(res));
    newFloatMatrix(res, m1->rows, m1->columns, resarray);
    return res;
}
doubleMatrix *copyDoubleMatrix(doubleMatrix *m1) {
    double resarray[m1->rows * m1->columns];
    int resarrayiterator = 0;
    for (int i = 0; i < m1->rows; i++) {
        for (int j = 0; j < m1->columns; j++) {
            resarray[resarrayiterator] = m1->m[i][j];
            resarrayiterator++;
        }
    }
    doubleMatrix *res = malloc(sizeof(res));
    newDoubleMatrix(res, m1->rows, m1->columns, resarray);
    return res;
}
charMatrix *copyCharMatrix(charMatrix *m1) {
    char resarray[m1->rows * m1->columns];
    int resarrayiterator = 0;
    for (int i = 0; i < m1->rows; i++) {
        for (int j = 0; j < m1->columns; j++) {
            resarray[resarrayiterator] = m1->m[i][j];
            resarrayiterator++;
        }
    }
    charMatrix *res = malloc(sizeof(res));
    newCharMatrix(res, m1->rows, m1->columns, resarray);
    return res;
}
// --------------------------------------------------

// -------------- get value functions ----------------
int getValueFromInt(intMatrix *m1, const int row, const int column) {
    return m1->m[row][column];
}
float getValueFromFloat(floatMatrix *m1, const int row, const int column) {
    return m1->m[row][column];
}
double getValueFromDouble(doubleMatrix *m1, const int row, const int column) {
    return m1->m[row][column];
}
char getValueFromchar(charMatrix *m1, const int row, const int column) {
    return m1->m[row][column];
}
// ---------------------------------------------------

// ----------------- set value functions ------------------------------
void setValueToInt(intMatrix *m1, const int row, const int column, int value) {
    m1->m[row][column] = value;
}
void setValueToFloat(floatMatrix *m1, const int row, const int column, float value) {
    m1->m[row][column] = value;
}
void setValueToDouble(doubleMatrix *m1, const int row, const int column, double value) {
    m1->m[row][column] = value;
}
void setValueToChar(charMatrix *m1, const int row, const int column, char value) {
    m1->m[row][column] = value;
}
// --------------------------------------------------------------------

// --------------------- transform functions ---------------------
intMatrix *transformFromFloatToInt(floatMatrix *m1) {
    int resarray[m1->rows * m1->columns];
    int resarrayiterator = 0;
    for (int i = 0; i < m1->rows; i++) {
        for (int j = 0; j < m1->columns; j++) {
            resarray[resarrayiterator] = m1->m[i][j];
            resarrayiterator++;
        }
    }
    intMatrix *res = malloc(sizeof(res));
    newIntMatrix(res, m1->rows, m1->columns, resarray);
    return res;
}
intMatrix *transformFromDoubleToInt(doubleMatrix *m1) {
    int resarray[m1->rows * m1->columns];
    int resarrayiterator = 0;
    for (int i = 0; i < m1->rows; i++) {
        for (int j = 0; j < m1->columns; j++) {
            resarray[resarrayiterator] = m1->m[i][j];
            resarrayiterator++;
        }
    }
    intMatrix *res = malloc(sizeof(res));
    newIntMatrix(res, m1->rows, m1->columns, resarray);
    return res;
}
intMatrix *transformFromCharToInt(charMatrix *m1) {
    int resarray[m1->rows * m1->columns];
    int resarrayiterator = 0;
    for (int i = 0; i < m1->rows; i++) {
        for (int j = 0; j < m1->columns; j++) {
            resarray[resarrayiterator] = m1->m[i][j];
            resarrayiterator++;
        }
    }
    intMatrix *res = malloc(sizeof(res));
    newIntMatrix(res, m1->rows, m1->columns, resarray);
    return res;
}
floatMatrix *transformFromIntToFloat(intMatrix *m1) {
    float resarray[m1->rows * m1->columns];
    int resarrayiterator = 0;
    for (int i = 0; i < m1->rows; i++) {
        for (int j = 0; j < m1->columns; j++) {
            resarray[resarrayiterator] = m1->m[i][j];
            resarrayiterator++;
        }
    }
    floatMatrix *res = malloc(sizeof(res));
    newFloatMatrix(res, m1->rows, m1->columns, resarray);
    return res;
}
floatMatrix *transformFromDoubleToFloat(doubleMatrix *m1) {
    float resarray[m1->rows * m1->columns];
    int resarrayiterator = 0;
    for (int i = 0; i < m1->rows; i++) {
        for (int j = 0; j < m1->columns; j++) {
            resarray[resarrayiterator] = m1->m[i][j];
            resarrayiterator++;
        }
    }
    floatMatrix *res = malloc(sizeof(res));
    newFloatMatrix(res, m1->rows, m1->columns, resarray);
    return res;
}
floatMatrix *transformFromCharToFloat(charMatrix *m1) {
    float resarray[m1->rows * m1->columns];
    int resarrayiterator = 0;
    for (int i = 0; i < m1->rows; i++) {
        for (int j = 0; j < m1->columns; j++) {
            resarray[resarrayiterator] = m1->m[i][j];
            resarrayiterator++;
        }
    }
    floatMatrix *res = malloc(sizeof(res));
    newFloatMatrix(res, m1->rows, m1->columns, resarray);
    return res;
}
doubleMatrix *transformFromIntToDouble(intMatrix *m1) {
    double resarray[m1->rows * m1->columns];
    int resarrayiterator = 0;
    for (int i = 0; i < m1->rows; i++) {
        for (int j = 0; j < m1->columns; j++) {
            resarray[resarrayiterator] = m1->m[i][j];
            resarrayiterator++;
        }
    }
    doubleMatrix *res = malloc(sizeof(res));
    newDoubleMatrix(res, m1->rows, m1->columns, resarray);
    return res;
}
doubleMatrix *transformFromFloatToDouble(floatMatrix *m1) {
    double resarray[m1->rows * m1->columns];
    int resarrayiterator = 0;
    for (int i = 0; i < m1->rows; i++) {
        for (int j = 0; j < m1->columns; j++) {
            resarray[resarrayiterator] = m1->m[i][j];
            resarrayiterator++;
        }
    }
    doubleMatrix *res = malloc(sizeof(res));
    newDoubleMatrix(res, m1->rows, m1->columns, resarray);
    return res;
}
doubleMatrix *transformFromCharToDouble(charMatrix *m1) {
    double resarray[m1->rows * m1->columns];
    int resarrayiterator = 0;
    for (int i = 0; i < m1->rows; i++) {
        for (int j = 0; j < m1->columns; j++) {
            resarray[resarrayiterator] = m1->m[i][j];
            resarrayiterator++;
        }
    }
    doubleMatrix *res = malloc(sizeof(res));
    newDoubleMatrix(res, m1->rows, m1->columns, resarray);
    return res;
}
charMatrix *transformFromIntToChar(intMatrix *m1) {
    char resarray[m1->rows * m1->columns];
    int resarrayiterator = 0;
    for (int i = 0; i < m1->rows; i++) {
        for (int j = 0; j < m1->columns; j++) {
            resarray[resarrayiterator] = m1->m[i][j];
            resarrayiterator++;
        }
    }
    charMatrix *res = malloc(sizeof(res));
    newCharMatrix(res, m1->rows, m1->columns, resarray);
    return res;
}
// ---------------------------------------------------------------

// ------------------- to array functions ------------------------
int *toArrayInt(intMatrix *m1) {
    int *res = malloc(sizeof(int) * (m1->rows * m1->columns));
    int resarrayiterator = 0;
    for (int i = 0; i < m1->rows; i++) {
        for (int j = 0; j < m1->columns; j++) {
            res[resarrayiterator] = m1->m[i][j];
            resarrayiterator++;
        }
    }
    return res;
}
float *toFloatArrayInt(intMatrix *m1) {
    float *res = malloc(sizeof(float) * (m1->rows * m1->columns));
    int resarrayiterator = 0;
    for (int i = 0; i < m1->rows; i++) {
        for (int j = 0; j < m1->columns; j++) {
            res[resarrayiterator] = m1->m[i][j];
            resarrayiterator++;
        }
    }
    return res;
}
double *toDoubleArrayInt(intMatrix *m1) {
    double *res = malloc(sizeof(double) * (m1->rows * m1->columns));
    int resarrayiterator = 0;
    for (int i = 0; i < m1->rows; i++) {
        for (int j = 0; j < m1->columns; j++) {
            res[resarrayiterator] = m1->m[i][j];
            resarrayiterator++;
        }
    }
    return res;
}
char *toCharArrayInt(intMatrix *m1) {
    char *res = malloc(sizeof(char) * (m1->rows * m1->columns));
    int resarrayiterator = 0;
    for (int i = 0; i < m1->rows; i++) {
        for (int j = 0; j < m1->columns; j++) {
            res[resarrayiterator] = m1->m[i][j];
            resarrayiterator++;
        }
    }
    return res;
}
float *toArrayFloat(floatMatrix *m1) {
    float *res = malloc(sizeof(float) * (m1->rows * m1->columns));
    int resarrayiterator = 0;
    for (int i = 0; i < m1->rows; i++) {
        for (int j = 0; j < m1->columns; j++) {
            res[resarrayiterator] = m1->m[i][j];
            resarrayiterator++;
        }
    }
    return res;
}
int *toIntArrayFloat(floatMatrix *m1) {
    int *res = malloc(sizeof(int) * (m1->rows * m1->columns));
    int resarrayiterator = 0;
    for (int i = 0; i < m1->rows; i++) {
        for (int j = 0; j < m1->columns; j++) {
            res[resarrayiterator] = m1->m[i][j];
            resarrayiterator++;
        }
    }
    return res;
}
double *toDoubleArrayFloat(floatMatrix *m1) {
    double *res = malloc(sizeof(double) * (m1->rows * m1->columns));
    int resarrayiterator = 0;
    for (int i = 0; i < m1->rows; i++) {
        for (int j = 0; j < m1->columns; j++) {
            res[resarrayiterator] = m1->m[i][j];
            resarrayiterator++;
        }
    }
    return res;
}
double *toArrayDouble(doubleMatrix *m1) {
    double *res = malloc(sizeof(double) * (m1->rows * m1->columns));
    int resarrayiterator = 0;
    for (int i = 0; i < m1->rows; i++) {
        for (int j = 0; j < m1->columns; j++) {
            res[resarrayiterator] = m1->m[i][j];
            resarrayiterator++;
        }
    }
    return res;
}
int *toIntArrayDouble(doubleMatrix *m1) {
    int *res = malloc(sizeof(int) * (m1->rows * m1->columns));
    int resarrayiterator = 0;
    for (int i = 0; i < m1->rows; i++) {
        for (int j = 0; j < m1->columns; j++) {
            res[resarrayiterator] = m1->m[i][j];
            resarrayiterator++;
        }
    }
    return res;
}
float *toFloatArrayDouble(doubleMatrix *m1) {
    float *res = malloc(sizeof(float) * (m1->rows * m1->columns));
    int resarrayiterator = 0;
    for (int i = 0; i < m1->rows; i++) {
        for (int j = 0; j < m1->columns; j++) {
            res[resarrayiterator] = m1->m[i][j];
            resarrayiterator++;
        }
    }
    return res;
}
char *toArrayChar(charMatrix *m1) {
    char *res = malloc(sizeof(char) * (m1->rows * m1->columns));
    int resarrayiterator = 0;
    for (int i = 0; i < m1->rows; i++) {
        for (int j = 0; j < m1->columns; j++) {
            res[resarrayiterator] = m1->m[i][j];
            resarrayiterator++;
        }
    }
    return res;
}
int *toIntArrayChar(charMatrix *m1) {
    int *res = malloc(sizeof(int) * (m1->rows * m1->columns));
    int resarrayiterator = 0;
    for (int i = 0; i < m1->rows; i++) {
        for (int j = 0; j < m1->columns; j++) {
            res[resarrayiterator] = m1->m[i][j];
            resarrayiterator++;
        }
    }
    return res;
}
// ---------------------------------------------------------------

#endif // MATRIX_H