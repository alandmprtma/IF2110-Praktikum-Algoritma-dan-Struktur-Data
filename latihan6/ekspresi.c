#include "stack.h"
#include "tokenmachine.h"
#include <stdio.h>
#include <math.h>

boolean isOperator() {
    /* KAMUS */

    /* ALGORITMA */
    return (currentToken.tkn != 'b');
}

int evaluate(int N1, int N2, char CC) {
    /* KAMUS */
    int hasil;

    /* ALGORITMA */
    switch (CC) {
        case '+':
            hasil = N1 + N2;
            break;
        case '-':
            hasil = N1 - N2;
            break;
        case '*':
            hasil = N1 * N2;
            break;
        case '/':
            hasil = N1 / N2;
            break;
        case '^':
            hasil = pow(N1, N2);
            break;
    }

    return hasil;
}

int main() {
    /* KAMUS */
    Stack S;
    ElType N1, N2;

    /* ALGORITMA */
    CreateStack(&S);

    startToken();

    if (endToken) {
        printf("Ekspresi kosong\n");
    } else {
        do {
            if (!isOperator()) {
                push(&S, currentToken.val);

                printf("%d\n", currentToken.val);
            } else {
                pop(&S, &N2);
                pop(&S, &N1);
                push(&S, evaluate(N1, N2, currentToken.tkn));

                printf("%d %c %d\n", N1, currentToken.tkn, N2);
                printf("%d\n", evaluate(N1, N2, currentToken.tkn));
            }
            advToken();
        } while (!endToken);
        printf("Hasil=%d\n", TOP(S));
    }
}