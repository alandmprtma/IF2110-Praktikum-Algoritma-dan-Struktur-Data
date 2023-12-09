#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "prioqueuechar.h"

boolean IsEmpty (PrioQueueChar Q){
    return Q.HEAD==Nil || Q.TAIL==Nil;
}

boolean IsFull (PrioQueueChar Q){
    if (NBElmt(Q)==Q.MaxEl){
        return true;
    }else{
        return false;
    }
}

int NBElmt (PrioQueueChar Q){
    if (Q.HEAD!=Nil&&Q.TAIL!=Nil){
        if (Q.TAIL<Q.HEAD){
            return Q.MaxEl - Q.HEAD+ 1 + Q.TAIL;
        }else{
            return (Q.TAIL-Q.HEAD) + 1;
        }
    }else{
        return 0;
    }
}

void MakeEmpty (PrioQueueChar * Q, int Max){
    Q->T = (infotype*)malloc(Max*sizeof(infotype));
    if (Q->T!=NULL){
        Q->HEAD = Nil;
        Q->TAIL = Nil;
        Q->MaxEl = Max;
    }else{
        Q->MaxEl = 0;
    }
}

void DeAlokasi(PrioQueueChar * Q){
    Q->HEAD = Nil;
    Q->TAIL = Nil;
    Q->MaxEl = 0;
    free(Q->T);
}

void Enqueue(PrioQueueChar *Q, infotype X) {
    if (!IsFull(*Q)) {
        if (IsEmpty(*Q)) {
            Q->HEAD = 0;
            Q->TAIL = 0;
            Q->T[0] = X;
        } else {
            int i = Q->TAIL;
            while (i >= Q->HEAD && X.prio < Q->T[i].prio) {
                Q->T[(i + 1) % Q->MaxEl] = Q->T[i];
                i = (i - 1 + Q->MaxEl) % Q->MaxEl;
            }
            Q->TAIL = (Q->TAIL + 1) % Q->MaxEl;
            Q->T[(i + 1) % Q->MaxEl] = X;
        }
    }
}

void Dequeue (PrioQueueChar * Q, infotype * X){
    *X = Q->T[Q->HEAD];
    if (Q->HEAD==Q->TAIL){
        Q->HEAD = Nil;
        Q->TAIL = Nil;
    }else{
        Q->HEAD = (Q->HEAD+1)%Q->MaxEl;
    }
}

void PrintPrioQueueChar (PrioQueueChar Q){
    infotype t;
    if (IsEmpty(Q)){
        printf("#\n");
    }else{
        int len = NBElmt(Q);
        for (int i=0;i<len;i++){
            Dequeue(&Q,&t);
            printf("%d %c\n",t.prio, t.info);
        }
        printf("#\n");
    }
}