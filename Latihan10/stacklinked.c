#include "stacklinked.h"
#include <stdio.h>

Address newNode(ElType x) {
    Address P = (Address)malloc(sizeof(Node));
    if (P != NULL) {
        INFO(P) = x;
        NEXT(P) = NIL;
    }
    return P;
}

boolean isEmpty(Stack s) {
    return ADDR_TOP(s) == NIL;
}

int length(Stack s) {
    int count = 0;
    Address P = ADDR_TOP(s);
    while (P != NIL) {
        count++;
        P = NEXT(P);
    }
    return count;
}

void CreateStack(Stack *s) {
    ADDR_TOP(*s) = NIL;
}

void DisplayStack(Stack s) {
    Address P = ADDR_TOP(s);
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

void push(Stack *s, ElType x) {
    Address P = newNode(x);
    if (P != NIL) {
        NEXT(P) = ADDR_TOP(*s);
        ADDR_TOP(*s) = P;
    }
}

void pop(Stack *s, ElType *x) {
    if (!isEmpty(*s)) {
        *x = INFO(ADDR_TOP(*s));
        Address P = ADDR_TOP(*s);
        ADDR_TOP(*s) = NEXT(ADDR_TOP(*s));
        free(P);
    }
}