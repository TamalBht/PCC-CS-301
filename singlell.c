#include <stdio.h>
#include<stdlib.h>
#define MAX 40
typedef struct Node{
    int data;
    Node* prev;
    Node* next;
}Node;
Node*list;

