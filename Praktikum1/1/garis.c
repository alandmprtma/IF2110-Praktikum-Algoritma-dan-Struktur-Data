#include <stdio.h>
#include <math.h>
#include "garis.h"

void CreateGaris (GARIS * L, POINT P1, POINT P2)
{
    PAwal(*L) = P1;
    PAkhir(*L) = P2; 
}

void BacaGARIS (GARIS * L)
{
    POINT p1, p2;
    BacaPOINT(&p1);
    BacaPOINT(&p2);
    while (EQ(p1,p2))
    {
        printf("Garis tidak valid\n");
        BacaPOINT(&p1);
        BacaPOINT(&p2);
    }
    CreateGaris(L, p1, p2);
}

void TulisGARIS (GARIS L)
{
    float x1,y1,x2,y2;
    x1 = Absis(PAwal(L));
    y1 = Ordinat(PAwal(L));
    x2 = Absis(PAkhir(L));
    y2 = Ordinat(PAkhir(L));
    printf("((%.2f,%.2f),(%.2f,%.2f))",x1, y1, x2, y2);
}

float PanjangGARIS (GARIS L)
{
    return  Panjang(PAwal(L), PAkhir(L));
}

float Gradien (GARIS L)
{
    return (Ordinat(PAkhir(L))-Ordinat(PAwal(L))) / (float) (Absis(PAkhir(L))-Absis(PAwal(L)));
}

void GeserGARIS (GARIS * L, float deltaX, float deltaY)
{
    Absis(PAwal(*L)) = Absis(PAwal(*L)) + deltaX;
    Absis(PAkhir(*L)) = Absis(PAkhir(*L)) + deltaX;
    Ordinat(PAwal(*L)) = Ordinat(PAwal(*L)) + deltaY;
    Ordinat(PAkhir(*L)) = Ordinat(PAkhir(*L)) + deltaY;
}

boolean IsTegakLurus (GARIS L1, GARIS L2)
{
    return (Gradien(L1)*Gradien(L2) == -1);
}

boolean IsSejajar (GARIS L1, GARIS L2)
{
    return(Gradien(L1) == Gradien(L2));
}

float JarakGARIS (GARIS L, POINT P)
{
    float a, b, c, d;
    a = (Ordinat(PAkhir(L)) - Ordinat(PAwal(L)));
    b = Absis(PAkhir(L)) - Absis(PAwal(L));
    c = (-Ordinat(PAwal(L))) * (b) + Absis(PAwal(L)) * (Ordinat(PAkhir(L)) - Ordinat(PAwal(L)));
    d = fabs(-(a)*Absis(P) + b * Ordinat(P) + c) / sqrt(a * a + b * b);

    return d;
}

boolean IsPointMemenuhiGaris (GARIS L, POINT P)
{
    float a, b, c;
    a = (Ordinat(PAkhir(L)) - Ordinat(PAwal(L)));
    b = Absis(PAkhir(L)) - Absis(PAwal(L));
    c = (-Ordinat(PAwal(L))) * (b) + Absis(PAwal(L)) * (Ordinat(PAkhir(L)) - Ordinat(PAwal(L)));
    return (-(a)*Absis(P) + b * Ordinat(P) + c == 0);
}
