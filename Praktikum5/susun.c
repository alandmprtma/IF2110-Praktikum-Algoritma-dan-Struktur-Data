#include <stdio.h>
#include "charmachine.h"
#include "wordmachine.h"


boolean isGreater(Word word1, Word word2) {
    int i = 0;
    while (i < word1.Length && i < word2.Length) {
        if (word1.TabWord[i] != word2.TabWord[i]) {
            return word1.TabWord[i] < word2.TabWord[i];
        }
        i++;
    }
    return word1.Length < word2.Length;
}


void printWord(Word word) {
   int i;
   for (i = 0; i < word.Length; i++) {
      printf("%c", word.TabWord[i]);
   }
}

void sortingstr(Word words[], int n) {
    int i, j;
    Word temp;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (isGreater(words[j + 1], words[j])) {
                temp = words[j];
                words[j] = words[j + 1];
                words[j + 1] = temp;
            }
        }
    }
}

int main() {
    Word input[100];
    STARTWORD();
    int i = 0;
    
    while (!EndWord) {
        for (int j = 0; j < currentWord.Length; j++) {
            input[i].TabWord[j] = currentWord.TabWord[j];
        }
        input[i].Length = currentWord.Length;
        IgnoreBlanks();
        CopyWord();
        if (currentChar == MARK) {
            EndWord = true;
        }
        i++;
    }

    sortingstr(input, i);

    for (int j = 0; j < i; j++) {
        printWord(input[j]);
        printf("\n");
    }
    
    return 0;
}