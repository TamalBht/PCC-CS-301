#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
}Node;
Node* initial(Node* n,int inp){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = inp;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
void preorder(Node* root){
    if(root==NULL){
        return;
    }
    print("%d",&root->data);
    preorder(root->left);
    preorder(root->right);
}
