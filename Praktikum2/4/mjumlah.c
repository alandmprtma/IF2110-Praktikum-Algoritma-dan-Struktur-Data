#include <stdio.h>
#include "liststatik.h"

int main()
{
    ListStatik l1, l2, lnew;
    readList(&l1);
    readList(&l2);
    CreateListStatik(&lnew);
    int i;
    int multi = 1;
    int sum = 0;
    for (i=listLength(l1)-1;i>=0;i--)
    {
        sum = sum + (ELMT(l1,i)*multi);
        multi= multi*10;
    }
    multi = 1;
    for (i=listLength(l2)-1;i>=0;i--)
    {
        sum = sum + (ELMT(l2,i)*multi);
        multi= multi*10;
    }
    while (sum > 0)
    {
        int bilangan = sum%10;
        insertFirst(&lnew, bilangan);
        sum = sum/10;
    }
    printList(lnew);
    printf("\n");
}