#include<stdio.h>
#include<stdlib.h>
#define MAX 100
typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
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
Node* deq(Node**queue,int* front){
    (*front)++;
    return queue[*front-1];
}
void printLevelOrder(Node* root){
    int front,rear;
    Node** queue =createQueue(&front,&rear);
    Node* tempNode=root;//this is taken for reference
    while(tempNode){
        printf("%d",tempNode->data);
        //if left and right exists
        if(tempNode->left) enq(queue,tempNode->left,&rear);
        if(tempNode->right)enq(queue,tempNode->right,&rear);
        //updating the temp node
        tempNode=deq(queue,&front);
        printf("\n");
    }
}
int main(){
    Node* root= createNode(1);
    root->left=createNode(2);
    root->right=createNode(3);
    root->left->right=createNode(5);
    root->left->left=createNode(4);
    printLevelOrder(root);
    return 0;
}