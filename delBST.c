#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
}Node;
Node* createNode(int inp){
    Node* newNode= (Node*)malloc(sizeof(Node));
    newNode->data=inp;
    newNode->left=newNode->right=NULL;
    return newNode;
}
void inorder(Node* root){
    if (root!=NULL){
        inorder(root->left);
        printf("(%d)->",root->data);
        inorder(root->right);
    }
}
Node* insert(Node* node,int key){
    if(node==NULL) return (createNode(key));
    if(key<node->data) node->left=insert(node->left,key);
    else if(key>node->data)node->right=insert(node->right,key);
    return node;
}
Node* helper(Node*root);
Node* findLastRight(Node*root);
Node* delete(Node* root,int key){
    //if empty tree
    if(root==NULL) return NULL;
    if(root->data==key) return helper(root);
    Node* dummy= root;
    while(root!=NULL){
        if(root->data>key){
            //if only right subtree is present
            if(root->left!=NULL && root->left->data==key){
                root->left=helper(root->left);
                break;
            }
            else root=root->left;
    }   else{
            if(root->right!=NULL && root->right->data==key){
                root->right=helper(root->right);
                break;
            }
            else root=root->right;
    }

    }
        return dummy;
    }

Node* helper(Node*root){
    //if left doesnt exist right is connected and vice versa
    if(root->left==NULL) return root->right;
    else if(root->right==NULL) return root->left;
    //selecting the right child
    Node* rightChild= root->right;
    //finding the right most node of left child
    Node* mostRight = findLastRight(root->left);
    mostRight->right=rightChild;
    return root->left;
}
Node* findLastRight(Node*root){
    if(root->right==NULL) return root;
    findLastRight(root->right);
}

int main(){
    Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    printf("Before deletion:\n");
    inorder(root);
    root=delete(root,60);
    printf("\nAfter deletion of node value 20\n");
    inorder(root);
    return 0;
}