#include "bintree.h"

void invertBtree(BinTree *p)
/* I.S. Pohon p terdefinisi */
/* F.S. Pohop p diflip secara vertikal*/
{
    /* KAMUS */
    BinTree temp;

    /* ALGORITMA */
    if (!isTreeEmpty(*p)) {
        temp = LEFT(*p);
        LEFT(*p) = RIGHT(*p);
        RIGHT(*p) = temp;
        
        invertBtree(&LEFT(*p));
        invertBtree(&RIGHT(*p));
    }
}