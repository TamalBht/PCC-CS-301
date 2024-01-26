#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
}Node;
Node* createNode(int inp){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = inp;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
