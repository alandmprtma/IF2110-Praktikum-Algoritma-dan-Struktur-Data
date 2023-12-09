#include <stdio.h>
#include "stack.h"
#include "wordmachine.h"
#include "charmachine.h"

void readWord(Word *input) {
    int i;
    START();
    IgnoreBlanks();

    (*input).Length = 0;
    i = 0;

    while ((currentChar != MARK) && (i < NMax)) {
        (*input).TabWord[i] = currentChar;
        ADV();
        i++;
    }

    (*input).Length = i;

    (*input).TabWord[i] = '\0';
}

int main (){
    Word kurung;
    Stack S;
    CreateEmpty(&S);
    readWord(&kurung);
    int i;
    int dalam = 0;
    int kedalaman = 0;
    for(i = 0; i < kurung.Length;i++)
    {
        if (kurung.TabWord[i] == '(')
        {
            Push(&S, kurung.TabWord[i]);
            dalam++;
            if (dalam > kedalaman)
            {
                kedalaman = dalam;   
            }
        }
        else if (kurung.TabWord[i]== ')')
        {
            int popChar;
            if(!IsEmpty(S)&&InfoTop(S)=='(')
            {
                Pop(&S, &popChar);
                dalam--;   
            }
            else
            {
                printf("%d\n", -1);
                return 0;
            }
        }
    }
    if (IsEmpty(S))
    {
        printf("%d\n", kedalaman);
    }
    else
    {
        printf("%d\n", -1);
    }
}