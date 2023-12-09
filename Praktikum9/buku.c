#include <stdio.h>
#include "list_circular.h"

int main() {
    int n, temp, i, res = 1, j;
    List l, db;
    CreateList(&l);
    scanf("%d", &n);
    boolean b[n];
    for (i = 0; i < n; i++) {
        b[i] = true;
    }
    for (i = 0; i < n-1; i++) {
        scanf("%d", &temp);
        insertLast(&l, temp);
    }
    for(i = 0; i < n - 1; i++) {
        deleteFirst(&l, &temp);

        if (temp > 0) {
            for (j = 0; j < temp; j++) {
                res++;
                if (res > n) {
                    res = 1;
                }
                while (!b[res-1]) {
                    res++;
                    if (res > n) {
                        res = 1;
                    }
                }
            }
            res = res % n;
            if (res == 0) {
                res = n;
            }
            if (b[res-1]) {
                b[res-1] = false;
            }
        }

        else {
            temp *= -1;
            for (j = 0; j < temp; j++) {
                res--;
                if (res < 1) {
                    res = n;
                }
                while (!b[res-1]) {
                    res--;
                    if (res < 1) {
                        res = n;
                    }                  
                }
            }
            res = res % n;
            if (res == 0) {
                res = n;
            }
            if (b[res-1]) {
                b[res-1] = false;
            }
        }
    }
    for(j = 0; j < n; j++) {
        if (b[j]) {
            printf("%d\n", j+1);
            break;
        }
    }
}