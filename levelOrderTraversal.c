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
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}
//returns pointer to the address of node
Node** createQueue(int* front,int* rear){
    Node** queue= (Node**)malloc(MAX* sizeof( Node*));
    *front=*rear=0;
    return queue;
}
//parameters for enqueue are the queue itself the front pointer of the node and the node itself
void enq( Node**queue,int* rear,Node* newNode){
    queue[*rear]=newNode;
    (*rear)++;
    //follows filo so the rear is increamented 

}
Node* dequeue(Node** queue,int* front){
    (*front )++;
    //increamenting the front pointer to the next item 
    return queue[*front-1];
    //retruning the node that has been dereferenced
}
//for printing we need the root of the tree
//in this we are using array to implement queue
void printLevelOrder(Node* root){
    int front,rear;
    Node** queue =createQueue(&front,&rear);
    Node* tempNode=root;//this is taken for reference
    while(tempNode){
        //this function will run till it reaches the end of the tree i.e it points to NULL(both left and right pointer)
        printf("%d ",tempNode->data);//prints  the nodes level wise
        if(tempNode->left){
            //checks if the left pointer of the tempNode exists
            //and now if it exists it is enqueued to the queue
            enq(queue,&rear,tempNode->left);
        }
        if(tempNode->right){
            enq(queue,&rear,tempNode->right);
        }
        //now that elements of both the level has been enqueued
        //we will dequeue the the elements and the tempnode is updated to the next level of nodes i.e child nodes
        tempNode=dequeue(queue,&front); 
    }


}
int main(){
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
 
    printf("Level Order traversal of binary tree is \n");
    printLevelOrder(root);
    return 0;
}
