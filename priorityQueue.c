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

void enqueue(Queue* q){
    if (isFull(q)) {
        printf("Queue is full. Enqueue operation failed.\n");
        return;
    }
    int inp,p;
    printf("Enter data and pririty followed by a space: ");
    scanf("%d%d",&inp,&p);
    Element newEle;
    newEle.data=inp;
    newEle.priority=p;
    //now in priority queue elements are enqueued or dequeued based on priority
    //so well run a while loop from the end to the start till the priority of new element is less thaan the existing priority element
    int i=q->size-1;
    while(newEle.priority>q->item[i].priority && i>=0){
        
    }

}