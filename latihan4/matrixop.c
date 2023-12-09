#include <stdio.h>
#include "matrixop.h"

float rowMean (Matrix m, IdxType i)
{
    int j;
    int sum = 0;
    for (j = 0; i <= getLastIdxCol(m); j++)
    {
        sum = sum + ELMT(m,i,j);
    }
    float mean = sum/(getLastIdxCol(m)+1);
    return mean;
}

float colMean (Matrix m, IdxType j)
{
    int i;
    int sum = 0;
    for (i = 0; i <= getLastIdxRow(m); i++)
    {
        sum = sum + ELMT(m,i,j);
    }
    float mean = sum/(getLastIdxRow(m)+1);
    return mean;
}

void rowExtremes (Matrix m, IdxType i, ElType *max, ElType *min)
{
    int j;
    *max = ELMT(m,i,0);
    *min = ELMT(m,i,0);
    for (j = 1; j <= getLastIdxCol(m); j++)
    {
        if (ELMT(m,i,j) > *max)
        {
            *max = ELMT(m,i,j);
        }
        if (ELMT(m,i,j) < *min)
        {
            *min = ELMT(m,i,j);
        }
    }   
}

void colExtremes (Matrix m, IdxType j, ElType *max, ElType *min)
{
    int i;
    *max = ELMT(m,0,j);
    *min = ELMT(m,0,j);
    for (i = 1; i <= getLastIdxRow(m); i++)
    {
        if (ELMT(m,i,j) > *max)
        {
            *max = ELMT(m,i,j);
        }
        if (ELMT(m,i,j) < *min)
        {
            *min = ELMT(m,i,j);
        }
    }   
}

int countValOnRow (Matrix m, IdxType i, ElType val)
{
    int count = 0;
    int j;
    for (j = 1; j <= getLastIdxCol(m); j++)
    {
        if (ELMT(m,i,j) == val)
        {
            count++;
        }
    }
    return count;
}

int countValOnCol (Matrix m, IdxType j, ElType val)
{
    int count = 0;
    int i;
    for (i = 1; i <= getLastIdxCol(m); i++)
    {
        if (ELMT(m,i,j) == val)
        {
            count++;
        }
    }
    return count;
}