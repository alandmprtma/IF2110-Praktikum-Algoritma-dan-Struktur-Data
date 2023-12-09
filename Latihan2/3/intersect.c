#include <stdio.h>
#include "liststatik.h"
#include "boolean.h"

int main(){
    ListStatik l1, l2, l;
    CreateListStatik(&l1);
    CreateListStatik(&l2);
    CreateListStatik(&l);
    readList(&l1);
    readList(&l2);

    if(!isEmpty(l1) && !isEmpty(l2)){
        int i,j, nim, count=0;
        for(i=0; i<listLength(l1); i++){
            for(j=0; j<listLength(l2); j++){
                if(ELMT(l1,i)==ELMT(l2,j)){
                    nim = ELMT(l1,i);
                    insertLast(&l, nim); // insertAt(&l, nim, i);   
                    count += 1;
                }
            }
        }
        sortList(&l, true);
        printf("%d\n", count);
        printList(l);

    } else {
        printf("0");
        printf("[]");
    }

    return 0;
}