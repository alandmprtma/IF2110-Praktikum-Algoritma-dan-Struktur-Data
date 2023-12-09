/*Nama : Aland Mulia Pratama*/
/*NIM : 13522124*/
/*Tanggal : 1 September 2023*/


#include <stdio.h>
#include "time.h"

int main()
{
    int n, i;
    TIME T1, T2;
    TIME Tmaks, Tmin;
    CreateTime(&Tmaks, 0, 0, 0);
    CreateTime(&Tmin, 23, 59, 59);
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        printf("[%d]\n", i);
        BacaTIME(&T1);
        BacaTIME(&T2);
        if(TLT(T1,T2))
        {
            printf("%ld\n", Durasi(T1,T2));
        }
        else if(TEQ(T1,T2))
        {
            printf("%d\n", 0);
        }
        else
        {
            printf("%ld\n", Durasi(T2,T1));
        }
        if (TLT(T1,Tmin))
        {
            Tmin = T1;
        }
        if(TGT(T1,Tmaks))
        {
            Tmaks = T1;
        }
        if(TLT(T2,Tmin))
        {
            Tmin = T2;
        }
        if(TGT(T2,Tmaks))
        {
            Tmaks = T2;
        }
    }
    TulisTIME(Tmin);
    printf("\n");
    TulisTIME(Tmaks);
    printf("\n");
}
