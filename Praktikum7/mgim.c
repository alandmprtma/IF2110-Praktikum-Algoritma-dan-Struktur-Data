#include <stdio.h>
#include "boolean.h"
#include "queue.h"
#include "math.h"

int max2(int a, int b) {
    int res;
    (a > b) ? (res = a) : (res = b);
    return res;
}

int findSmallestSteps(int N) {

    int k = 0;

    Queue qNums; CreateQueue(&qNums);
    Queue qSteps; CreateQueue(&qSteps);

    enqueue(&qNums, N);
    enqueue(&qSteps, 0);

    boolean found = false;

    int valNum, valStep, quotient;
    while (!found) {

        dequeue(&qNums, &valNum);
        dequeue(&qSteps, &valStep);

        if (valNum == 0) {
            found = true;
        }

        else {
            enqueue(&qNums, valNum - 1);
            enqueue(&qSteps, valStep + 1);

            int i;
            int sqNum = sqrt(valNum);
            for (i = 2; i <= sqNum; i++) {
                if (valNum % i == 0) {
                    quotient = valNum / i;
                    if (!isFull(qNums)) {
                        enqueue(&qNums, max2(i, quotient));
                        enqueue(&qSteps, valStep + 1);
                    }
                }
            }
        }
    }

    return valStep;
}

int main() {
    int n, num, res = 1;
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &num);
        res *= findSmallestSteps(num);
    }
    printf("%d\n", res);
}