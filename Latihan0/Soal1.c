#include <stdio.h>
#include <stdbool.h>

int main()
{
    float ip, pot;
    scanf("%f %f", &ip, &pot);
    if(ip >= 3.5)
    {
        printf("4");
    }
    else if (pot>=1 && pot<5 && ip >= 2)
    {
        printf("3");
    }
    else if (pot<1 && ip<3.5)
    {
        printf("1");
    }
    else if (pot>=1 && pot<5 && ip<2)
    {
        printf("2");
    }
    else{
        printf("0");
    }
}