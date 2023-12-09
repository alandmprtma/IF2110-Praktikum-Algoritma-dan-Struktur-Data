#include <stdio.h>
#include "deque.h"

Address newNode(ElType X){
    Address p = (Address)malloc(sizeof(Node));
    if(p != NULL){
        INFO(p) = X;
        NEXT(p) = NULL;
    }
    return p;
}

boolean isEmpty(Deque q){
    return ADDR_HEAD(q) == NULL && ADDR_TAIL(q) == NULL;
}

int length(Deque q){
    int result = 0;
    Address p = ADDR_HEAD(q);
    while(p != NULL){
        result++;
        p = NEXT(p);
    }
    return result;
}

void CreateDeque(Deque *q){
    ADDR_HEAD(*q) = NULL;
    ADDR_TAIL(*q) = NULL;
}

void DisplayDeque(Deque q){
    Address p = ADDR_HEAD(q);
    int i;
    printf("[");
    for(i = 0; i < length(q); i++){
        printf("%d", INFO(p));
        if(i != length(q) - 1){
            printf(",");
        }
        p = NEXT(p);
    }
    printf("]");
}

void EnqueueHead(Deque *q, ElType x) {
    Address P = newNode(x);
    if (P != NIL) {
        if (isEmpty(*q)) {
            ADDR_HEAD(*q) = P;
            ADDR_TAIL(*q) = P;
        } else {
            NEXT(P) = ADDR_HEAD(*q);
            ADDR_HEAD(*q) = P;
        }
    }
}

void DequeueHead(Deque *q, ElType *x) {
    Address P = ADDR_HEAD(*q);
    *x = INFO(P);
    ADDR_HEAD(*q) = NEXT(P);
    free(P);
    if (ADDR_HEAD(*q) == NIL) {
        ADDR_TAIL(*q) = NIL;
    }
}

void EnqueueTail(Deque *q, ElType x) {
    Address P = newNode(x);
    if (P != NIL) {
        if (isEmpty(*q)) {
            ADDR_HEAD(*q) = P;
            ADDR_TAIL(*q) = P;
        } else {
            NEXT(ADDR_TAIL(*q)) = P;
            ADDR_TAIL(*q) = P;
        }
    }
}

void DequeueTail(Deque *q, ElType *x) {
    Address P = ADDR_HEAD(*q);
    Address prev = NIL;
    while (NEXT(P) != NIL) {
        prev = P;
        P = NEXT(P);
    }
    *x = INFO(P);
    if (prev != NIL) {
        NEXT(prev) = NIL;
        ADDR_TAIL(*q) = prev;
        free(P);
    } else {
        ADDR_HEAD(*q) = NIL;
        ADDR_TAIL(*q) = NIL;
        free(P);
    }
}