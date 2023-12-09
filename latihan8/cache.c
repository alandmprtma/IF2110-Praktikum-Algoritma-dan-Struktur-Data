#include <stdio.h>
#include "listlinier.h"
#include "listlinier.c"

int main (){
    List l;
    CreateList(&l);

    int N;
    scanf("%d", &N);
    int i;
    for(i = 1; i <= N; i++)
    {
        insertLast(&l, i);
    }
    
    int ops;
    scanf("%d", &ops);

    for (i = 0; i < ops; i++)
    {
        ElType mem;
        scanf("%d", &mem);
        if (indexOf(l, mem) != IDX_UNDEF)
        {
            int val;
            deleteAt(&l, indexOf(l, mem), &val);
            insertFirst(&l,mem);
            printf("hit ");
            displayList(l);
            printf("\n");
        }
        else{
            int temp;
            insertFirst(&l,mem);
            deleteLast(&l,&temp);
            printf("miss ");
            displayList(l);
            printf("\n");
        }
    }
}