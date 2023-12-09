#include <stdio.h>

int main()
{
    int m, n, i;
    scanf("%d", &m);
    scanf("%d", &n);
    for(i = 1; i <= m; i++)
    {
        if(i%n == 0)
        {
            printf("happy\n");
        }
        else
        {
            printf("%d\n", i);
        }
    }
    return 0;
}