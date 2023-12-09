#include <stdio.h>
#include "queue.h"

float average (Queue q){
    float average;
    int i;
    ElType temp;
    int sum = 0;
    int len =length(q);
    for (i =0;i <len;i++){
        dequeue(&q,&temp);
        sum += temp;
    }
    average = sum/len;
    return average;
}

int main (){
    int command;
    ElType waktu;
    Queue q;

    CreateQueue(&q);

    scanf ("%d",&command);
    while (command != 0){
        if (command == 1){
            scanf ("%d",&waktu);
            if (!isFull(q)){
                enqueue(&q, waktu);    
            }

            else{
                printf("Queue Penuh\n");
            }
        }

        else if (command ==2){
            int temp;
            if (!isEmpty(q)){
                dequeue(&q,&temp);
            }
            else{
                printf("Queue kosong\n");
            }
        }

        scanf("%d",&command);
    }
    printf("%d\n",length(q));
    if (length(q) == 0){
        printf("Tidak bisa dihitung");
    }
    else{
        printf("%.2f\n",average(q));
    }
}