/* File: garis.h */
/* Tanggal: 28 Agustus 2016 */
/* Definisi ADT GARIS, menggunakan ADT point */

/* *** ADT LAIN YANG DIPAKAI *** */
#include <stdio.h>
#include "garis.h"
        
/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */ 
/* ***************************************************************** */
/* *** Konstruktor membentuk GARIS *** */
void MakeGARIS (POINT P1, POINT P2, GARIS * L)
/* I.S. P1 dan P2 terdefinisi */
/* F.S. L terdefinisi dengan L.PAw = P1 dan L.PAkh = P2 */
{
    PAwal(*L) = P1;
    PAkhir(*L) = P2;
}

void BacaGARIS (GARIS * L)
/* I.S. sembarang */
/* F.S. L terdefinisi sebagai GARIS yang valid */
{
    POINT P1, P2;
    BacaPOINT(&P1);
    BacaPOINT(&P2);
    MakeGARIS(P1, P2, L);
}

void TulisGARIS (GARIS L)
/* I.S. L terdefinisi */
/* F.S. L tertulis di layar dengan format "((x1,y1),(x2,y2))" */
{
    float x1,y1,x2,y2;
    x1 = Absis(PAwal(L));
    y1 = Ordinat(PAwal(L));
    x2 = Absis(PAkhir(L));
    y2 = Ordinat(PAkhir(L));
    printf("((%.2f,%.2f),(%.2f,%.2f))",x1, y1, x2, y2);
}

/* *** Kelompok operasi garis *** */
float PanjangGARIS (GARIS L) 
/* Menghitung panjang garis L : sqrt(x1 - x2)^2 + (y1 - y2)^2*/
{
    float panjang;
    panjang = Panjang(PAwal(L), PAkhir(L));
    return panjang;
}
float Gradien (GARIS L)
/* Mengembalikan Gradien (m) dari L */
/* Gradien garis yang melalui (x1,y1) dan (x2,y2) adalah: (y2-y1)/(x2-x1) */
/* Prekondisi : x1 != x2 */
{
    float grad;
    grad = (Ordinat(PAkhir(L))-Ordinat(PAwal(L)))/(Absis(PAkhir(L))-Absis(PAkhir(L)));
    return grad;
}
void GeserGARIS (GARIS * L, float deltaX, float deltaY)
/* I.S. L terdefinisi */
/* F.S. L digeser sebesar deltaX ke arah sumbu X dan sebesar deltaY ke arah sumbu Y */
{
    Absis(PAwal(*L)) = Absis(PAwal(*L)) + deltaX;
    Absis(PAkhir(*L)) = Absis(PAkhir(*L)) + deltaX;
    Ordinat(PAwal(*L)) = Ordinat(PAwal(*L)) + deltaY;
    Ordinat(PAkhir(*L)) = Ordinat(PAkhir(*L)) + deltaY;
}

/* *** Kelompok predikat *** */
boolean IsTegakLurus (GARIS L1, GARIS L2)
/* Menghasilkan true jika L1 tegak lurus terhadap L2 */
/* Dua garis saling tegak lurus jika hasil perkalian kedua gradiennya = -1 */

{
    return (Gradien(L1)*Gradien(L2) == -1);
}

boolean IsSejajar (GARIS L1, GARIS L2)
/* Menghasilkan true jika L "sejajar" terhadap L1 */
/* Dua garis saling sejajar jika memiliki gradien yang sama */
{
    return ((int)Gradien(L1) == (int)Gradien(L2));
}

int main()
{
    GARIS L1, L2;
    BacaGARIS(&L1);
    BacaGARIS(&L2);
    printf("%f", Gradien(L1)*Gradien(L2));
    if (IsTegakLurus(L1, L2))
    {
        printf("true");
    }
}