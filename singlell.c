#include <stdio.h>
#include<stdlib.h>
#define MAX 40
typedef struct Node{
    int data;
    struct Node* prev;
    struct Node* next;
}Node;

Node* createNode(int data){
    Node*newNode=(Node*)malloc(sizeof(Node));
    newNode->data=data;
    newNode->next=newNode->prev=NULL;
    return newNode;
}
void insert(Node**head,int data){
    Node* newNode=createNode(data);
    if(*head==NULL){
        *head=newNode;
        return;
    }
    Node* current=*head;
    while(current->next!=NULL){
        current=current->next;
    }
    current->next=newNode;
    newNode->prev=current; 

}
void delete(Node** head){
    if (*head == NULL) {
        return;
    }
    Node* current=*head;
     while(current->next!=NULL){
        current=current->next;
    }
    if (current->prev != NULL) {
        current->prev->next = NULL;
        free(current);
    } else {
        // If there is only one node in the list
        free(current);
        *head = NULL;
    }
}
void display(Node**head){
    Node* current=*head;
    while(current!=NULL){
        printf("(%d)->",current->data);
            current=current->next;

    }
}
int main(){
    int ch;
    int data;
    Node* head = NULL;

    while(1){
        printf("\nPress1 to insert\nPress2 to delete\nPress3 to display\nPress4 to exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("ENter data:");
                scanf("%d",&data);
                insert(&head,data);
                break;
            case 2:
                delete(&head);
                break;
            case 3:
                display(&head);
                break;
            case 4:
                exit(1);
                break;
            default:
                printf("Ïnvalid choice");
                break;



        }
        

    }
    return 0;
}
