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
    return (newNode);
}
//for printing the tree
void inorder(Node* root){
    if(root!=NULL){
        inorder(root->left);
        printf("(%d)->",root->data);
        inorder(root->right);
    }
}
Node* insert(Node* node,int key){
    if(node==NULL) return(createNode(key));
    //if the value is less than the key then it traverses to the left subtree and so on until it reaches the leaf node
    if(key<node->data) node->left=insert(node->left,key);
    else if(key>node->data)node->right=insert(node->right,key);
    return node;

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
    printf("Before insertion:\n");
    inorder(root);
    int num;
    printf("\nEnter a value to be inserted:");
    scanf("%d",&num);
    insert(root,num);
    printf("After insertion:\n");
    inorder(root);

    return 0;
}