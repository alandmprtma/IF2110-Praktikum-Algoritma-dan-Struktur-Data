#include <stdio.h>
#include "listlinier.h"

int main (){
    List l;
    CreateList(&l);
    int N;
    float counthit = 0;
    scanf ("%d", &N);

    int ops;
    scanf ("%d", &ops);
    int i;
    for(i = 0; i < ops; i++)
    {
        ElType mem;
        scanf("%d", &mem);
        if (N == 0)
        {
            printf("miss ");
            displayList(l);
            printf("\n");
        }
        else
        {
            if (isEmpty(l))
            {
                insertFirst(&l,mem);
                printf("miss ");
                displayList(l);
                printf("\n");
            }
            else{
                if (indexOf(l, mem) != IDX_UNDEF)
                {
                    printf("hit ");
                    int temp;
                    deleteAt(&l, indexOf(l, mem), &temp);
                    insertFirst(&l, temp);
                    displayList(l);
                    printf("\n");
                    counthit++;
                }
                else
                {
                    if(length(l) == N)
                    {
                        int val;
                        insertFirst(&l, mem);
                        deleteLast(&l, &val);
                        printf("miss ");
                        displayList(l);
                        printf("\n");
                    }
                    else
                    {
                        insertFirst(&l, mem);
                        printf("miss ");
                        displayList(l);
                        printf("\n");
                    }
                }
            }
        }
    }
    float ratio;
    if (counthit == 0)
    {
        ratio = 0;
        printf("hit ratio: %.2f\n", ratio);
    }
    else
    {
        ratio = counthit/ops;
        printf("hit ratio: %.2f\n", ratio);
    }
}