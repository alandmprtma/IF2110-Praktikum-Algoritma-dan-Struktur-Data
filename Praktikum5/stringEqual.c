#include <stdio.h>
#include "wordmachine.h"
#include "charmachine.h"

boolean EndWord;
char currentchar;
Word currentWord;

int stringLength(char *s) {

   int result =  0;

   int i = 0;

   while (s[i] != '\0') {

      ++result;

      ++i;

   }

   return result;

}

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
    int n;

    scanf("%d ", &n);

    START();
    IgnoreBlanks();

    CopyWord();

    char c = currentWord.TabWord[4];
    if (c == 'U')
    {
        printf("Moving %d square upwards\n", n);
    }
    else if (c == 'D')
    {
        printf("Moving %d square downwards\n", n);
    }
    else if (c == 'L')
    {
        printf("Moving %d square leftwards\n", n);
    }
    else if (c == 'R')
    {
        printf("Moving %d square rightwards\n", n);
    }

    return 0;
}