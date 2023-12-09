#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"

Address newNode(ElType val){
    Address p = (Address)malloc(sizeof(Node));
    if(p != NULL){
        INFO(p) = val;
        NEXT(p) = NULL;
    }
    return p;
}

void CreateList(List *l){
    FIRST(*l) = NULL;
}

boolean isEmpty(List l){
    return FIRST(l) == NULL;
}

ElType getElmt(List l, int idx){
    while(idx--){
        FIRST(l) = NEXT(l);
    }
    return INFO(l);
}

void setElmt(List*l, int idx, ElType val){
    List p = *l;
    while(idx--){
        FIRST(p) = NEXT(p);
    }
    INFO(p)=val;
}

int indexOf(List l, ElType val){
    boolean found = false;
    int idx = 0;
    while(l != NULL && !found){
        if(INFO(l) == val){
            found = true;
        }
        else {
            idx++;
            FIRST(l) = NEXT(l);
        }
    }
    if (found) return idx;
    return IDX_UNDEF;
}

void insertFirst(List *l, ElType val){
    Address p = newNode(val);
    if(p != NULL){
        NEXT(p) = *l;
        *l = p;
    }
}

void insertLast(List *l, ElType val){
    if(isEmpty(*l)){
        insertFirst(l, val);
    }
    else {
        Address p = newNode(val);
        if(p != NULL){
            Address last = *l;
            while(NEXT(last) != NULL){
                last = NEXT(last);
            }
            NEXT(last) = p;
        }
    }
}

void insertAt(List *l, ElType val, int idx){
    if(idx == 0){
        insertFirst(l,val);
    }
    else {
        Address p = newNode(val);
        if(p != NULL){
            int ctr = 0;Address loc = *l;
            while(ctr < idx - 1){
                ctr++;
                loc = NEXT(loc);
            }
            NEXT(p) = NEXT(loc);
            NEXT(loc) = p;
        }
    }
}

void deleteFirst(List *l, ElType *val){
    Address p = *l;
    *val = INFO(p);
    *l = NEXT(p);
    free(p);
}

void deleteLast(List *l, ElType *val){
    Address p = *l, loc = NULL;
    while(NEXT(p) != NULL){
        loc = p;
        p = NEXT(p);
    }
    if(loc == NULL){
        *l = NULL;
    }
    else{
        NEXT(loc) = NULL;
    }
    *val = INFO(p);
    free(p);
}

void deleteAt(List *l, int idx, ElType *val){
    if(idx == 0){
        deleteFirst(l, val);
    } else {
        int ctr = 0;
        Address loc = *l;
        while(ctr < idx - 1){
            ctr++;
            loc = NEXT(loc);
        }
        Address p = NEXT(loc);
        *val = INFO(p);
        NEXT(loc) = NEXT(p);
        free(p);
    }
}

void displayList(List l){
    printf("[");
    while(!isEmpty(l)){
        printf("%d", INFO(l));
        if(NEXT(l) != NULL){
            printf(",");
        }
        l = NEXT(l);
    }
    printf("]");
}

int length(List l){
    int cnt = 0;
    while(l != NULL){
        cnt++;
        l = NEXT(l);
    } return cnt;
}

List concat(List l1, List l2){
    List l3;
    CreateList(&l3);
    Address p = l1;
    while(p != NULL){
        insertLast(&l3, INFO(p));
        p = NEXT(p);
    }
    p = l2;
    while(p != NULL){
        insertLast(&l3, INFO(p));
        p = NEXT(p);
    }
    return l3;
}

boolean fSearch(List L, Address P) {
    Address p = L;
    while (p != NULL && p != P) {
        p = NEXT(p);
    }
    return (p != NULL);
}

Address searchPrec(List L, ElType X) {
    if (INFO(L) == X) {
        return NULL;
    } else {
        Address p = L;
        while (NEXT(p) != NULL && INFO(NEXT(p)) != X) {
            p = NEXT(p);
        }
        if (NEXT(p) == NULL) {
            return NULL;
        } else {
            return p;
        }
    }
}

ElType maxValue(List l) {
    ElType max = INFO(l);
    Address p = NEXT(l);
    while (p != NULL) {
        if (INFO(p) > max) {
            max = INFO(p);
        }
        p = NEXT(p);
    }
    return max;
}

Address adrMax(List l) {
    Address max = l;
    Address p = NEXT(l);
    while (p != NULL) {
        if (INFO(p) > INFO(max)) {
            max = p;
        }
        p = NEXT(p);
    }
    return max;
}

ElType minValue(List l) {
    ElType min = INFO(l);
    Address p = NEXT(l);
    while (p != NULL) {
        if (INFO(p) < min) {
            min = INFO(p);
        }
        p = NEXT(p);
    }
    return min;
}

Address adrMin(List l) {
    Address min = l;
    Address p = NEXT(l);
    while (p != NULL) {
        if (INFO(p) < INFO(min)) {
            min = p;
        }
        p = NEXT(p);
    }
    return min;
}

float average(List L) {
    float sum = 0;
    int count = 0;
    Address p = L;
    while (p != NULL) {
        sum += INFO(p);
        count++;
        p = NEXT(p);
    }
    return sum / count;
}

void deleteAll(List *l) {
    ElType x;
    while (!isEmpty(*l)) {
        deleteFirst(l, &x);
    }
}

void copyList(List *l1, List *l2) {
    *l2 = *l1;
}

void inverseList(List *l) {
    if (!isEmpty(*l) && NEXT(*l) != NULL) {
        Address p = NEXT(*l);
        Address q = NULL;
        NEXT(*l) = NULL;
        while (p != NULL) {
            q = NEXT(p);
            NEXT(p) = *l;
            *l = p;
            p = q;
        }
    }
}
