/* File: listsirkuler.c */
#include "list_circular.h"
#include <stdio.h>
#include <stdlib.h>

/****************** TEST LIST KOSONG ******************/
boolean isEmpty(List l) {
    return FIRST(l) == NULL;
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateList(List *l) {
    FIRST(*l) = NULL;
}

/****************** Manajemen Memori ******************/
Address allocate(ElType val) {
    Address newNode = (Address)malloc(sizeof(ElmtList));
    if (newNode != NULL) {
        INFO(newNode) = val;
        NEXT(newNode) = NULL;
    }
    return newNode;
}

void deallocate(Address P) {
    free(P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
Address search(List l, ElType val) {
    if (isEmpty(l)){
        return NULL;
    }
    else{
        Address P = FIRST(l);
        boolean found = false;
        while (NEXT(P) != FIRST(l) && !found){
            if(INFO(P) == val){
                found = true;
            }
            else{
                P = NEXT(P);
            }
        }
        if(INFO(P) == val){
            found = true;
        }
        if (found){
            return P;
        }
        else{
            return NULL;
        }
    }
}

boolean addrSearch(List l, Address p) {
    if(isEmpty(l)){
        return false;
    }
    Address q = FIRST(l);
    while(NEXT(q) != FIRST(l) && q != p){
        q = NEXT(q);
    }
    return q == p;
}


/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirst(List *l, ElType val)
{
    Address p, last;
    p = allocate(val);
    if (p != NULL) {
        if (isEmpty(*l)) {
            NEXT(p) = p;
        } else {
            last = FIRST(*l);
            while (NEXT(last) != FIRST(*l)) {
                last = NEXT(last);
            }
            NEXT(p) = FIRST(*l);
            NEXT(last) = p;
        }
        FIRST(*l) = p;
    }
}


void insertLast(List *l, ElType val)
{
    Address p, last;
    if (isEmpty(*l)) {
        insertFirst(l, val);
    } else {
        p = allocate(val);
        if (p != NULL) {
            last = FIRST(*l);
            while (NEXT(last) != FIRST(*l)) {
                last = NEXT(last);
            }
            NEXT(last) = p;
            NEXT(p) = FIRST(*l);
        }
    }
}

/*** PENGHAPUSAN ELEMEN ***/
void deleteFirst(List *l, ElType *val)
{
    Address p = FIRST(*l), q = FIRST(*l);
    *val = INFO(p);
    if(NEXT(FIRST(*l)) == FIRST(*l)){
        FIRST(*l) = NULL;
    }
    else{
        while(NEXT(q) != FIRST(*l)){
            q = NEXT(q);
        }
        FIRST(*l) = NEXT(FIRST(*l));
        NEXT(q) = FIRST(*l);
    }
    free(p);
}

void deleteLast(List *l, ElType *val) 
{
    Address p = FIRST(*l), q = NULL;
    while(NEXT(p) != FIRST(*l)){
        q = p;
        p = NEXT(p);
    }
    if(q == NULL){
        FIRST(*l) = NULL;
    }
    else{
        NEXT(q) = FIRST(*l);
    }
    *val = INFO(p);
    free(p);
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void displayList(List l) {
    Address P = FIRST(l);
    if (P != NULL) {
        printf("[");
        do {
            printf("%d", INFO(P));
            P = NEXT(P);
            if (P != FIRST(l)) {
                printf(",");
            }
        } while (P != FIRST(l));
        printf("]");
    } else {
        printf("[]");
    }
}