#include <stdio.h>
#include "boolean.h"
#include "matrix.h"

int main() 
{
    int N;
    int M;
    int K;
    scanf("%d %d %d", &N, &M, &K);

    Matrix matriks;
    readMatrix(&matriks, N, M);

    int maxTotal = 0;

    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < M; j++) 
        {
            for (int p = i; p < N; p++) 
            {
                for (int q = j; q < M; q++) 
                {
                    int total = 0;
                    for (int a = i; a <= p; a++) 
                    {
                        for (int b = j; b <= q; b++) 
                        {
                            total += ELMT(matriks, a, b);
                        }
                    }

                    int luas = (p - i + 1) * (q - j + 1);

                    if (luas == K && total > maxTotal) 
                    {
                        maxTotal = total;
                    }
                }
            }
        }
    }

    printf("%d\n", maxTotal);

    return 0;
}