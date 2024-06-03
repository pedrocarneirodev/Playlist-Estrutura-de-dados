<<<<<<< HEAD
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

=======
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

>>>>>>> d88951a1fc1c276674e5424f6415d916dd1a8075
#endif