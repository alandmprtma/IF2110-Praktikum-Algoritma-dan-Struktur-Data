#include <stdio.h>
#include "matrix.h"

int main() {
    /* KAMUS */
    int m, n;
    Matrix m1, m2, temp;

    /* ALGORITMA */
    scanf("%d %d", &m, &n);
    readMatrix(&m1, m, n);
    printf("\n");

    scanf("%d %d", &m, &n);
    readMatrix(&m2, m, n);
    printf("\n");

    if (isMatrixEqual(m1, m2)) {
        printf("M1 = M2\n");
        printf("\n");
    }

    if (isMatrixNotEqual(m1,m2)){
        printf("M1 != M2\n");
        printf("\n");
    }

    if (isIdentity(m1)) {
        printf("M1 adalah matriks identitas\n");
        printf("\n");
    }

    if (isIdentity(m2)) {
        printf("M2 adalah matriks identitas\n");
        printf("\n");
    }

    if (isSparse(m1)) {
        printf("M1 adalah matriks sparse\n");
        printf("\n");
    }

    if (isSparse(m2)) {
        printf("M2 adalah matriks sparse\n");
        printf("\n");
    }

    if (isSymmetric(m1)) {
        printf("M1 adalah matriks simetrik\n");
        printf("\n");
    }

    if (isSymmetric(m2)) {
        printf("M2 adalah matriks simetrik\n");
        printf("\n");
    }

    if (isSquare(m1)) {
        printf("Transpose M1 =\n");
        copyMatrix(m1, &temp);
        pTranspose(&temp);
        displayMatrix(temp);
        printf("\n\n");

        printf("Determinan M1 = %.2f\n", determinant(m1));
        printf("\n");
    }

    if (isSquare(m2)) {
        printf("Transpose M2 =\n");
        copyMatrix(m2, &temp);
        Matrix hasil;
        hasil = transpose(temp);
        displayMatrix(hasil);
        printf("\n\n");

        printf("Determinan M2 = %.2f\n", determinant(m2));
        printf("\n");
    }

    if (isMatrixSizeEqual(m1, m2)) {
        printf("M1 + M2 =\n");
        displayMatrix(addMatrix(m1, m2));
        printf("\n\n");

        printf("M1 - M2 =\n");
        displayMatrix(subtractMatrix(m1, m2));
        printf("\n\n");
    }

    if (COL_EFF(m1) == ROW_EFF(m2)) {
        printf("M1 x M2 =\n");
        displayMatrix(multiplyMatrix(m1, m2));
        printf("\n\n");
    }
    printf("Negasi M1 =\n");
    displayMatrix(negation(m1));
    printf("\n\n");

    printf("Negasi M2 =\n");
    copyMatrix(m2, &temp);
    pNegation(&temp);
    displayMatrix(temp);
    printf("\n\n");
}