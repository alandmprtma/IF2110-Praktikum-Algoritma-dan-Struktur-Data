#include <stdio.h>
#include "wordmachine.h"
#include "charmachine.h"

// Prints word from Mesin Kata
void printWord(Word word)
{
    int i;
    for (i = 0; i < word.Length; i++)
    {
        printf("%c", word.TabWord[i]);
    }
}

boolean isAnagram(Word word1, Word word2)
{
    int num1[26] = {0};
    int num2[26] = {0};
    int i, j;
    for (i = 0; i < word1.Length; i++)
    {
        num1[word1.TabWord[i] - 'a']++;
    }
    for (j = 0; j < word2.Length; j++)
    {
        num2[word2.TabWord[j] - 'a']++;
    }
    int k;
    for (k = 0; k < 26; k++)
    {
        if (num2[k] != num1[k])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    Word kata[100];
    int count = 0;
    STARTWORD();
    while (!EndWord)
    {
        kata[count] = currentWord;
        count++;
        ADVWORD();
    }
    int countAnagram = 0;
    int i, j;
    for (i = 0; i < count - 1; i++)
    {
        for (j = i + 1; j < count; j++)
        {
            if (isAnagram(kata[i], kata[j]))
            {
                countAnagram++;
            }
        }
    }
    printf("%d\n", countAnagram);
    return 0;
}