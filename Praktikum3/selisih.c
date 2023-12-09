#include <stdio.h>
#include "listdin.h"

int main()
{
    ListDin(l1);
    CreateListDin(&l1,100);
    readList(&l1);
    if (listLength(l1) == 1)
    {
        printf("%d\n", 0);
    }
    else
    {
        int maks, min;
        extremeValues(l1, &maks, &min);
        int selisih = (maks-min)+1;
        printf("%d\n", selisih);
    }
}