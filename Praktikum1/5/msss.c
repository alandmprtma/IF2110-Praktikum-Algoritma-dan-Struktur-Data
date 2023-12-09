#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "point.h"


int main() {
    POINT a,b,c;
    BacaPOINT(&a);
    BacaPOINT(&b);
    BacaPOINT(&c);
    float y1 = Ordinat(c)-Ordinat(b),
    y2 = Ordinat(b)-(Ordinat(a)),
    b1 = Absis(c)-Absis(b),
    b2 = Absis(b)-Absis(a),
    c1 = pow(Absis(c),2)-pow(Absis(b),2),
    c2 = pow(Absis(b),2)-pow(Absis(a),2);

    float tempc = c2*b1/b2,
    tempy = y2*b1/b2;

    float cc = (y1-tempy)/(c1-tempc),
    bb = (tempy-(tempc*cc))/b1,
    aa = Ordinat(a)-(Absis(a)*bb)-(pow(Absis(a),2)*cc);

    printf("%.0f\n", aa);
    return 0;
}