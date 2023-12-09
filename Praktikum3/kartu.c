#include <stdio.h>
#include "listdin.h"

void deleteFirst(ListDin *l, ElType *val)
{
    IdxType i;
    *val = ELMT(*l, getFirstIdx(*l));

    for (i = IDX_MIN; i <= getLastIdx(*l); i++)
    {
        ELMT(*l, i) = ELMT(*l, i + 1);
    }

    NEFF(*l) -= 1;
}

int main()
{
    ListDin l1, l2, l3;
    CreateListDin(&l1, 100000);
    CreateListDin(&l2, 100000);
    CreateListDin(&l3, 100000);

    readList(&l1);
    readList(&l2);

    int len = listLength(l1) + listLength(l2);
    while (listLength(l3) != len)
    {
        if (isEmpty(l1) || ELMT(l1, getFirstIdx(l1)) < ELMT(l2, getFirstIdx(l2)))
        {
            insertLast(&l3, ELMT(l2, getFirstIdx(l2)));
            deleteFirst(&l2, &ELMT(l2, getFirstIdx(l2)));
        }
        else
        {
            insertLast(&l3, ELMT(l1, getFirstIdx(l1)));
            deleteFirst(&l1, &ELMT(l1, getFirstIdx(l1)));
        }
    }

    printList(l3);
    printf("\n");
    return 0;
}