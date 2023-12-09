#include <stdio.h>

int main()
{
    int n, biggest, second,i, curr;
    scanf("%d", &n);
    scanf("%d", &biggest);
    scanf("%d", &second);
    if (n > 2)
    {
        if(biggest < second)
        {
            int temp = second;
            second = biggest;
            biggest = temp;
        }
        for(i=0; i < n-2; i++)
        {
            scanf("%d", &curr);
            if (curr > biggest)
            {
                biggest = curr;
            }
            else if (curr < biggest && curr > second)
            {
                second = curr;
            }
        }
        printf("%d\n",second);
    }
    else
    {
        if(biggest >= second)
        {
            printf("%d\n",second);
        }
        else
        {
            printf("%d\n",biggest);
        }
    }
    return 0;
}
