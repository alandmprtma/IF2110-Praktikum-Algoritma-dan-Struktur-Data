#include <stdio.h>
#include "charmachine.h"
#include "stacklinked.h"

int maksimum(int a, int b){
    if(a >= b){
        return a;
    }
    else if (b > a){
        return b;
    }
}

int main(){
    Stack parser;
    CreateStack(&parser);
    int countsiku = 0;
    int countbulat = 0;
    int counttegak = 0;
    int totaltegak = 0;
    int countkurawal = 0;
    int countsegitiga = 0;
    int maks = 0;
    START();
    boolean cek = true;
    while(!EOP){
        if(currentChar == '['){
            push(&parser, 0);
            DisplayStack(parser);
            printf("\n");
            maks = maksimum(maks, length(parser));
        }
        else if(currentChar == ']' && isEmpty(parser)){
            DisplayStack(parser);
            printf("\n");
            cek = false;
        }
        else if(currentChar == ']'){
            int val;
            pop(&parser, &val);
            if (val != 0){
                push(&parser, val);
            }
            else{
                countsiku++;
            }
            DisplayStack(parser);
            printf("\n");
            maks = maksimum(maks, length(parser));
        }
        else if(currentChar == '('){
            push(&parser, 1);
            DisplayStack(parser);
            printf("\n");
            maks = maksimum(maks, length(parser));
        }
        else if(currentChar == ')' && isEmpty(parser)){
            DisplayStack(parser);
            printf("\n");
            cek = false;
        }
        else if(currentChar == ')'){
            int val;
            pop(&parser, &val);
            if (val != 1){
                push(&parser, val);
            }
            else{
                countbulat++;
            }
            DisplayStack(parser);
            printf("\n");
            maks = maksimum(maks, length(parser));
        }
        else if(currentChar == '|' && totaltegak%2 == 0){
            push(&parser, 2);
            DisplayStack(parser);
            printf("\n");
            maks = maksimum(maks, length(parser));
            totaltegak++;
        }
        else if(currentChar == '|' && totaltegak%2 == 1){
            int val;
            pop(&parser, &val);
            totaltegak++;
            if (val != 2){
                push(&parser, val);
            }
            else{
                counttegak++;
            }
            DisplayStack(parser);
            printf("\n");
            maks = maksimum(maks, length(parser));
        }
        else if(currentChar == '{'){
            push(&parser, 3);
            DisplayStack(parser);
            printf("\n");
            maks = maksimum(maks, length(parser));
        }
        else if(currentChar == '}' && isEmpty(parser)){
            DisplayStack(parser);
            printf("\n");
            cek = false;
        }
        else if(currentChar == '}'){
            int val;
            pop(&parser, &val);
            if (val != 3){
                push(&parser, val);
            }
            else{
                countkurawal++;
            }
            DisplayStack(parser);
            printf("\n");
            maks = maksimum(maks, length(parser));
        }
        else if(currentChar == '<'){
            push(&parser, 4);
            DisplayStack(parser);
            printf("\n");
            maks = maksimum(maks, length(parser));
        }
        else if(currentChar == '>' && isEmpty(parser)){
            DisplayStack(parser);
            printf("\n");
            cek = false;
        }
        else if(currentChar == '>'){
            int val;
            pop(&parser, &val);
            if (val != 4){
                push(&parser, val);
            }
            else{
                countsegitiga++;
            }
            DisplayStack(parser);
            printf("\n");
            maks = maksimum(maks, length(parser));
        }
        ADV();
    }
    if(!isEmpty(parser) || !cek){
        printf("kurung tidak valid\n");
    }
    else{
        printf("kurung valid\n");
        printf("[%d] (%d) |%d| {%d} <%d>\n", countsiku, countbulat, counttegak, countkurawal, countsegitiga);
        printf("MAX %d\n", maks);
    }
}