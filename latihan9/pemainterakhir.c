#include "list_circular.h"
#include "list_circular.c"
#include <stdio.h>

int main(){
    int i,N,K;
    scanf("%d %d",&N, &K);
    List l;
    CreateList(&l);
    for (i = 1 ; i <= N ; i++){
        insertLast(&l,i);
    }
    Address loc;
    int val, pop;
    int temp = 0;
    while(temp < N){
        temp++;        
        int val = K;
        loc = FIRST(l);
        while (val > 1){
            loc = NEXT(loc);
            val--;
        }
        pop = INFO(loc);
        FIRST(l) = loc;
        deleteFirst(&l,&val);
        if (temp != N){
            printf("%d\n",pop);
        }
        else{
            printf("Pemenang %d\n",pop);
        }
    }
    return 0;
}