#include <stdio.h>

int fibonacci (int n)
{
    printf("fibonacci(%d)\n", n);
    if (n==0)
    {
        return 0;
    }
    else if (n==1)
    {
        return 1;
    }
    else{
        return (fibonacci(n-1) + fibonacci(n-2));
    }
}

int main (){
    int input;
    scanf("%d", &input);
    int fib = fibonacci(input);
    printf("%d\n", fib);
}