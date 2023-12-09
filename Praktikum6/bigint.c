#include <stdio.h>
#include <math.h>
#include <string.h>
#include "stack.h"

int charToNum(char c) 
{
    return (c - '0');
}

char numToChar(int n) 
{
    return (n + '0');
}

boolean isGreater(char array1[100], char array2[100])
{
    int len1 = 0;
    int len2 = 0;

    while (array1[len1] != '\0') 
    {
        len1++;
    }

    while (array2[len2] != '\0') 
    {
        len2++;
    }

    if (len1 > len2) 
    {
        return true;
    }
    else if (len1 < len2) 
    {
        return false;
    }
    else 
    {
        int idx = 0; 
        while (idx < len1) 
        {
            if (array1[idx] > array2[idx]) 
            {
                return true;
            }
            else if (array1[idx] < array2[idx]) 
            {
                return false;
            }
            idx++;
        }
    }
    return true;
}

int main() 
{
    Stack stackA, stackB, stackMin;
    int val1, val2, result;
    int i = 0;
    int j = 0;
    char array1[100], array2[100];

    CreateEmpty (&stackA);
    CreateEmpty (&stackB);
    CreateEmpty (&stackMin);

    scanf("%s", array1);

    while (array1[i] != '\0') 
    {
        if (charToNum(array1[i]) >= 0) 
        {
            Push(&stackA, charToNum(array1[i]));
        }
        i++;
    }

    scanf("%s", array2);
    while (array2[j] != '\0')
    {
        if (charToNum(array2[j]) >= 0) 
        {
            Push(&stackB, charToNum(array2[j]));
        }
        j++;
    }

    int sisa = 0;
    if (isGreater(array1, array2)) 
    {
        while (!IsEmpty(stackB)) 
        {
            Pop(&stackA, &val1);
            Pop(&stackB, &val2);
            result = val1 - val2 + sisa;
            if (result < 0) 
            {
                sisa = -1; 
                result += 10;
                Push(&stackMin, result);
            }
            else 
            {
                sisa = 0;
                Push(&stackMin, result);
            }
        }

        while (!IsEmpty(stackA)) 
        {
            Pop(&stackA, &val1);
            result =  val1 + sisa;
            if (result < 0) 
            {
                sisa = -1; 
                result += 10;
                Push(&stackMin, result);
            }
            else 
            {
                sisa = 0; 
                Push(&stackMin, result);
            }
        }

        while (InfoTop(stackMin) == 0 && Top(stackMin) > 0) 
        {
            Pop(&stackMin, &val1);
        }
    }
    else 
    {
        while (!IsEmpty(stackA)) 
        {
            Pop(&stackA, &val1);
            Pop(&stackB, &val2);
            result = val2 - val1 + sisa;
            if (result < 0) 
            {
                sisa = -1; 
                result += 10; 
                Push(&stackMin, result);
            }
            else 
            {
                sisa = 0; 
                Push(&stackMin, result);
            }
        }

        while (!IsEmpty(stackB)) 
        {
            Pop(&stackB, &val2);
            result = val2 + sisa; 
            if (result < 0) 
            {
                sisa = -1; 
                result += 10; 
                Push(&stackMin, result);
            }
            else 
            {
                sisa = 0; 
                Push(&stackMin, result);   
            }
        }

        while (InfoTop(stackMin) == 0 && Top(stackMin) > 0) 
        {
            Pop(&stackMin, &val1);
        }
        if (InfoTop(stackMin) != 0) 
        {
            Pop(&stackMin, &val2);
            val2 *= -1; 
            Push(&stackMin, val2);
        }
    }

    int tempMinus;
    while (!IsEmpty(stackMin)) 
    {
        Pop(&stackMin, &tempMinus);
        printf("%c", numToChar(tempMinus));
    }
    printf("\n");

    return 0;
}