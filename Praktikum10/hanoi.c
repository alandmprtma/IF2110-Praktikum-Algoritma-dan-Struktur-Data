#include <stdio.h>
#include "stacklinked.h"



int main (){
    Stack tower1;
    Stack tower2;
    Stack tower3;
    CreateStack(&tower1);
    CreateStack(&tower2);
    CreateStack(&tower3);
    int i;
    for (i = 5; i > 0; i--){
        push(&tower1, i);
    }
    int N;
    scanf("%d", &N);
    for (i = 0; i < N; i++){
        int asal, tujuan;
        scanf("%d %d", &asal, &tujuan);
        if (asal == 1 && tujuan == 2){
            if (isEmpty(tower1)){
                printf("Menara kosong\n");
            }
            else{
                int val;
                pop(&tower1, &val);
                if (!isEmpty(tower2) && val > TOP(tower2))
                {
                    push(&tower1, val);
                    printf("Piringan tidak dapat dipindah\n");
                }
                else{
                    push(&tower2, val);
                }
            }
        }
        else if (asal == 1 && tujuan == 3){
            if (isEmpty(tower1)){
                printf("Menara kosong\n");
            }
            else{
                int val;
                pop(&tower1, &val);
                if (!isEmpty(tower3) && val > TOP(tower3))
                {
                    push(&tower1, val);
                    printf("Piringan tidak dapat dipindah\n");
                }
                else{
                    push(&tower3, val);
                }
            }

        }
        else if (asal == 2 && tujuan == 1){
            if (isEmpty(tower2)){
                printf("Menara kosong\n");
            }
            else{
                int val;
                pop(&tower2, &val);
                if (!isEmpty(tower1) && val > TOP(tower1))
                {
                    push(&tower2, val);
                    printf("Piringan tidak dapat dipindah\n");
                }
                else{
                    push(&tower1, val);
                }
            }

        }
        else if (asal == 2 && tujuan == 3){
            if (isEmpty(tower2)){
                printf("Menara kosong\n");
            }
            else{
                int val;
                pop(&tower2, &val);
                if (!isEmpty(tower3) && val > TOP(tower3))
                {
                    push(&tower2, val);
                    printf("Piringan tidak dapat dipindah\n");
                }
                else{
                    push(&tower3, val);
                }
            }
        }
        else if (asal == 3 && tujuan == 1){
            if (isEmpty(tower3)){
                printf("Menara kosong\n");
            }
            else{
                int val;
                pop(&tower3, &val);
                if (!isEmpty(tower1) && val > TOP(tower1))
                {
                    push(&tower3, val);
                    printf("Piringan tidak dapat dipindah\n");
                }
                else{
                    push(&tower1, val);
                }
            }

        }
        else if (asal == 3 && tujuan == 2){
            if (isEmpty(tower3)){
                printf("Menara kosong\n");
            }
            else{
                int val;
                pop(&tower3, &val);
                if (!isEmpty(tower2) && val > TOP(tower2))
                {
                    push(&tower3, val);
                    printf("Piringan tidak dapat dipindah\n");
                }
                else{
                    push(&tower2, val);
                }
            }
        }
    }
    printf("Menara 1: ");
    DisplayStack(tower1);
    printf("\n");
    printf("Menara 2: ");
    DisplayStack(tower2);
    printf("\n");
    printf("Menara 3: ");
    DisplayStack(tower3);
    printf("\n");
}

