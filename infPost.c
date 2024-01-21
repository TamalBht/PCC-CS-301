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
int isOperator(char c){
    return(c=='+'||c=='-'||c=='*'||c=='/'||c=='^');
}
int precedence(char c){
    if(c=='+'||c=='-'){
        return 1;
    }
    else if(c=='*'||c=='/'){
        return 2;
    }
    else if(c=='^'){
        return 3;
    }
    else{
        printf("Invalid operator");
        exit(0);
    }
}
//in this we are dealing with two strings 
//the first one is the expression that the user will provide and the second one is the postfix expression in which it will be pushed
void inf2pf(char *exp,char *post){
    Stack stack;
    initial(&stack);
    char popped;
    int i,j=0;
    for(i=0;exp[i]!='\0';i++){
        char c=exp[i];
        if(isalnum(c)){
            post[j++]=c;
        }
        else if(c=='('){
            push(&stack,c);
        }
        else if(isOperator(c)){
            while(isOperator(stack.arr[stack.top]) && precedence(c)<=precedence(stack.arr[stack.top]) && stack.top!=-1){
				post[j++]=pop(&stack);
			}
			push(&stack,c);
        }
        
    }
}