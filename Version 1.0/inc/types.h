#ifndef TYPES
#define TYPES

typedef struct node{
    char name[100];
    char music[100];
    int position;
    struct node* next;
    struct node* prev;
}node;

int size = 0;
node* head = NULL;
node* first = NULL;
node* last = NULL;

#endif