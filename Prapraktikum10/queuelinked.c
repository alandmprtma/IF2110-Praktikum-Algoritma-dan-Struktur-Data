#include "queuelinked.h"
#include <stdio.h>

Address newNode(ElType x) {
    Address P = (Address)malloc(sizeof(Node));
    if (P != NULL) {
        INFO(P) = x;
        NEXT(P) = NIL;
    }
    return P;
}

boolean isEmpty(Queue q) {
    return ADDR_HEAD(q) == NIL && ADDR_TAIL(q) == NIL;
}

int length(Queue q) {
    int count = 0;
    Address P = ADDR_HEAD(q);
    while (P != NIL) {
        count++;
        P = NEXT(P);
    }
    return count;
}

void CreateQueue(Queue *q) {
    ADDR_HEAD(*q) = NIL;
    ADDR_TAIL(*q) = NIL;
}

void DisplayQueue(Queue q) {
    Address P = ADDR_HEAD(q);
    printf("[");
    while (P != NIL) {
        printf("%d", INFO(P));
        P = NEXT(P);
        if (P != NIL) {
            printf(",");
        }
    }
    printf("]");
}

void enqueue(Queue *q, ElType x) {
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

void dequeue(Queue *q, ElType *x) {
    if (!isEmpty(*q)) {
        *x = INFO(ADDR_HEAD(*q));
        Address P = ADDR_HEAD(*q);
        ADDR_HEAD(*q) = NEXT(ADDR_HEAD(*q));
        free(P);

        // Jika setelah dequeue queue menjadi kosong, perlu mengupdate ADDR_TAIL juga.
        if (ADDR_HEAD(*q) == NIL) {
            ADDR_TAIL(*q) = NIL;
        }
    }
}