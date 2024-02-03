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
    //only one node exists
    Node* dummy= root;
    while(root!=NULL){
        if(root->data>key){
            if(root->left->data==key && root->left!=NULL){
                 root->left=helper(root->left);
                break;
            }
            else root=root->left;

        }
        else if(root->data<key){
            if(root->right!=NULL && root->right->data==key){
                root->right=helper(root->right);
                break;
            }
            else root=root->right;
        }
    }
    return dummy;
}
Node* helper(Node* root){
    if(root->right==NULL) return root->left;
    else if(root->left==NULL) return root->right;
    //to select the right subtree
    Node* rightChild= root->right;
    Node* rightMost=findLastRight(root->left);
    rightMost->right=rightChild;
    return root->left;//returns the parent element to be deleted
}
Node* findLastRight(Node*root){
    if(root->right==NULL) return root;
    else findLastRight(root->right);
}