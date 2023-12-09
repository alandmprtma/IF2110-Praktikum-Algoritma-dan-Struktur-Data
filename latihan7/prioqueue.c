#include "prioqueue.h"

/* *** Kreator *** */
void CreatePrioQueue(PrioQueue *pq)
/* I.S. sembarang */
/* F.S. Sebuah pq kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah pq kosong */
{
    /* KAMUS */

    /* ALGORITMA */
    IDX_HEAD(*pq) = IDX_UNDEF;
    IDX_TAIL(*pq) = IDX_UNDEF;
}

boolean isEmpty(PrioQueue pq)
/* Mengirim true jika pq kosong: lihat definisi di atas */
{
    /* KAMUS */

    /* ALGORITMA */
    return ((IDX_HEAD(pq) == IDX_UNDEF) && (IDX_TAIL(pq) == IDX_UNDEF));
}

boolean isFull(PrioQueue pq)
/* Mengirim true jika tabel penampung elemen pq sudah penuh */
/* yaitu jika index head bernilai 0 dan index tail bernilai CAPACITY-1 */
{
    /* KAMUS */

    /* ALGORITMA */
    return ((IDX_HEAD(pq) == 0) && (IDX_TAIL(pq) == CAPACITY - 1));
}

int length(PrioQueue pq)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika pq kosong. */
{
    /* KAMUS */
    int N;

    /* ALGORITMA */

    if (isEmpty(pq)) {
        N = 0;
    } else {
        N = IDX_TAIL(pq) - IDX_HEAD(pq) + 1;
    }

    return N;
}

/*** Primitif Add/Delete ***/
void enqueue(PrioQueue *pq, ElType val)
/* Proses: Menambahkan val pada pq dengan aturan FIFO */
/* I.S. pq mungkin kosong, tabel penampung elemen pq TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur".
        Jika q penuh semu, maka perlu dilakukan aksi penggeseran "maju" elemen-elemen pq
        menjadi rata kiri untuk membuat ruang kosong bagi TAIL baru  */
{
    /* KAMUS */
    int i;
    ElType temp;

    /* ALGORITMA */
    if (isEmpty(*pq)) {
        IDX_HEAD(*pq) = 0;
        IDX_TAIL(*pq) = 0;
    } else {
        if (IDX_TAIL(*pq) == CAPACITY - 1) {
            for (i = IDX_HEAD(*pq); i <= IDX_TAIL(*pq); i++) {
                pq->buffer[i - IDX_HEAD(*pq)] = pq->buffer[i];
            }
            IDX_TAIL(*pq) -= IDX_HEAD(*pq);
            IDX_HEAD(*pq) = 0;
        }
        IDX_TAIL(*pq)++;
    }
    TAIL(*pq) = val;

    i = IDX_TAIL(*pq);

    while ((i > 0) && (pq->buffer[i - 1].score < pq->buffer[i].score) || ((pq->buffer[i - 1].score == pq->buffer[i].score) && (pq->buffer[i - 1].tArrival > pq->buffer[i].tArrival))) {
        temp = pq->buffer[i - 1];
        pq->buffer[i - 1] = pq->buffer[i];
        pq->buffer[i] = temp;
        i--;
    }
}

void dequeue(PrioQueue * pq, ElType *val)
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. pq tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd
I.S., HEAD dan IDX_HEAD "mundur"; 
        pq mungkin kosong */
{
    /* KAMUS */

    /* ALGORITMA */
    *val = HEAD(*pq);

    if (IDX_HEAD(*pq) == IDX_TAIL(*pq)) {
        IDX_HEAD(*pq) = IDX_UNDEF;
        IDX_TAIL(*pq) = IDX_UNDEF;
    } else {
        IDX_HEAD(*pq)++;
    }
}