#include <stdio.h>
#include "listdin.h"

int main()
{
    ListDin A;
    IdxType i;
    int C, Q, tipe, num;

    scanf("%d", &C);
    CreateListDin(&A, C);

    scanf("%d", &Q);
    for (i = 0; i < Q; i++)
    {
        scanf("%d", &tipe);

        if (tipe == 1)
        {
            scanf("%d", &num);

            int i = getLastIdx(A);
            while (num > ELMT(A, i))
            {
                deleteLast(&A, &ELMT(A, getLastIdx(A)));
                i--;
            }

            insertLast(&A, num);
        }
        else
        {
            printf("%d\n", listLength(A));
            printList(A);
            printf("\n");
        }
    }
    return 0;
}