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
void preorder(Node* root){
    if(root==NULL){
        return;
    }
    printf("%d->",root->data);
    preorder(root->left);
    preorder(root->right);
}
void inorder(Node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    printf("%d->",root->data);

    inorder(root->right);
}
int main(){
    Node* root=createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    printf("Preorder Traversal: ");
    preorder(root);
    printf("\n Inorder traversal: ");
    inorder(root);

    return 0;
}
