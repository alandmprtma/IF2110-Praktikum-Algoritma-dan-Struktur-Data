#include <stdio.h>
#include "liststatik.h"
#include <stdlib.h>

int truck(ListStatik R, ListStatik J, int x) {
    int count = 0, path = 0, index = 0;

    for (int i = 0; i < listLength(R); i++) {
        if (ELMT(R, i) == x) {
            count++;
            for (int j = index; j < i; j++) {
                path += ELMT(J, j);
            }
            index = i;
        }
    }

    return count + (path * 2);
}

int main() {
    ListStatik R, J;
    readList(&R);
    readList(&J);

    int total = 0;
    for (int i = 1; i <= 3; i++) {
        total += truck(R, J, i);
    }

    printf("%d\n", total);
}


/*
int main()
{
    ListStatik rumah, durasi;
    readList(&rumah);
    readList(&durasi);
    int besi = 1;
    int kertas = 2;
    int kaca = 3;
    int time = 0;

    int i;
    Index Besi
    int indexbesi =-1;
    i = listLength(rumah)-1;
    boolean cekbesi = false;
    while (cekbesi == false && i >= 0)
    {
        if (ELMT(rumah,i) == besi) {
            indexbesi = i;
            cekbesi = true;
        }
        i--;
    }
    Besi
    if (indexbesi >= 0);
    {
        for(i = 0; i <= indexbesi; i++)
        {
            if (ELMT(rumah,i) == besi)
            {
                time = time + 1;
            }
            int index = i-1;
            if (index >= 0)
            {
                time = time + ELMT(durasi, index);
            }
        }
        /*Perjalanan Balik Besi
        for(i = indexbesi; i >= 0; i--)
        {
            int index = i-1;
            if (index >= 0)
            {
                time = time + ELMT(durasi, index);
            }
        }
    }
   

    /*Index Kertas
    int indexkertas =-1;
    boolean cekkertas = false;
    while (cekkertas == false && i >= 0)
    {
        if (ELMT(rumah,i) == kertas) {
            indexkertas = i;
            cekkertas = true;
        }
        i--;
    }
    /*Kertas
    if (indexkertas>= 0)
    {
        for(i = 0; i <= indexkertas; i++)
        {
            if (ELMT(rumah,i) == kertas)
            {
                time = time + 1;
            }
            int index = i-1;
            if (index >= 0)
            {
                time = time + ELMT(durasi, index);
            }
        }
        /*Perjalanan Balik Kertas
        for(i = indexkertas; i >= 0; i--)
        {
            int index = i-1;
            if (index >= 0)
            {
                time = time + ELMT(durasi, index);
            }
        }
    }
    

     /*Index Kaca
    int indexkaca =-1;
    boolean cekkaca = false;
    while (cekkaca == false && i >= 0)
    {
        if (ELMT(rumah,i) == kertas) {
            indexkaca = i;
            cekkaca = true;
        }
        i--;
    }
    /*Kaca
    if (indexkaca >= 0)
    {
        for(i = 0; i <= kaca; i++)
        {
            if (ELMT(rumah,i) == kaca)
            {
                time = time + 1;
            }
            int index = i-1;
            if (index >= 0)
            {
                time = time + ELMT(durasi, index);
            }
        }
        /*Perjalanan Balik Kaca
        for(i = indexkaca; i >= 0; i--)
        {
            int index = i-1;
            if (index >= 0)
            {
                time = time + ELMT(durasi, index);
            }
        }
    }

    printf("%d\n", 26);
}
*/