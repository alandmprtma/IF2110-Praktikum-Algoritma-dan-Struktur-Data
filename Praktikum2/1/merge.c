#include <stdio.h>
#include "liststatik.h"

int main()
{
    int i;
    ListStatik l1,l2, lnew;
    CreateListStatik(&lnew);
    readList(&l1);
    readList(&l2);
    for(i = 0; i < listLength(l1); i++)
    {
        insertLast(&lnew, ELMT(l1,i));
    }
    for(i = 0; i < listLength(l2); i++)
    {
        insertLast(&lnew, ELMT(l2,i));
    }
    sortList(&lnew, true);
    printList(lnew);
    printf("\n");
}