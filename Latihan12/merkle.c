#include "bintree.h"
#include <stdio.h>

BinTree NewMerkleTree(int level) {
    /* KAMUS */
    BinTree p1, p2;
    ElType val;
    
    /* ALGORITMA */
    if (level == 0) {
        scanf("%d", &val);
        return newTreeNode(val);
    } else {
        p1 = NewMerkleTree(level - 1);
        p2 = NewMerkleTree(level - 1);
        return NewTree(ROOT(p1) + ROOT(p2), p1, p2);
    }
}

int main() {
    /* KAMUS */
    int N, level;
    BinTree p;

    /* ALGORITMA */
    scanf("%d", &N);

    level = 0;
    while (N % 2 == 0 && N > 1) {
        N = N / 2;
        level++;
    }

    if (N != 1) {
        printf("Jumlah masukan tidak sesuai\n");
    } else {
        p = NewMerkleTree(level);
        printTree(p, 2);
    }
}