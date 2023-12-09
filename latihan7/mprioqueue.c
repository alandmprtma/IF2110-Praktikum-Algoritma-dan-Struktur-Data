#include "prioqueue.h"
#include <stdio.h>

int main() {
    /* KAMUS */
    PrioQueue pq;
    ElType *arrVal, processed;
    int i, t, N;

    /* ALGORITMA */
    scanf("%d", &N);
    CreatePrioQueue(&pq);

    if (N == 0) {
        printf("Tidak ada layanan\n");
    } else {
        arrVal = (ElType *) malloc(N * sizeof(ElType));
        
        for (i = 0; i < N; i++) {
            scanf("%d %d %d %d", &(arrVal[i].tArrival), &(arrVal[i].id), &(arrVal[i].score), &(arrVal[i].dService));
        }

        i = 0;
        t = 0;
        processed.id = 0;
        processed.tArrival = 0;
        processed.score = -1;
        processed.dService = 0;

        while ((i < N) || ((processed.id != 0) && (processed.tArrival != 0) && (processed.score != -1) && (processed.dService != 0)) || !(isEmpty(pq))) {
            if (arrVal[i].tArrival == t) { // Masuk antrian
                enqueue(&pq, arrVal[i]);
                i++;
            }

            if ((processed.id == 0) && (processed.tArrival == 0) && (processed.score == -1) && (processed.dService == 0) && !(isEmpty(pq))) { // Jika tidak ada yang dilayani, keluar dari antrian
                dequeue(&pq, &processed);
                printf("%d %d %d\n", t, processed.id, t - processed.tArrival);
            }
            
            if ((processed.id != 0) && (processed.tArrival != 0) && (processed.score != -1) && (processed.dService != 0)) { // Waktu pelayanan berkurang
                processed.dService -= 1;
            }

            if ((processed.id != 0) && (processed.tArrival != 0) && (processed.score != -1) && (processed.dService == 0)) { // Beres dilayani jika waktu pelayanan habis
                processed.id = 0;
                processed.tArrival = 0;
                processed.score = -1;
                processed.dService = 0;
            }

            t++; // Waktu terus bertambah
        }
    }
}