#include <stdio.h>
#include<stdlib.h>
#define MAX 40
typedef struct Node{
    int data;
    Node* prev;
    Node* next;
}Node;
Node*list;
Node* createNode(int data){
    Node*newNode=(Node*)malloc(sizeof(Node));
    newNode->data=data;
    newNode->next=newNode->prev=NULL;
}
void insert(Node**head,int data){
    Node* newNode=createNode(data);
    Node* current=*head;
    while(current->next!=NULL){
        current=current->next;
    }
    current->next=newNode;
    newNode->prev=current; 

}

