#include <stdio.h>
#include "matrix.h"


int main(){
    Matrix m;
    readMatrix(&m, 8, 8);
    int cekhitamputih = 0;
    int counthitam = 0;
    int countputih = 0;
    int i,j;
    for (i = 0; i<8; i++)
    {
        for (j = 0;j<8; j++)
        {
            cekhitamputih++;
            if ((i%2 == 0) && (cekhitamputih%2 == 1) && (ELMT(m,i,j) == 1))
            {
                counthitam++;                
            } 
            if((i%2 == 0) && (cekhitamputih%2 == 0) && (ELMT(m,i,j) == 1))
            {
                countputih++;
            }
            if ((i%2 == 1) && (cekhitamputih%2== 1) && (ELMT(m,i,j) == 1))
            {
                countputih++;                
            } 
            if ((i%2 == 1) && (cekhitamputih%2 == 0) && (ELMT(m,i,j) == 1))
            {
                counthitam++;
            }
        }
        cekhitamputih = 0;
    }
    printf("%d %d\n", counthitam, countputih);
}