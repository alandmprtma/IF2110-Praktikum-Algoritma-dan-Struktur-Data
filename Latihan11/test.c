#include <stdio.h>

typedef union { 
    char c; 
    char *p; 
    int i; 
    short s;
} union1;

typedef struct { 
    char c; 
    union1 u; 
    int i; 
    short s;
} struct1;

int main() {
    printf("Size of struct: %zu bytes\n", sizeof(struct struct1));
    printf("Address of c: %p\n", (void*)&((struct struct1*)0)->c);
    printf("Address of u: %p\n", (void*)&((struct struct1*)0)->u);
    printf("Address of i: %p\n", (void*)&((struct struct1*)0)->i);
    printf("Address of s: %p\n", (void*)&((struct struct1*)0)->s);
    return 0;
}