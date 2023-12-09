#include <stdio.h>
#include "stack.h"
#include "stack.c"

int angka(char CC){
    return CC - 48;
}

char karakter (int Angka){
    return Angka + 48;
}

int main(){
    Stack s1, s2;
    CreateEmpty(&s1);
    CreateEmpty(&s2);
    infotype N1, N2;

    char CC1, CC2;
    int CC;
    do
    {
        scanf("%c", &CC1);
        if (CC1 != '#')
        {
            Push(&s1, angka(CC1));
        }
        Push(&s1, angka(CC1));
    } while (CC1 != '#');

    do
    {
        scanf("%c", &CC2);
        if (CC2 != '#')
        {
            Push(&s2, angka(CC2));
        }
    } while (CC2 != '#');

    //Proses Penjumlahan
    address imaks;
    boolean ss1 = false;
    boolean ss2 = false;
    if (Top(s1) > Top(s2))
    {
        imaks = Top(s2);
        ss1 = true;
    }
    else
    {
        imaks = Top(s1);
        ss2 = true;
    }

    boolean carry = false;
    boolean carry_final = false;

    int sum;
    int res;
    Stack hasil;
    CreateEmpty(&hasil);
    for (int i = 0; i < imaks; i++)
    {
        printf("N");
        Pop(&s1,&N1);
        Pop(&s2,&N2);
        if (carry)
        {
            sum = N1 + N2 + 1;
            res = sum%10;
        }
        else{
            sum = N1 + N2;
            res = sum%10;
        }
        printf("%d\n",res);
        Push(&hasil,res);
        if (sum/10 == 0)
        {
            carry = false;
        }
        else{
            carry = true;
        }
        if (i == imaks-1)
        {
            if (sum/10 == 0)
            {
                carry_final = false;
            }
            else{
                carry_final = true;
            }
        }
    }
    while (carry_final == true)
    {
        if (ss1)
        {
            if (!IsEmpty(s1))
            {
                printf("N");
                Pop(&s1, &N1);
                sum = N1 + 1;
                res = sum%10;
                Push(&hasil,res);
                if (sum/10 == 0)
                {
                    carry_final = false;
                }
                else
                {
                    carry_final = true;
                } 
            }
            else{
                Push(&hasil,1);
                carry_final = false;
            }
        }
        if (ss2)
        {
            if (!IsEmpty(s2))
            {
                Pop(&s2, &N1);
                sum = N1 + 1;
                res = sum%10;
                Push(&hasil,res);
                if (sum/10 == 0)
                {
                    carry_final = false;
                }
                else
                {
                    carry_final = true;
                }  
            }
            else{
                printf("N");
                Push(&hasil, 1);
                carry_final = false;
            }
        }
    }
    if (ss1)
    {
        while(!IsEmpty(s1))
        {
            printf("N");
            int N;
            Pop(&s1, &N);
            Push(&hasil,N);
        }
    }
    if (ss2)
    {
        while(!IsEmpty(s2))
        {
            printf("N");
            int N;
            Pop(&s2, &N);
            Push(&hasil, N);
        }
    }

    while(!IsEmpty(hasil))
    {
        Pop(&hasil, &CC);
        printf("%c", karakter(CC));
    }
    printf("\n");
}