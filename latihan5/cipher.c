#include <stdio.h>
#include "wordmachine.h"

char geser (char currentChar, int x);

char geser (char currentChar, int x){
    return((((currentChar - 'A')+ x)%('Z'-'A'+1)) + 'A');
}

int main(){
    STARTWORD();
    int N = currentWord.Length;

    while(!EndWord){
        int i;
        for (i = 0; i < currentWord.Length; i++){
            printf("%c", geser(currentWord.TabWord[i], N));
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
