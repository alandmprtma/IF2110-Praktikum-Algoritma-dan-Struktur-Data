#include <stdio.h>
#include "liststatik.h"

/*
NIM     : 13522124
Nama    : Aland Mulia Pratama
Topik   : PraPraktikum ADT List
Tanggal : 8 September 2023
*/

int main()
{
    int i,j;
    boolean cekdes, cekasc, cekmono;
    ListStatik l;
    readList(&l);
    int n = listLength(l);

    /*Cek Descending*/
    cekdes = true;
    for (i = 0; i < n; i++)
    {
        for (j = i; j < n; j++)
        {
            if (ELMT(l,i) > ELMT(l,j))
            {
                cekdes = false;
            }
        }
    }

    /*Cek Ascending*/
    cekasc = true;
    for (i = 0; i < n; i++)
    {
        for (j = i; j < n; j++)
        {
            if (ELMT(l,i) < ELMT(l,j))
            {
                cekasc = false;
            }
        }
    }

    /*Cek Static Monotonic*/
    cekmono = true;
    for (i = 0; i < n; i++)
    {
        for (j = i; j < n; j++)
        {
            if (ELMT(l,i) != ELMT(l,j))
            {
                cekmono = false;
            }
        }
    }


    if (cekmono)
    {
        printf("Static Monotonic List");
    }
    else if (cekasc)
    {
        printf("Non-ascending Monotonic List");
    }
    else if(cekdes)
    {
        printf("Non-descending Monotonic List");
    }
    else{
        printf("Non-monotonic List");
    }
}