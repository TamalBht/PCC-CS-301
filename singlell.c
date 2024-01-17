#include <stdio.h>
#include<stdlib.h>
#define MAX 40
typedef struct node{
    int data;
    node* prev;
    node* next;
}node;
node*list;

