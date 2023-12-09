#include <stdio.h>
#include <stdlib.h>
#include "listganda.h"

Address newNode(ElType val) {
    Address p = (Address) malloc (sizeof(Node));
    if (p != NULL) {
        INFO(p) = val;
        NEXT(p) = NULL;
        PREV(p) = NULL;
    }
}

void createListGanda(ListGanda *l) {
    CURRENT(*l) = NULL;
}

boolean isEmpty(ListGanda l) {
    return (CURRENT(l) == NULL);
}

boolean isOneElement(ListGanda l) {
    return (!isEmpty(l) && NEXT(CURRENT(l)) == CURRENT(l));
}

int length(ListGanda l) {
    if (isEmpty(l)) {
        return 0;
    } else {
        Address start = CURRENT(l);
        Address p = start;

        int count = 1;
        while (NEXT(p) != start) {
            p = NEXT(p);
            count += 1;
        }

        return count;
    }
}

void rotate(ListGanda *l, int k) {
    int step = (k > 0) ? k : (-1 * k);

    int count = 0;
    Address p = CURRENT(*l);
    if (length(*l) > 0)  {
        while (count < step) {
            if (k > 0) {
                p = NEXT(p);
            } else {
                p = PREV(p);
            }
            count += 1;
        }
        CURRENT(*l) = p;
    }
}

void insertAfterCurrent(ListGanda *l, ElType x) {
    Address newp = newNode(x);

    if (isEmpty(*l)) {
        CURRENT(*l) = newp;
        NEXT(newp) = newp;
        PREV(newp) = newp;
    } else {
        Address p = CURRENT(*l);
        Address oldnext = NEXT(p);

        NEXT(p) = newp;
        NEXT(newp) = oldnext;

        PREV(newp) = p;
        PREV(oldnext) = newp;

        CURRENT(*l) = newp;
    }
;}

void deleteCurrent(ListGanda *l, ElType *x) {
    if (isOneElement(*l)) {
        Address p = CURRENT(*l);
        *x = INFO(p);

        free(p);
        CURRENT(*l) = NULL;
    } else {
        Address p = CURRENT(*l);
        Address pnext = NEXT(p);
        Address pprev = PREV(p);

        *x = INFO(p);
        NEXT(pprev) = pnext;
        PREV(pnext) = pprev;

        free(p);
        CURRENT(*l) = pnext;
    }
}