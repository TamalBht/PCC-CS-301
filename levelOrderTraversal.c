#include<stdio.h>
#include<stdlib.h>
#define MAX 100
//Node to represent the tree node
typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
}Node;
Node* createNode(int inp){
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->data=inp;
    newNode->left=newNode->right=NULL;
    return newNode;
}
//returns pointer to the address of node
Node** createQueue(int* front,int* rear){
    Node** queue= (Node**)malloc(MAX);
    *front=*rear=0;
    return queue;
}
//parameters for enqueue are the queue itself the front pointer of the node and the node itself
void enq( Node**queue,int* front,Node* newNode){
    
}