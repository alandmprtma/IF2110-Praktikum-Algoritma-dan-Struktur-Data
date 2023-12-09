#include <stdio.h>
#include "matrix.h"

int main() {
    Matrix m1, sub;
    int n, m, x, O = 0, b = 0;

    scanf("%d %d", &n, &m);
    readMatrix(&m1, n, m);

    scanf("%d", &x);

    for (int i = 0; i < x; i++) {
        scanf("%d %d", &n, &m);
        readMatrix(&sub, n, m);
        for (int p = 0; p < ROW_EFF(m1); p++) {
            for (int q = 0; q < COL_EFF(m1); q++) {
                if (ELMT(m1, p, q) == ELMT(sub, 0, 0)) {
                    for (int t = 0; t < ROW_EFF(sub); t++) {
                        for (int y = 0; y < COL_EFF(sub); y++) {
                            if (ELMT(sub, t, y) == ELMT(m1, p+t, q+y)) {
                            b ++ ;
                            }
                        }
                    }
                    if (b == ROW_EFF(sub) * COL_EFF(sub)){
                        O ++;
                    }
                    b = 0;

                }
            }
        }

    }

    if (O == x) {
        printf("Puzzle dapat diselesaikan.\n");
    } else {
        printf("Puzzle tidak dapat diselesaikan.\n");

    }
}