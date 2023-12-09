#include "wordmachine.h"
#include <stdio.h>

int main() {
    /* KAMUS */
    int i;

    /* ALGORITMA */
    STARTWORD();

    while (!EndWord) {
        for (i = 0; i < currentWord.Length; i++) {
            printf("%c", currentWord.TabWord[i]);
        }
        if (currentChar = MARK){
            printf("%c", MARK);
        }
        else{
            printf(" ");
        }
        ADVWORD();
    }
    printf("\n");
}