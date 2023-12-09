#include <stdio.h>
#include "liststatik.h"

int main()
{
    int x, index, max, min;
    ListStatik l;
    readList(&l);
    scanf ("%d", &x);
    printList(l);
    printf("\n");
    index = indexOf(l,x);
    if (index == IDX_UNDEF)
    {
        printf("%d tidak ada\n", x);
    }
    else
    {
        printf("%d\n", indexOf(l,x));
    }
    extremeValues(l, &max, &min);
    sortList (&l, true);
    int median;
    if(listLength(l)%2 == 1)
    {
        median = ELMT(l, listLength(l)/2);
    }
    else
    {
        median = ELMT(l,(listLength(l)/2)+1);
    }
    if (x == max)
    {
        printf("maksimum\n");
    }
    if(x == min)
    {
        printf("minimum\n");
    }
    if(x == median)
    {
        printf("median\n");
    }
}