#ifndef MATRIX_H
#define MATRIX_H

// ---------------- structures -------------------
typedef struct intMatrix intMatrix;
typedef struct floatMatrix floatMatrix;
typedef struct doubleMatrix doubleMatrix;
typedef struct charMatrix charMatrix;
// -------------------------------------------------

// ------------------------ create functions ---------------------------------------------------
void newIntMatrix(intMatrix *m1, const int rows, const int columns, int *matrixArray);
void newFloatMatrix(floatMatrix *m1, const int rows, const int columns, float *matrixArray);
void newDoubleMatrix(doubleMatrix *m1, const int rows, const int columns, double *matrixArray);
void newCharMatrix(charMatrix *m1, const int rows, const int columns, char *matrixArray);
// ---------------------------------------------------------------------------------------------

// ------------ print functions ------------
void printIntMatrix(intMatrix *m1);
void printFloatMatrix(floatMatrix *m1);
void printDoubleMatrix(doubleMatrix *m1);
void printCharMatrix(charMatrix *m1);
// -----------------------------------------

// ------- free(delete) functions ---------
void freeIntMatrix(intMatrix *m1);
void freeFloatMatrix(floatMatrix *m1);
void freeDoubleMatrix(doubleMatrix *m1);
void freeCharMatrix(charMatrix *m1);
// ----------------------------------------

// ------- add functions ------------------
void addIntMatrix(intMatrix *m1, intMatrix *m2);
floatMatrix *addToIntFloat(intMatrix *m1, floatMatrix *m2);
doubleMatrix *addToIntDouble(intMatrix *m1, doubleMatrix *m2);
charMatrix *addToIntChar(intMatrix *m1, charMatrix *m2);
void addFloatMatrix(floatMatrix *m1, floatMatrix *m2);
void addToFloatInt(floatMatrix *m1, intMatrix *m2);
floatMatrix *rAddToFloatInt(floatMatrix *m1, intMatrix *m2);
void addToFloatDouble(floatMatrix *m1, doubleMatrix *m2);
floatMatrix *rAddToFloatDouble(floatMatrix *m1, doubleMatrix *m2);
void addDoubleMatrix(doubleMatrix *m1, doubleMatrix *m2);
void addToDoubleInt(doubleMatrix *m1, intMatrix *m2);
doubleMatrix *rAddToDoubleInt(doubleMatrix *m1, intMatrix *m2);
floatMatrix *addToDoubleFloat(doubleMatrix *m1, floatMatrix *m2);
void addCharMatrix(charMatrix *m1, charMatrix *m2);
// ----------------------------------------

// ----------- sub functions ----------------------------
void subIntMatrix(intMatrix *m1, intMatrix *m2);
floatMatrix *subFromIntFloat(intMatrix *m1, floatMatrix *m2);
doubleMatrix *subFromIntDouble(intMatrix *m1, doubleMatrix *m2);
charMatrix *subFromIntChar(intMatrix *m1, charMatrix *m2);
void subFloatMatrix(floatMatrix *m1, floatMatrix *m2);
void subFromFloatInt(floatMatrix *m1, intMatrix *m2);
floatMatrix *rSubFromFloatInt(floatMatrix *m1, intMatrix *m2);
void subFromFloatDouble(floatMatrix *m1, doubleMatrix *m2);
floatMatrix *rSubFromFloatDouble(floatMatrix *m1, doubleMatrix *m2);
void subDoubleMatrix(doubleMatrix *m1, doubleMatrix *m2);
void subFromDoubleInt(doubleMatrix *m1, intMatrix *m2);
doubleMatrix *rSubFromDoubleInt(doubleMatrix *m1, intMatrix *m2);
floatMatrix *subFromDoubleFloat(doubleMatrix *m1, floatMatrix *m2);
void subCharMatrix(charMatrix *m1, charMatrix *m2);
// ------------------------------------------------------

#endif // MATRIX_H