#include <stdio.h>
#include "stack.h"

void SortirKeranjang (Stack * S1, Stack * S2)
/* Menyortir keranjang S1 menggunakan bantuan S2 */
/* I.S. S1 tidak terurut dan S2 kosong */
/* F.S. S1 kosong dan S2 terurut */
/* Contoh: */
/*            TOP */
/* I.S. S1 = [23, 92, 98, 31, 3, 34]; S2 = [] */
/*                     TOP */
/* I.S. S1 = []; S2 = [3, 23, 31, 34, 92, 98] */
{
    Stack temp;
    CreateEmpty(&temp); 

    infotype X, Y;

    while (!IsEmpty(*S1))
    {
        Pop(S1, &X); 
        if (IsEmpty(temp) || X >= InfoTop(temp))
        {
            Push(&temp, X); 
        }
        else
        {
            while (!IsEmpty(temp) && X < InfoTop(temp))
            {
                Pop(&temp, &Y); 
                Push(S1, Y); 
            }
            Push(&temp, X);
        }
    }


    while (!IsEmpty(temp))
    {
        Pop(&temp, &X);
        Push(S2, X);
    }
}