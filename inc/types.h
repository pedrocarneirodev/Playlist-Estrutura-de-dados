#ifndef TYPES
#define TYPES

typedef struct node{
    char name[100];
    char music[100];
    struct node* next;
    struct node* prev;
}node;

node* head = NULL;
node* first = NULL;
node* last = NULL;

#endif