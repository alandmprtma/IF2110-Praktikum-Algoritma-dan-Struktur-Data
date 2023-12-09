#include <stdio.h>
#include "queue.h"

int main (){
    int N;
    int rev;
    Queue q1;
    CreateQueue(&q1);
    Queue q2;
    CreateQueue(&q2);
    int reverse[100];
    scanf ("%d", &N);
    scanf ("%d", &rev);
    int i;
    for (i = 0; i < N; i++)
    {
        int val;
        scanf("%d", &val);
        enqueue(&q1,val);
    }
    for (i = 0; i < rev; i++)
    {
        int var;
        dequeue(&q1,&var);
        reverse[i] = var;
    }
    while (!isEmpty(q1))
    {
        int val;
        dequeue(&q1,&val);
        enqueue(&q2,val);
    }
    for (i = 0; i < rev; i++)
    {
        int var;
        var = reverse[rev-1-i];
        enqueue(&q1,var);
    }
    while (!isEmpty(q2))
    {
        int val;
        dequeue(&q2,&val);
        enqueue(&q1,val);
    }
    displayQueue(q1);
}