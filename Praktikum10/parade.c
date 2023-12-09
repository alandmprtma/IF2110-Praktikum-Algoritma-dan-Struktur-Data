#include <stdio.h>
#include "stacklinked.h"

int main(){
    int t; scanf("%d", &t);
    for (t; t > 0; t--){
        Stack datang, kecil, parkir;
        CreateStack(&datang);
        CreateStack(&kecil);
        CreateStack(&parkir);

        int n;
        scanf("%d", &n);
        int i;
        int arr[n];

        for ( i = 0; i < n; i++){
            int temp;
            scanf("%d", &temp);
            arr[n-i-1] = temp;
        }

        for (i = 0; i < n; i++){
            push(&datang, arr[i]);
        }
        boolean bisa = true;
        int current = 1;
        int buang;
        while ((length(datang) > 0 || length(kecil) > 0 )&& bisa)
        {
            if (!isEmpty(datang) ){
                if (TOP(datang) == current){
                    push(&parkir, TOP(datang));
                    pop(&datang, &buang);
                    current++;
                    continue;
                }
            } 
            
            if (!isEmpty(kecil)){
                if (TOP(kecil) == current){
                    push(&parkir, current);
                    pop(&kecil, &buang);
                    current++;
                    continue;
                }
            }

            if (!isEmpty(datang)){
                pop(&datang, &buang);
                push(&kecil, buang);
                continue;
            }
            bisa = false;
        }

        if (bisa){
            printf("yes\n");
        } else {
            printf("no\n");
        }
    }
}