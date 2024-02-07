#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node* next;
    
}Node;

Node* createNode(int inp){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data=inp;
    newNode->next=NULL;
    return newNode;
}
void insertFirst(Node* head){
    int inp;
    printf("Enter the value: ");
    scanf("%d",&inp);
    Node* newNode= createNode(inp);
    newNode->next =head;
    Node* temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=newNode;
}
void display(Node* head){
    Node* temp= head;
    while(temp->next!=head){
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("%d->",temp->data);


}

int main(){
    Node* head=createNode(1);
    head->next=createNode(2);
    head->next->next=createNode(3);
    head->next->next->next=head;
    display(head);
    insertFirst(head);
    display(head);
    return 0;
}
