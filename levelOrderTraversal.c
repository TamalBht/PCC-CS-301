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