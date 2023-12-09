#include <stdio.h>
#include <stdlib.h>
#include "list_linked.h"
#include "listlinier.h"

void CreateList(List *l)
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
{
    FIRST(*l) = NULL;
}

boolean isEmpty(List l)
/* Mengirim true jika list kosong */
{
    return FIRST(l) == NULL;
}

ElType getElmt(List l, int idx)
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengembalikan nilai elemen l pada indeks idx */
{
    /* KAMUS */
    Address p;
    int i;

    /* ALGORITMA */
    i = 0;
    p = FIRST(l);

    while (i < idx) {
        p = NEXT(p);
        i++;
    }

    return INFO(p);
}

void setElmt(List *l, int idx, ElType val)
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengubah elemen l pada indeks ke-idx menjadi val */
{
    Address p;
    int i;

    /* ALGORITMA */
    i = 0;
    p = FIRST(*l);

    while (i < idx) {
        p = NEXT(p);
        i++;
    }
    INFO(p) = val;
}

int indexOf(List l, ElType val)
/* I.S. l, val terdefinisi */
/* F.S. Mencari apakah ada elemen list l yang bernilai val */
/* Jika ada, mengembalikan indeks elemen pertama l yang bernilai val */
/* Mengembalikan IDX_UNDEF jika tidak ditemukan */
{
    Address p;
    int i;
    boolean found;

    /* ALGORITMA */
    i = 0;
    p = FIRST(l);
    found = false;

    while (p != NULL && found == false) {
        if (INFO(p) == val)
        {
            found = true;
        }
        else
        {
            p = NEXT(p);
            i++;
        }
    }
    if (found == true)
    {
        return i;
    }
    else{
        return IDX_UNDEF;
    }
}

void insertFirst(List *l, ElType val)
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai val jika alokasi berhasil. */
/* Jika alokasi gagal: I.S.= F.S. */
{
    /* KAMUS */
    Address p;

    /* ALGORITMA */
    p = newNode(val);
    if (p != NULL) {
        NEXT(p) = FIRST(*l);
        FIRST(*l) = p;
    }
}

void insertLast(List *l, ElType val)
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
    /* KAMUS */
    Address p, last;

    /* ALGORITMA */
    if (isEmpty(*l)) {
        insertFirst(l, val);
    } else {
        p = newNode(val);
        if (p != NULL) {
            last = FIRST(*l);
            while (NEXT(last) != NULL) {
                last = NEXT(last);
            }
            NEXT(last) = p;
        }
    }
}

void insertAt(List *l, ElType val, int idx)
/* I.S. l tidak mungkin kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menyisipkan elemen dalam list pada indeks ke-idx (bukan menimpa elemen di i) */
/* yang bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
    /* KAMUS */
    Address p, loc;
    int ctr;

    /* ALGORITMA */
    if (idx == 0) {
        insertFirst(l, val);
    } else {
        p = newNode(val);
        if (p != NULL) {
            ctr = 0;
            loc = FIRST(*l);
            while (ctr < idx - 1) {
                ctr++;
                loc = NEXT(loc);
            }
            NEXT(p) = NEXT(loc);
            NEXT(loc) = p;
        }
    }
}

/*** PENGHAPUSAN ELEMEN ***/
void deleteFirst(List *l, ElType *val)
/* I.S. List l tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen pertama di-dealokasi */
{
    /* KAMUS */
    Address p;

    /* ALGORITMA */
    p = FIRST(*l);
    *val = INFO(p);
    FIRST(*l) = NEXT(p);
    free(p);
}

void deleteLast(List *l, ElType *val)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen terakhir di-dealokasi */
{
    /* KAMUS */
    Address p, loc;

    /* ALGORITMA */
    p = FIRST(*l);
    loc = NULL;

    while (NEXT(p) != NULL) {
        loc = p;
        p = NEXT(p);
    }

    if (loc == NULL) {
        FIRST(*l) = NULL;
    } else {
        NEXT(loc) = NULL;
    }
    *val = INFO(p);
    free(p);
}


void deleteAt(List *l, int idx, ElType *val)
/* I.S. list tidak kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. val diset dengan elemen l pada indeks ke-idx. */
/*      Elemen l pada indeks ke-idx dihapus dari l */

{
    /* KAMUS */
    Address p, loc;
    int ctr;

    /* ALGORITMA */
    if (idx == 0) {
        deleteFirst(l, val);
     } else {
        ctr = 0;
        loc = FIRST(*l);

        while (ctr < idx - 1) {
            ctr++;
            loc = NEXT(loc);
        }
        p = NEXT(loc);
        *val = INFO(p);
        NEXT(loc) = NEXT(p);
        free(p);
    }
}


/****************** PROSES SEMUA ELEMEN LIST ******************/
void displayList(List l)
// void printInfo(List l);
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
    /* KAMUS */
    Address p;

    /* ALGORITMA */
    printf("[");
    p = FIRST(l);
    while (p != NULL) {
        if (NEXT(p) == NULL) {
            printf("%d", INFO(p));
        } else {
            printf("%d,", INFO(p));
        }
        p = NEXT(p);
    }
    printf("]");
}

int length(List l)
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
{
    /* KAMUS */
    Address p;
    int i;

    /* ALGORITMA */
    i = 0;
    p = FIRST(l);

    while (p != NULL) {
        i++;
        p = NEXT(p);
    }

    return i;
}

boolean fSearch(List L, Address P)
/* Mencari apakah ada elemen list yang beralamat P */
/* Mengirimkan true jika ada, false jika tidak ada */
{
    Address awal;
    boolean found;
    awal = FIRST(L);
    found = false;

    while (awal != NULL && found == false)
    {
        if(awal == P)
        {
            found == true;
        }
        else{
            awal = NEXT(awal);
        }
    }

    return found;
}

Address searchPrec(List L, ElType X)
/* Mengirimkan address elemen sebelum elemen yang nilainya=X */
/* Mencari apakah ada elemen list dengan Info(P)=X */
/* Jika ada, mengirimkan address Prec, dengan Next(Prec)=P dan Info(P)=X. */
/* Jika tidak ada, mengirimkan Nil */
/* Jika P adalah elemen pertama, maka Prec=Nil */
/* Search dengan spesifikasi seperti ini menghindari */
/* traversal ulang jika setelah Search akan dilakukan operasi lain */
{
    Address prec, current;
    boolean found;

    prec = NULL;
    current = FIRST(L);

    found = false;

    while (current != NULL && found == false)
    {
        if (INFO(current) == X)
        {
            found = true;
        }
        else{
            prec = current;
            current = NEXT(current);
        }
    }
    return prec;
}

ElType maxList(List l)
/* Mengirimkan nilai info(P) yang maksimum */
{
    Address p;
    ElType maks;

    p = FIRST(l);
    maks = INFO(p);
    while (p != NULL)
    {
        p = NEXT(l);
        if (INFO(p) >= maks)
        {
            maks = INFO(p);
        }
    }
    return maks;
}

Address adrMax(List l)
/* Mengirimkan address P, dengan info(P) yang bernilai maksimum */
{
    ElType maks;
    Address p;
    boolean found;

    maks = maxList(l);
    found = false;
    p = FIRST(l);
    while (p != NULL && found == false)
    {
        if(INFO(p) == maks)
        {
            found = true;
        }
        else{
            p = NEXT(p);
        }
    }
    return p;
}

ElType minList(List l)
/* Mengirimkan nilai info(P) yang minimum */
{
    Address p;
    ElType min;

    p = FIRST(l);
    min = INFO(p);
    while (p != NULL)
    {
        p = NEXT(l);
        if (INFO(p) <= min)
        {
            min = INFO(p);
        }
    }
    return min;
}

Address adrMin(List l)
/* Mengirimkan address P, dengan info(P) yang bernilai minimum */
{
    ElType min;
    Address p;
    boolean found;

    min = minList(l);
    found = false;
    p = FIRST(l);
    while (p != NULL && found == false)
    {
        if(INFO(p) == min)
        {
            found = true;
        }
        else{
            p = NEXT(p);
        }
    }
    return p;
}

float average(List l)
/* Mengirimkan nilai rata-rata info(P) */
{
    Address p;
    float average;
    int sum = 0;
    int count = 0;
    p = FIRST(l);
    while (p!=NULL)
    {
        sum += INFO(p);
        count++;
        p = NEXT(p);
    }
    average = sum/count;
}

void delAll(List *l)
/* Delete semua elemen list dan alamat elemen di-dealokasi */
{
    /* KAMUS */
    ElType val;

    /* ALGORITMA */

    while (!isEmpty(*l)) {
        deleteFirst(l, &val);
    }
}

void inverseList(List *l)
/* I.S. sembarang. */
/* F.S. elemen list dibalik : */
/* Elemen terakhir menjadi elemen pertama, dan seterusnya. */
/* Membalik elemen list, tanpa melakukan alokasi/dealokasi. */
{
    /* KAMUS */
    int i, N;
    ElType temp;

    /* ALGORITMA */

    N = length(*l);
    for (i = 0; i < N / 2; i++) {
        temp = getElmt(*l, i);
        setElmt(l, i, getElmt(*l, N - 1 - i));
        setElmt(l, N - 1 - i, temp);
    }
}

List fInverseList(List l)
/* Mengirimkan list baru, hasil invers dari L */
/* dengan menyalin semua elemen list. Alokasi mungkin gagal. */
/* Jika alokasi gagal, hasilnya list kosong */
/* dan semua elemen yang terlanjur di-alokasi, harus didealokasi */
{
    /* KAMUS */
    List lHasil;

    /* ALGORITMA */
    CreateList(&lHasil);
    cpAllocList(l, &lHasil);
    inverseList(&lHasil);
    
    return lHasil;
}

void copyList(List *l1, List *l2)
/* I.S. L1 sembarang. F.S. L2=L1 */
/* L1 dan L2 "menunjuk" kepada list yang sama.*/
/* Tidak ada alokasi/dealokasi elemen */
{
    /* KAMUS */

    /* ALGORITMA */
    CreateList(l2);
    FIRST(*l2) = FIRST(*l1);
}

List fCopyList(List l)
/* Mengirimkan list yang merupakan salinan L */
/* dengan melakukan alokasi. */
/* Jika ada alokasi gagal, hasilnya list kosong dan */
/* semua elemen yang terlanjur di-alokasi, harus didealokasi */
{
    /* KAMUS */
    List lHasil;
    Address p, prec, pHasil;
    boolean berhasil;

    /* ALGORITMA */
    lHasil = (Address) malloc(sizeof(Node));
    
    if (lHasil != NULL) {
        CreateList(&lHasil);

        berhasil = true;

        p = FIRST(l);
        prec = NULL;
        while (p != NULL && berhasil) {
            pHasil = newNode(INFO(p));
            if (pHasil != NULL) {
                if (prec == NULL) {
                    FIRST(lHasil) = pHasil;
                } else {
                    NEXT(prec) = pHasil;
                }
                p = NEXT(p);
            } else {
                delAll(&lHasil);
                berhasil = false;
            }
            prec = pHasil;
        }
    }

    return lHasil;
}

void cpAllocList(List lIn, List *lOut)
/* I.S. lIn sembarang. */
/* F.S. Jika semua alokasi berhasil,maka lOut berisi hasil copy lIn */
/* Jika ada alokasi yang gagal, maka lOut=Nil dan semua elemen yang terlanjur dialokasi, didealokasi */
/* dengan melakukan alokasi elemen. */
/* lOut adalah list kosong jika ada alokasi elemen yang gagal */
{
    /* KAMUS */

    /* ALGORITMA */
    CreateList(lOut);
    *lOut = fCopyList(lIn);
}

void splitList(List *l1, List *l2, List l)
/* I.S. l mungkin kosong */
/* F.S. Berdasarkan L, dibentuk dua buah list l1 dan l2 */
/* L tidak berubah: untuk membentuk l1 dan l2 harus alokasi */
/* l1 berisi separuh elemen L dan l2 berisi sisa elemen L */
/* Jika elemen L ganjil, maka separuh adalah length(L) div 2 */
{
    /* KAMUS */
    int i;
    Address p, pNew;

    /* ALGORITMA */
    CreateList(l1);
    CreateList(l2); 
    
    p = FIRST(l);

    i = 0;
    while (p != NULL) {
        pNew = newNode(INFO(p));
        if (pNew != NULL) {
            if (i < length(l) / 2) {
                insertLast(l1, INFO(pNew));
            } else {
                insertLast(l2, INFO(pNew));
            }
        }
        free(pNew);
        p = NEXT(p);
        i++;
    }
}