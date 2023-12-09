#ifndef MATRIXOP_H
#define MATRIXOP_H

#include "matrix.h"

float rowMean (Matrix m, IdxType i);

float colMean (Matrix m, IdxType j);

void rowExtremes (Matrix m, IdxType i, ElType *max, ElType *min);

void colExtremes (Matrix m, IdxType j, ElType *max, ElType *min);

int countValOnRow (Matrix m, IdxType i, ElType val);

int countValOnCol (Matrix m, IdxType j, ElType val);

#endif