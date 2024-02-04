#include<stdio.h>
#include<stdlib.h>
#define MAX 100
typedef struct Node{
    int data;
    Node* left;
    Node* right;
}Node;
Node* createNode(int inp){
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->data=inp;
    newNode->left=newNode->right=NULL;
}
//Node** is taken for create queue because it will contain the pointers of nodes
Node** createQueue(int* front,int* rear){
    Node** queue= (Node**)malloc(MAX * sizeof(Node*));
    *front=*rear=0;//set to initial index
    return queue;
}
void enq(Node**queue ,Node* node,int* rear){
    queue[*rear]=node;
    (*rear)++;//so it is incremented so that a new item could be inserted
}

