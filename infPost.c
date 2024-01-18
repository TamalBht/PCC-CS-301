#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <ctype.h>
#define MAX 40
typedef struct Stack{
    char arr[MAX];
    int top;
}Stack;
void initial(Stack*s){
    s->top=-1;
}
int isEmpty(Stack* s){
    return(s->top==-1);
}
void push(Stack* s,char c){
    s->arr[++s->top]=c;   
}
char pop(Stack*s){
    return s->arr[s->top--];
}