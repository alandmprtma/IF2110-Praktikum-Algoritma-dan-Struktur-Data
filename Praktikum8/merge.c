#ifndef merge_H
#define merge_H

#include <stdio.h>
#include "listlinier.h"
#include "merge.h"
#include "boolean.h"

void splitList(List source, List* front, List* back) {
    int len = length(source);
    int frontBound = (len % 2) ? (len / 2) : ((len / 2) - 1);

    List p = source;
    int i;
    for (i = 0; i < len; i++) {
        if (i <= frontBound) {
            insertLast(front, INFO(p));
        } else {
            insertLast(back, INFO(p));
        }
        p = NEXT(p);
    }
}
/* Fungsi untuk memecah sebuah list dengan head source menjadi dua buah 
   list baru, yaitu front dan back. Apabila panjang list ganjil, maka
   list front akan lebih panjang dibandingkan list back.
   Sebagai contoh untuk list dengan panjang 5, maka list front memiliki
   3 elemen dan list back memiliki 2 elemen.
*/

List merge(List a, List b) {
    List res;
    CreateList(&res);

    if (a == NULL) return b;
    else if (b == NULL) return a;
    else {
        List tempA = a;
        List tempB = b;
        ElType val;

        // Loop until tempA is empty or tempB is empty
        while ((tempA != NULL) && (tempB != NULL)) {
            if (INFO(tempA) <= INFO(tempB)) 
                deleteFirst(&tempA, &val);
            else 
                deleteFirst(&tempB, &val);
            
            insertLast(&res, val);
        }

        // Empty TempA
        while (tempA != NULL) {
            deleteFirst(&tempA, &val);
            insertLast(&res, val);
        }

        // Empty TempB
        while (tempB != NULL) {
            deleteFirst(&tempB, &val);
            insertLast(&res, val);
        }

        return res;
    }
}
/* Fungsi untuk melakukan merge sort list a dan b secara rekursif.
   Sort dilakukan secara ascending berdasarkan nilai elemen.
   Apabila List a = NULL, maka kembalikan List b
   Apabila List b = NULL, maka kembalikan List a
   Selain itu, lakukan perbandingan antara INFO(a) dengan 
   INFO(b) untuk mendapatkan urutannya
*/

void mergeSort(List* list) {
    displayList(*list); printf("\n");
    if (length(*list) > 1) {
        
        List front; CreateList(&front);
        List back; CreateList(&back);

        splitList(*list, &front, &back);
        mergeSort(&front);
        mergeSort(&back);

        List merged = merge(front, back);
        *list = merged;
    }
}
/* Fungsi untuk melakukan inisialisasi merge sort secara rekursif.
   Setiap kali fungsi dipanggil, maka tampilkan list yang sekarang
   sedang diproses.
   Apabila head atau NEXT(head) kosong, maka lakukan return
   Fungsi akan membagi list menjadi dua terlebih dahulu, kemudian 
   secara rekursif melakukan merge untuk mengurutkan
*/

#endif