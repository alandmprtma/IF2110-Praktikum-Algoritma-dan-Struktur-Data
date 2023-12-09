#include <stdio.h>
#include "queue.h"

float average (Queue q)
{
    int panjang = length(q);
    float sum = 0;
    while (!isEmpty(q))
    {
        int var;
        dequeue(&q, &var);
        sum = sum + var;
    }
    float rata = sum/panjang;
    return rata;
}

int main(){
    Queue q, layan;
    CreateQueue(&q);
    CreateQueue(&layan);
    int command;
    do
    {
        scanf("%d", &command);
        if (command == 1)
        {
            int val;
            scanf("%d", &val);
            if(isFull(q))
            {
                printf("Queue penuh\n");
            }
            else
            {
                enqueue(&q, val);
            }
        }
        else if (command == 2)
        {
            if(isEmpty(q))
            {
                printf("Queue kosong\n");
            }
            else
            {
                int temp;
                dequeue(&q,&temp);
                enqueue(&layan,temp);
            }
        }
    } while (command != 0);

    printf("%d\n", length(layan));
    if (isEmpty(layan))
    {
        printf("Tidak bisa dihitung\n");
    }
    else{
        printf("%.2f\n", average(layan));
    }
}