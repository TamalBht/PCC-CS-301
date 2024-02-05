#include<stdio.h>
#include<stdlib.h>
#define MAX 100
typedef struct {
    int data;
    int priority;
}Element;
typedef struct{
    //making an array of Elements
    Element item[MAX];
    int size;
}Queue;
void initial(Queue* q){
    q->size=0;
}
int isFull(Queue* q){
    return (q->size==MAX);
}
int isEmpty(Queue* q){
    return(q->size==0);
}
