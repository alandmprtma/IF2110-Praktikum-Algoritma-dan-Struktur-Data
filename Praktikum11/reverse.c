#include <stdio.h>
#include "listrec.h"

void cutList(List l, List* l1, List* l2, int count) {
    if (!count) {
        *l2 = l;
    } else {
        *l1 = konsb(*l1, head(l));
        cutList(tail(l), l1, l2, count - 1);
    }
}

List reverseList(List l) {
    if (isOneElmt(l) || isEmpty(l)) {
        return l;
    } else {
        return konsb(reverseList(tail(l)), head(l));
    }
}

int main() {
    int len;
    scanf("%d", &len);

    List mhs = NULL;
    int i;
    for (i = 0; i < len; i++) {
        int x;
        scanf("%d", &x);
        mhs = konsb(mhs, x);
    }

    int q;
    scanf("%d", &q);
    int j;
    for (j = 0; j < q; j++) {
        int cut;
        scanf("%d", &cut);

        List l1 = NULL;
        List l2 = NULL;
        cutList(mhs, &l1, &l2, cut);
        l1 = reverseList(l1);
        l2 = reverseList(l2);
        mhs = concat(l1, l2);
    }
    displayList(mhs);
    
    return 0;
}