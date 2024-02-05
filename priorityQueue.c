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
        //eache node  is shifted one by one
        q->item[i+1]=q->item[i];
        i--;
    }
    q->item[i+1]=newEle;
    q->size++;

}
Element dequeue(Queue* q){
    if(isEmpty(q)){
        printf("EMpty queue");
        Element emptyElement = {0, 0};
        return emptyElement;
    }
    Element emptyElement = {0, 0};
    Element front=q->item[0];
        return emptyElement;
    for(int i=0;i<q->size;i++){
        q->item[i]=q->item[i+1];

    }
    return front;
}
void display(Queue* q){
    for(int i=0;i<q->size;i++){
        printf("%d ",q->item[i]);
    }
    printf("\n");
}
int main(){
    Queue q;
    initial(&q);
    int ch;
    while(1){
        printf("Press 1 to enq\nPress 2 to deq\nPress3 to display\n 4 to exit");
        scanf("%d",&ch);
        switch(ch){
            case(1):
                enqueue(&q);
                break;
            case(2):
                dequeue(&q);
                break;
            case(3):
                display(&q);
                break;
            case(4):
                exit(0);
                break;
            default:
                printf("Invalid choice");
        }
    }
    return 0;
}