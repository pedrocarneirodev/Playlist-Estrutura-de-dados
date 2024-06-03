#ifndef SORT
#define SORT

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "types.h"
#include "print.h"

#include "operations.h"

void sort(){
    if(first == NULL){
        printAlert("lista");
    }
    node* newHead = NULL;
    node* newLast = NULL;
    node* current = first;
    int size = 0;
    do{
        size++;
        node* newNode = (node*)malloc(sizeof(node));
        if(newNode == NULL){
            printAlert("memoria");
        }
        strcpy(newNode->name, current->name);
        strcpy(newNode->music, current->music);
        if(newHead == NULL){
            newHead = newNode;
            newHead->next = newHead;
            newHead->prev = newHead;
            newLast = newHead;
        }else{
            newNode->next = newHead;
            newNode->prev = newLast;
            newLast->next = newNode;
            newHead->prev = newNode;
            newLast = newNode;
        }
        current = current->next;
    }while(current != first);

    node* stack[size];
    current = newHead;

    for(int i = 0; size > i; i++){
        stack[i] = current;
        current = current->next;
    }
    for(int i = 0; i < size - 1; i++){
        for(int j = 0; j < size - 1 - i; j++){
            if(strcmp(stack[j]->music, stack[j + 1]->music) > 0){
                node* tmp = stack[j];
                stack[j] = stack[j + 1];
                stack[j + 1] = tmp;
            }
        }
    }
    for(int i = 0; i < size - 1; i++){
        stack[i]->next = stack[i + 1];
    }
    stack[size - 1]->next = stack[0];
    list(stack[0]);
}

#endif