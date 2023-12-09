/*Latihan Praktikum 10*/
/*Sandwich Butak (Bulat & Kotak)*/

#include <stdio.h>
#include "queuelinked.h"
#include "charmachine.h"

boolean isElHomogen(Queue q){
    Address P = ADDR_HEAD(q);
    int x = INFO(P); 
    while (P != NULL) {
        if (INFO(P) != x) {
            return false;
        }
        P = NEXT(P);
    }
    return true;
}

int main(){
    Queue qsiswa;
    Queue qsandwich;
    Queue nomorsiswa;
    CreateQueue(&qsiswa);
    CreateQueue(&qsandwich);
    CreateQueue(&nomorsiswa);
    START();
    int count = 0;
    while(currentChar != ','){
        if(currentChar == 'K') //k = 1
        {
            enqueue(&qsiswa, 1);
        }
        if (currentChar == 'B')
        {
            enqueue(&qsiswa, 0);
        }
        count++;
        enqueue(&nomorsiswa,count);
        ADV();
    }
    ADV();
    while(!EOP){
        if(currentChar == 'K') //k = 1
        {
            enqueue(&qsandwich, 1);
        }
        if (currentChar == 'B')
        {
            enqueue(&qsandwich, 0);
        }
        ADV();
    }
    int hitung = 0;
    while(!isEmpty(qsandwich) && !isEmpty(qsiswa) && !(isElHomogen(qsiswa) && HEAD(qsiswa) != HEAD(qsandwich))){
        if(HEAD(qsiswa) == HEAD(qsandwich)){
            int val;
            int nosiswa;
            dequeue(&qsiswa, &val);
            dequeue(&qsandwich, &val);
            dequeue(&nomorsiswa, &nosiswa);
            if(val == 1){
                printf("%d -> kotak\n", nosiswa);
            }
            else if (val == 0){
                printf("%d -> kotak\n", nosiswa);
            }
            hitung++;
        }
        else{
            int val;
            dequeue(&qsiswa, &val);
            enqueue(&qsiswa, val);
            dequeue(&nomorsiswa, &val);
            enqueue(&nomorsiswa, val);
        }
    }
    printf("%d\n", count - hitung);
}
