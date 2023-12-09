#include <stdio.h>
#include "charmachine.h"
#include "wordmachine.h"

boolean EndWord;
char currentchar;
Word currentWord;

int printWord(Word word)
{
    int i;
    for (i = 0; i < word.Length; i++)
    {
        printf("%c", word.TabWord[i]);
    }
}

int main()
{
    int i = 0, tot;

    START();
    IgnoreBlanks();

    while (!EOP && i < NMax)
    {
        currentWord.TabWord[i] = currentChar;
        ADV();
        i++;
    }

    
    if (i >= NMax)
    {
        currentWord.Length = NMax;
    }
    else
    {
        currentWord.Length = i;
    }

    printWord(currentWord);
    printf("\n%d\n", currentWord.Length);
}
