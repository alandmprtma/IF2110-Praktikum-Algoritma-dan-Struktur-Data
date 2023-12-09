#include <stdio.h>
#include "matrix.h"

void createMatrix(int nRows, int nCols, Matrix *m)
/* Membentuk sebuah Matrix "kosong" yang siap diisi berukuran nRow x nCol di "ujung kiri" memori */
/* I.S. nRow dan nCol adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks m sesuai dengan definisi di atas terbentuk */
{
    ROW_EFF(*m) = nRows;
    COL_EFF(*m) = nCols;
}

boolean isMatrixIdxValid(int i, int j)
/* Mengirimkan true jika i, j adalah index yang valid untuk matriks apa pun */
{
    return (i >= 0 && i < ROW_CAP && j >= 0 && j < COL_CAP);
}

IdxType getLastIdxRow(Matrix m)
/* Mengirimkan Index baris terbesar m */
{
    return (IdxType) ROW_EFF(m)-1;
}

IdxType getLastIdxCol(Matrix m)
/* Mengirimkan Index kolom terbesar m */
{
    return (IdxType) COL_EFF(m)-1;
}

boolean isIdxEff(Matrix m, IdxType i, IdxType j)
/* Mengirimkan true jika i, j adalah Index efektif bagi m */
{
    return (i >= 0 && i < ROW_EFF(m) && j >= 0 && j < COL_EFF(m));
}

ElType getElmtDiagonal(Matrix m, IdxType i)
/* Mengirimkan elemen m(i,i) */
{
    return ELMT(m, i, i);
}

void copyMatrix(Matrix mIn, Matrix *mOut)
/* Melakukan assignment mOut <- mIn */
{
    int i, j;
    createMatrix(ROW_EFF(mIn), COL_EFF(mIn), mOut);

    for (i = 0; i <= getLastIdxRow(mIn); i++)
    {
        for (j = 0; j <= getLastIdxCol(mIn); j++)
        {
            ELMT(*mOut,i,j) = ELMT(mIn,i,j);
        }
    }
}

void readMatrix(Matrix *m, int nRow, int nCol)
/* I.S. isIdxValid(nRow,nCol) */
/* F.S. m terdefinisi nilai elemen efektifnya, berukuran nRow x nCol */
/* Proses: Melakukan CreateMatrix(m,nRow,nCol) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika nRow = 3 dan nCol = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10 
*/
{
    IdxType i, j;

    createMatrix(nRow, nCol, m);
    
    for (i = 0; i < nRow; i++)
    {
        for (j = 0; j < nCol; j++)
        {
            scanf("%d", &ELMT(*m,i,j));
        }
    }
}

void displayMatrix(Matrix m)
/* I.S. m terdefinisi */
/* F.S. Nilai m(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
   dipisahkan sebuah spasi. Baris terakhir tidak diakhiri dengan newline */
/* Proses: Menulis nilai setiap elemen m ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/
{
    /*KAMUS LOKAL*/
    int i, j;
    /*ALGORITMA*/

    for (i = 0; i < ROW_EFF(m); i++)
    {
        for (j = 0; j < COL_EFF(m); j++)
        {
            printf("%d", ELMT(m, i, j));
            if (j != COL_EFF(m) - 1)
            {
                printf(" ");
            }
        }
        if (i != ROW_EFF(m) - 1)
        {
            printf("\n");
        }
    }
    printf("\n");
}

Matrix addMatrix(Matrix m1, Matrix m2)
/* Prekondisi : m1 berukuran sama dengan m2 */
/* Mengirim hasil penjumlahan matriks: m1 + m2 */
{
    IdxType i, j;
    Matrix mnew;
    createMatrix(ROW_EFF(m1), COL_EFF(m1),&mnew);

    for (i = 0; i <=  getLastIdxRow(mnew); i++)
    {
        for (j = 0; j <= getLastIdxCol(mnew); j++)
        {
            ELMT(mnew,i,j) = ELMT(m1,i,j) + ELMT(m2,i,j);
        }
    }

    return mnew;
}

Matrix subtractMatrix(Matrix m1, Matrix m2)
/* Prekondisi : m1 berukuran sama dengan m2 */
/* Mengirim hasil pengurangan matriks: salinan m1 – m2 */
{
    IdxType i, j;
    Matrix mnew;
    createMatrix(ROW_EFF(m1), COL_EFF(m1),&mnew);

    for (i = 0; i <=  getLastIdxRow(mnew); i++)
    {
        for (j = 0; j <= getLastIdxCol(mnew); j++)
        {
            ELMT(mnew,i,j) = ELMT(m1,i,j) - ELMT(m2,i,j);
        }
    }

    return mnew;
}

Matrix multiplyMatrix(Matrix m1, Matrix m2)
/* Prekondisi : Ukuran kolom efektif m1 = ukuran baris efektif m2 */
/* Mengirim hasil perkalian matriks: salinan m1 * m2 */
{
    Matrix mnew;
    createMatrix(ROW_EFF(m1), COL_EFF(m2), &mnew);
    IdxType i, j, k;
    int jumlah = 0;
    for (i = 0; i <= ROW_EFF(m1); i++)
    {
        for (j = 0; j <= COL_EFF(m2); j++)
        {
            for (k = 0; k <= ROW_EFF(m2); k++)
            {
                jumlah = jumlah + ELMT(m1,i,k)*ELMT(m2,k,j);
            }
            ELMT(mnew,i,j) = jumlah;
            jumlah = 0; 
        }
    }
    return mnew;
}

Matrix multiplyMatrixWithMod(Matrix m1,Matrix m2,int mod)
/* Prekondisi : Ukuran kolom efektif m1 = ukuran baris efektif m2 */
/* Mengirim hasil perkalian matriks: salinan (m1 * m2)%mod, artinya setiap elemen matrix hasil perkalian m1 * m2 dilakukan modulo terhadap mod */
{
    Matrix mnew;
    createMatrix(ROW_EFF(m1), COL_EFF(m2), &mnew);
    IdxType i, j, k;
    int jumlah = 0;
    for (i = 0; i <= ROW_EFF(m1); i++)
    {
        for (j = 0; j <= COL_EFF(m2); j++)
        {
            for (k = 0; k <= ROW_EFF(m2); k++)
            {
                jumlah = jumlah + ELMT(m1,i,k)*ELMT(m2,k,j);
            }
            ELMT(mnew,i,j) = jumlah%mod;
            jumlah = 0; 
        }
    }
    return mnew;
}

Matrix multiplyByConst(Matrix m, ElType x)
/* Mengirim hasil perkalian setiap elemen m dengan x */
{
    IdxType i, j;
    Matrix mnew;
    createMatrix(ROW_EFF(m), COL_EFF(m),&mnew);

    for (i = 0; i <=  getLastIdxRow(mnew); i++)
    {
        for (j = 0; j <= getLastIdxCol(mnew); j++)
        {
            ELMT(mnew,i,j) = ELMT(m,i,j) * x;
        }
    }

    return mnew;
}

void pMultiplyByConst(Matrix *m, ElType k)
/* I.S. m terdefinisi, k terdefinisi */
/* F.S. Mengalikan setiap elemen m dengan k */
{
    IdxType i, j;

    for (i = 0; i <=  getLastIdxRow(*m); i++)
    {
        for (j = 0; j <= getLastIdxCol(*m); j++)
        {
            ELMT(*m,i,j) = ELMT(*m,i,j) * k;
        }
    }
}

boolean isMatrixEqual(Matrix m1, Matrix m2)
/* Mengirimkan true jika m1 = m2, yaitu count(m1) = count(m2) dan */
/* untuk setiap i,j yang merupakan Index baris dan kolom m1(i,j) = m2(i,j) */
/* Juga merupakan strong eq karena getLastIdxCol(m1) = getLastIdxCol(m2) */
{
    IdxType i,j;
    boolean hasil;

    hasil = true;
    
    if (((getLastIdxRow(m1) != getLastIdxRow(m2)) || (getLastIdxCol(m1) != getLastIdxCol(m2))))
    {
        hasil = false;
    }
    else
    {
        i = 0;
        while ((i <= getLastIdxRow(m1)) && hasil)
        {
            j = 0;
            while ((j <= getLastIdxCol(m1)) && hasil)
            {
                if (ELMT(m1,i,j) != ELMT(m2,i,j))
                {
                    hasil = false;
                }
                j++;
            }
            i++;
        }
    }
    return hasil;
}

boolean isMatrixNotEqual(Matrix m1, Matrix m2)
{
    IdxType i, j;
    boolean hasil;

    hasil = true;
    int count = 0;
    if (((getLastIdxRow(m1) != getLastIdxRow(m2)) || (getLastIdxCol(m1) != getLastIdxCol(m2))))
    {
        return true;
    }
    else
    {
        i = 0;
        while(i <= getLastIdxRow(m1))
        {
            j = 0;
            while(j <= getLastIdxCol(m1))
            {
                if (ELMT(m1,i,j) == ELMT(m2,i,j))
                {
                    count++;
                }
                j++;
            }
            i++;
        }
    }
    if (count == countElmt(m1))
    {
        hasil = false;
    }
    return hasil;
}

boolean isMatrixSizeEqual(Matrix m1, Matrix m2)
{
    return ((getLastIdxRow(m1) == getLastIdxRow(m2)) && (getLastIdxCol(m1) == getLastIdxCol(m2)));
}

int countElmt(Matrix m)
{
    return (ROW_EFF(m)*COL_EFF(m));
}

boolean isSquare(Matrix m)
/* Mengirimkan true jika m adalah matriks dg ukuran baris dan kolom sama */
{
    return (ROW_EFF(m) == COL_EFF(m));
}

boolean isSymmetric(Matrix m)
/* Mengirimkan true jika m adalah matriks simetri : isSquare(m) 
   dan untuk setiap elemen m, m(i,j)=m(j,i) */
{
    IdxType i, j;
    if (isSquare(m))
    {
        for (i = 0; i <= getLastIdxRow(m); i++)
        {
            for (j = 0; j <= getLastIdxCol(m); j++)
            {
                if (ELMT(m,i,j) != ELMT(m,j,i))
                {
                    return false;
                }
            }
        }
        return true;
    }
    else
    {
        return false;
    }
}

boolean isIdentity(Matrix m)
/* Mengirimkan true jika m adalah matriks satuan: isSquare(m) dan 
   setiap elemen diagonal m bernilai 1 dan elemen yang bukan diagonal bernilai 0 */
{
    IdxType i,j;
    boolean hasil;

    hasil = true;

    if (!isSquare(m))
    {
        hasil = false;
    }
    else{
        i = 0;
        while (i < getLastIdxRow(m) && hasil)
        {
            j = 0;
            while (j < getLastIdxCol(m) && hasil)
            {
                hasil = ((i != j) && (ELMT(m,i,j) == 0) || (i==j)&&(ELMT(m,i,j) == 1));
                j++;
            }
            i++;
        }
    }
    return hasil;
}

boolean isSparse(Matrix m)
/* Mengirimkan true jika m adalah matriks sparse: matriks “jarang” dengan definisi: 
   hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */
{
    float max = (ROW_EFF(m) * COL_EFF(m)) * 0.05;
    max = (int)max; // Round down
    int countNotZero = 0;
    int i, j;
    /*ALGORITMA*/
    for (i = 0; i < ROW_EFF(m); i++)
    {
        for (j = 0; j < COL_EFF(m); j++)
        {
            if (ELMT(m, i, j) != 0)
            {
                countNotZero++;
            }
        }
    }
    return (countNotZero <= max);
}

Matrix negation(Matrix m)
/* Menghasilkan salinan m dengan setiap elemen dinegasikan (dikalikan -1) */
{
    IdxType i, j;
    Matrix mnew;
    createMatrix(ROW_EFF(m), COL_EFF(m),&mnew);

    for (i = 0; i <=  getLastIdxRow(mnew); i++)
    {
        for (j = 0; j <= getLastIdxCol(mnew); j++)
        {
            ELMT(mnew,i,j) = ELMT(m,i,j) * (-1);
        }
    }

    return mnew;
}

void pNegation(Matrix *m)
/* I.S. m terdefinisi */
/* F.S. m di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */
{
    IdxType i, j;

    for (i = 0; i <=  getLastIdxRow(*m); i++)
    {
        for (j = 0; j <= getLastIdxCol(*m); j++)
        {
            ELMT(*m,i,j) = ELMT(*m,i,j) * (-1);
        }
    }
}

float cofactor(Matrix m, IdxType a, IdxType b)
/* Prekondisi: isSquare(m) */
/* Menghitung nilai kofaktor m pada baris i dan kolom j */
{
    /* KAMUS */
    IdxType i, j, iHasil, jHasil;
    Matrix mHasil;
    float hasil;

    /* ALGORITMA */
    hasil = 0;
    createMatrix(ROW_EFF(m) - 1, COL_EFF(m) - 1, &mHasil);

    iHasil = 0;
    for (i = 0; i <= getLastIdxRow(m); i++) {
        jHasil = 0;
        for (j = 0; j <= getLastIdxCol(m); j++) {
            if (i == a) {
                iHasil = i - 1;
            } else if (j == b) {
                jHasil = j - 1;
            } else {
                ELMT(mHasil, iHasil, jHasil) = ELMT(m, i, j);
            }
            jHasil++;
        }
        iHasil++;
    }

    if ((a + b) % 2 == 0) {
        hasil = determinant(mHasil);
    } else {
        hasil = -1 * determinant(mHasil);
    }

    return hasil;
}

float determinant(Matrix m)
/* Prekondisi: isSquare(m) */
/* Menghitung nilai determinan m */
{
    /* KAMUS */
    IdxType i, j;
    float hasil;

    /* ALGORITMA */
    hasil = 0;

    if (countElmt(m) == 1) { /* Dikarenakan matriks persegi maka tidak perlu membuat matriks baru */
        hasil = (float) ELMT(m, 0, 0);
    } else {
        i = 0;
        for (j = 0; j <= getLastIdxCol(m); j++) {
            hasil += ((float) ELMT(m, i, j)) * cofactor(m, i, j);
        }
    }

    return hasil;
}

Matrix transpose(Matrix m)
/* I.S. m terdefinisi dan IsSquare(m) */
/* F.S. menghasilkan salinan transpose dari m, yaitu setiap elemen m(i,j) ditukar nilainya dengan elemen m(j,i) */
{
    Matrix mhasil;
    int i, j;
    /*ALGORITMA*/
    createMatrix(ROW_EFF(m), COL_EFF(m), &mhasil);

    for (i = 0; i < ROW_EFF(m); i++)
    {
        for (j = 0; j < COL_EFF(m); j++)
        {
            ELMT(mhasil, j, i) = ELMT(m, i, j);
        }
    }

    return mhasil;
}

void pTranspose(Matrix *m)
/* I.S. m terdefinisi dan IsSquare(m) */
/* F.S. m "di-transpose", yaitu setiap elemen m(i,j) ditukar nilainya dengan elemen m(j,i) */
{
    Matrix mhasil;
    int i, j;
    /*ALGORITMA*/
    createMatrix(ROW_EFF(*m), COL_EFF(*m), &mhasil);

    for (i = 0; i < ROW_EFF(*m); i++)
    {
        for (j = 0; j < COL_EFF(*m); j++)
        {
            ELMT(mhasil, j, i) = ELMT(*m, i, j);
        }
    }
    *m = mhasil;
}
