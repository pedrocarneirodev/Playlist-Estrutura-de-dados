#ifndef OPERATIONS
#define OPERATIONS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#include "types.h"
#include "print.h"

void createList(node* artist){
    artist->next = artist;
    artist->prev = artist;
    first = artist;
    head = artist;
    last = artist;
}
void insertArtist(node* artist){
    artist->name[strcspn(artist->name, "\n")] = '\0';
    artist->music[strcspn(artist->music, "\n")] = '\0';
    if(first == NULL){
        createList(artist);
    }else{
        artist->next = first;
        artist->prev = first->prev;
        first->prev->next = artist;
        first->prev = artist;
        first = artist;
        head = artist;
    }
}
void list(node* index){
    node* current = index;
    if(index == NULL){
        printAlert("lista");
        exit(1);
    }
    printHeaderList("start");
    do{
        printContent(current);
        current = current->next;
    }while(index != current);
    printHeaderList("end");
    printBackToMenu();
}
node* removeMusic(char* nameMusic){
    system("cls");
    node* current = first;
    if(first == NULL){
        printAlert("lista");
    }
    while(strcmp(current->music, nameMusic) != 0){
        current = current->next;
        if(first == current && current->music != nameMusic){
            printAlert("musica");
            return NULL;
        }
    }
    if(current->next == current){
        head = first = last = NULL;
    }else{
        current->prev->next = current->next;
        current->next->prev = current->prev;
        if(current == first){
            first = current->next;
            head = first;
        }
        if(current == last){
            last = current->prev;
        }
    }
    return current;
    free(current);
}
node* searchArtist(char* nameMusic){
    node* current = first;
    if(first == NULL){
        printAlert("lista");
    }
    do{
        if(strcmp(current->music,nameMusic) == 0){
            break;
        }
        if(current->next == first){
            current = NULL;
            break;
        }
        current = current->next;
    }while( current != first);
    return current;
}
void nextMusic(){
    system("cls");
    node* current = head;
    if(head == NULL){
        printAlert("lista");
        exit(1);
    }
    head = printStatuslist(current, 1);
}
void prevMusic(){
    system("cls");
    node* current = head;
    printselectedOption(7);
    if(head == NULL){
        printAlert("lista");
        exit(1);
    }
    head = printStatuslist(current, 2);
}

#endif