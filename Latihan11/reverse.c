#include <stdio.h>
#include "listrec.h"

void displayList1(List l){
    if (isOneElmt(l)){
        printf("%d", head(l));
    } else{
        printf("%d ", head(l));
        displayList1(tail(l));
    }
}

void mixUp(List l, List l1, int K, int count){
    if (isEmpty(l)){
        displayList1(l1);
        printf("\n");
    } else if (isOneElmt(l) && count == K){
        printf("%d ", head(l));
        displayList1(l1);
        printf("\n");
    } else {
        if (count < K){
            l1 = konso(l1, head(l));
            count++;
            mixUp(tail(l),l1,K,count);
        } else{
            l1 = konso(l1, head(l));
            displayList1(l1);
            printf(" ");
            l1 = NIL;
            count = 1;
            mixUp(tail(l),l1,K,count);
        }
    } 
}

int main(){
    int N, K, temp;
    List l, l1;
    l = NIL;
    l1 = NIL;
    scanf("%d %d", &N, &K);
    int i;
    for (i = 0; i < N; i++){
        scanf("%d", &temp);
        l = konsb(l, temp);
    }

    if (N == 1){
        printf("%d\n", head(l));
    } else if (K <= 1){
        displayList1(l);
        printf("\n");
    } else{
        int count = 1;
        mixUp(l, l1, K, count);
    }
}