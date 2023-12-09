#include <stdio.h>
#include <stdbool.h>

bool isValid(int n);
void belahketupat(int n);

bool isValid(int n)
{
    if(n>0 && n%2 == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void belahketupat(int n)
{
    for(int i = 0; i < n/2; i++)
    {
        for(int j = n/2 - i; j > 0; j--)
        {
            printf(" ");
        }
        for(int j = 0; j < 2*i+1; j++)
        {
            printf("*");
        }
        printf("\n");
    }
    for(int i = 0; i < n; i++)
    {
        printf("*");
    }
    printf("\n");
    for(int i = 0; i < n/2; i++)
    {
        for(int j = 0; j < i+1; j++)
        {
            printf(" "); 
        }
        for(int j = n/2-i*2; j>=0; j--)
        {
            printf("*");
        }
        printf("\n");
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d\n", n/2);
    if (isValid(n) == true)
    {
        belahketupat(n);
    }
    else
    {
        printf("Masukan tidak valid\n");
    }
    return 0;
}