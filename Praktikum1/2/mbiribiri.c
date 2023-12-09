#include <stdio.h>
#include <math.h>
#include "garis.h"

int main(){
    POINT P1, P2;
    GARIS L1;
    int i,b,n;

    // Input
    scanf("%d",&b);
    BacaPOINT(&P1);
    BacaPOINT(&P2);
    CreateGaris(&L1, P1, P2);
    scanf("%d",&n);
    POINT domba[n];
    for (i = 0; i < n; i++){
        BacaPOINT(&domba[i]);
    }
    // Algorithm
    int jumlah = 0;
    for (i = 0; i < n; i++){
        if (JarakGARIS(L1, domba[i])<=b){
            jumlah++;
        }
    }
    printf("%d\n",jumlah);
    return 0;
}
