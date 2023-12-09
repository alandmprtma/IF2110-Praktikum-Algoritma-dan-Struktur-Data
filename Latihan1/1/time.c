/*Nama : Aland Mulia Pratama*/
/*NIM : 13522124*/
/*Tanggal : 1 September 2023*/

#include <stdio.h>
#include "time.h"

boolean IsTIMEValid (int H, int M, int S)
{
    /*Algoritma*/
    return((H>=0 && H<24)&&(M>=0 && M<60)&&(S>=0 && S<60));
}

void CreateTime (TIME *T, int HH, int MM, int SS)
{
    /*Algoritma*/
    Hour(*T) = HH;
    Minute(*T) = MM;
    Second(*T) = SS;
}

void BacaTIME (TIME *T)
{
    /*Kamus*/
    int HH, MM, SS;
    /*Algoritma*/
    scanf("%d %d %d", &HH, &MM, &SS);
    while (!IsTIMEValid(HH,MM,SS))
    {
        printf("Jam tidak valid\n");
        scanf("%d %d %d", &HH, &MM, &SS);
    }
    CreateTime (T, HH, MM, SS);
}

void TulisTIME(TIME T)
{
    /*Algoritma*/
    printf("%02d:%02d:%02d", Hour(T), Minute(T), Second(T));
}

long TIMEToDetik (TIME T)
{
    /*Algoritma*/
    return Hour(T)*3600 + Minute(T)*60 + Second(T);
}

TIME DetikToTIME (long N)
{
    /*Kamus*/
    TIME T;
    long N1;
    /*Algoritma*/
    while (N<0)
    {
        N = N + 86400;
    }
    N1 = N % 86400;
    Hour(T) = N1 / 3600;
    Minute(T) = (N1 - Hour(T)*3600) / 60;
    Second(T) = N1 % 60;
    return T;
}

boolean TEQ (TIME T1, TIME T2)
{
    /*Algoritma*/
    return(TIMEToDetik(T1)==TIMEToDetik(T2));
}

boolean TNEQ (TIME T1, TIME T2)
{
    /*Algoritma*/
    return(TIMEToDetik(T1)!=TIMEToDetik(T2));
}

boolean TLT (TIME T1, TIME T2)
{
    /*Algoritma*/
    return(TIMEToDetik(T1)<TIMEToDetik(T2));
}

boolean TGT (TIME T1, TIME T2)
{
    /*Algoritma*/
    return(TIMEToDetik(T1)>TIMEToDetik(T2));
}

TIME NextDetik (TIME T)
{
    /*Algoritma*/
    return DetikToTIME (TIMEToDetik(T)+1);
}

TIME NextNDetik (TIME T, int N)
{
    /*Algoritma*/
    return DetikToTIME (TIMEToDetik(T)+N);
}

TIME PrevDetik (TIME T)
{
    /*Algoritma*/
    return DetikToTIME (TIMEToDetik(T)-1);
}

TIME PrevNDetik (TIME T, int N)
{
    /*Algoritma*/
    return DetikToTIME (TIMEToDetik(T)-N);
}

long Durasi (TIME TAw, TIME TAkh)
{
    /*Algoritma*/
    long durasiawal = TIMEToDetik(TAw);
    long durasiakhir = TIMEToDetik(TAkh);
    if (durasiawal > durasiakhir)
    {
        durasiakhir = durasiakhir + 86400;
    }
    return durasiakhir-durasiawal;
}
