#include <stdio.h>
#include "listdin.h"


int main()
{
    ListDin l1;
    int tipe;
    CreateListDin(&l1, 0);
    int Q, i;
    scanf("%d",&Q);
    for (i = 0; i < Q; i++)
    {
        scanf("%d",&tipe);
        if(tipe==1)
        {
            int x;
            scanf("%d",&x);
            // proses query tipe 1
            if (isEmpty(l1))
            {
                expandList(&l1,1);
            }
            else if (isFull(l1))
            {
                expandList(&l1,CAPACITY(l1));
            }
            insertLast(&l1,x);

        }
        else if(tipe==2)
        {
            // proses query tipe 2
            int temp;
            deleteLast(&l1,&temp);
            if (NEFF(l1) <= (CAPACITY(l1)/2))
            {
                CAPACITY(l1) = CAPACITY(l1)/2;
            }
        }
        else
        {
            printf("%d ", CAPACITY(l1));
            printList(l1);
            printf("\n");
        }
    }
}
