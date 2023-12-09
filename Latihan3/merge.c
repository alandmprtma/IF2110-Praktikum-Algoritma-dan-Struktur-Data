#include <stdio.h>
#include "listdin.h"

int main ()
{
    int i;
    ListDin l1, l2, lnew;
    CreateListDin(&l1, 200);
    CreateListDin(&l2, 200);
    CreateListDin(&lnew, 400);
    readList(&l1);
    readList(&l2);
    for ( i = 0; i < NEFF(l1); i++)
    {
        /* code */
        if (countVal(lnew,ELMT(l1,i))==0)
        {
            insertLast(&lnew,ELMT(l1,i));
        }
    }
    for ( i = 0; i < NEFF(l2); i++)
    {
        /* code */
        if (countVal(lnew,ELMT(l2,i))==0)
        {
            insertLast(&lnew,ELMT(l2,i));
        }
    }
    sort(&lnew,true);
    printList(lnew);
}