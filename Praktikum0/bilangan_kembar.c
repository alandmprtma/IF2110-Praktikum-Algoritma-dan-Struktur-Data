#include <stdio.h>
#include <stdbool.h>

int main()
{
    int m,n,i, hitung, div;
    scanf("%d", &m);
    scanf("%d", &n);
    for(i = m; i<=n; i++)
    {
        if(i/10 == i%10)
        {
            hitung++;
        }
    }
    printf("%d\n",hitung);
    return 0;
}