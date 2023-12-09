#include <stdio.h>
#include "listdin.h"

int main() {
    /* KAMUS */
    int NMax, NExtra;
    ListDin l1, l2, sortedL1, sortedL2;
    ElType maxL1, minL1, maxL2, minL2, temp;
    IdxType i;

    /* ALGORITMA */
    printf("Masukkan jumlah maksimal elemen ListDin: ");
    scanf("%d", &NMax);

    CreateListDin(&l1, NMax);
    CreateListDin(&l2, NMax);

    printf("Masukkan ListDin pertama:\n");
    readList(&l1);

    printf("\n");
    printf("ListDin pertama: ");printList(l1);printf("\n");

    if (!isEmpty(l1)){
        extremeValues(l1, &maxL1, &minL1);
        printf("Range ListDin pertama: (%d - %d)\n", minL1, maxL1);
        printf("Jumlah semua elemen pada ListDin pertama: %d\n", sumList(l1));
        printf("Frequency table ListDin pertama: \n");
        for (i = 0; i <= getLastIdx(l1); i++) {
            if (i == indexOf(l1, ELMT(l1, i))) {
                printf("%d : %d\n", ELMT(l1, i), countVal(l1, ELMT(l1, i)));
            }
        }
        if (isEmpty(l1)) {
            printf("ListDin pertama kosong!\n");
        }
        if (isFull(l1)) {
            printf("ListDin pertama penuh!\n");
        }
        copyList(l1, &sortedL1);
        sort(&sortedL1, true);
        printf("ListDin pertama sorted: ");printList(sortedL1);printf("\n");
    } else {
        printf("ListDin pertama kosong!\n");
    }
    printf("\n");

    compressList(&l1);

    printf("Masukkan ListDin kedua:\n");
    readList(&l2);

    printf("\n");
    printf("ListDin kedua: ");printList(l2);printf("\n");

    if (!isEmpty(l2)){
        extremeValues(l2, &maxL2, &minL2);
        printf("Range ListDin kedua: (%d - %d)\n", minL2, maxL2);
        printf("Jumlah semua elemen pada ListDin kedua: %d\n", sumList(l2));
        printf("Frequency table ListDin kedua: \n");
        for (i = 0; i <= getLastIdx(l2); i++) {
            if (i == indexOf(l2, ELMT(l2, i))) {
                printf("%d : %d\n", ELMT(l2, i), countVal(l2, ELMT(l2, i)));
            }
        }
        if (isEmpty(l2)) {
            printf("ListDin kedua kosong!\n");
        }
        if (isFull(l2)) {
            printf("ListDin kedua penuh!\n");
        }
        copyList(l2, &sortedL2);
        sort(&sortedL2, true);
        printf("ListDin kedua sorted: ");printList(sortedL2);printf("\n");
    } else {
        printf("ListDin kedua kosong!\n");
    }
    printf("\n");
    
    compressList(&l2);

    if (listLength(l1) == listLength(l2)) {
        printf("ListDin pertama + ListDin kedua = ");printList(plusMinusList(l1, l2, true));printf("\n");
        printf("ListDin pertama - ListDin kedua = ");printList(plusMinusList(l1, l2, false));printf("\n");
    }
    if (isListEqual(l1, l2)) {
        printf("ListDin pertama = ListDin kedua\n");
    }

    expandList(&l1, listLength(l2));

    NExtra = listLength(l2);

    for (i = 0; i < NExtra; i++) {
        deleteLast(&l2, &temp);
        insertLast(&l1, temp);
    }

    sort(&l1, true);

    printf("Concat kedua ListDin secara terurut: ");printList(l1);printf("\n");

    dealocateList(&l1);
    dealocateList(&l2);
}