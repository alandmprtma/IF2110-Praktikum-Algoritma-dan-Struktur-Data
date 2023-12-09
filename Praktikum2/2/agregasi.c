#include <stdio.h>
#include "liststatik.h"

int main ()
{
    ListStatik l1;
    readList(&l1);
    int x;
    scanf("%d", &x);
    sortList(&l1, true);
    printList(l1);
    printf("\n");
    float sum = 0;
    int i;
    for (i = 0; i < listLength(l1); i++)
    {
        sum = sum + ELMT(l1,i);
    }
    float average = sum / listLength(l1);
    printf("Average: %.2f\n", average);
    int index = indexOf(l1,x);
    if (index == IDX_UNDEF)
    {
        printf("%d tidak ada\n", x);
    }
    else
    {
        printf("%d\n", index);
    }
    int max, min;
    extremeValues(l1, &max, &min);  
    if (x == max)
    {
        printf("X maksimum\n");
    }
    if (x == min)
    {
        printf("X minimum\n");
    }
    int median;
    if (listLength(l1)%2 == 0)
    {
        median = ELMT(l1, (listLength(l1)/2)-1);
    }
    else
    {
        median = ELMT(l1, (listLength(l1)/2));
    }
    if (x == median)
    {
        printf("X median\n");
    }
}