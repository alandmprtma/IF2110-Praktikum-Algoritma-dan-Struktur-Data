#include <stdio.h>
#include <stdbool.h>

bool inRange (float ip);

bool inRange (float ip)
{
    if (ip>=0 && ip<=4)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main ()
{
    float curr_ip;
    int totalmhs = 0;
    int mhslulus = 0;
    float totalip = 0;
    do
    {
        /* code */
        scanf("%f", &curr_ip);
        if (inRange(curr_ip) == true)
        {
            totalmhs++;
            totalip = totalip + curr_ip;
            if (curr_ip >= 2.75)
            {
                mhslulus++;
            }
        }
    } while (curr_ip != 999);
    if(totalmhs == 0)
    {
        printf("Tidak ada data");
    }
    else
    {
        printf("%d\n", totalmhs);
        printf("%d\n", mhslulus);
        printf("%d\n", totalmhs-mhslulus);
        printf("%.2f\n", totalip/totalmhs);
    }
}