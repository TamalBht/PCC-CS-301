#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    Node* left;
    Node* right;
}Node;

Node* createNode(int inp){
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->left=newNode->right=NULL;
    newNode->data=inp;
    return newNode;
}
Node* insert(Node*node,int key){
    if(node==NULL) return createNode(key);
    if(key<node->data) node->left=insert(node->left,key);
    else if(key>node->data) node->right=insert(node->right,key);
    return node;
}
void inorder(Node* root){
    while(root!=NULL){
        inorder(root->left);
        printf("%d->",root->data);
        inorder(root->right);

    }
}
Node* helper(Node* root);
Node* findLastRight(Node* root);
Node* delete(Node*root,int key){
    if(root==NULL) return NULL;
    if(root->data==key) return helper(root);
}