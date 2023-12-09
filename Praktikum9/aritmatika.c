#include <stdio.h>
#include "list_circular.h"

int main (){
    int N, i;
    scanf("%d", &N);
    List l;
    CreateList(&l);

    for (i = 0; i < N; i++)
    {
        int temp;
        scanf("%d", &temp);
        insertLast(&l, temp);
    };
    
    //Mendapatkan nilai a dan b
    Address p;
    p = FIRST(l);
    int b = INFO(p);  
    p = NEXT(p);
    int f = INFO(p);
    int a = f - b;
    //Memvalidasi apakah deret memenuhi kaidah aritmatika
    boolean cek = true;
    int j = 1;
    while (!isEmpty(l) && j <= N)
    {
        int val;
        int deret = a*(j-1)+b;
        deleteFirst(&l,&val);
        if (val != deret)
        {
            cek = false;
        }
        j++;
    }
    if (cek)
    {
        printf("%d %d\n", a, b);
    }
    else{
        printf("%d %d\n", 0, 0);
    }
}