#ifndef OPERATIONS
#define OPERATIONS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#include "types.h"
#include "print.h"
#include "colors.h"

void createList(node* artist){
    artist->next = artist;
    artist->prev = artist;
    artist->position = size;
    first = artist;
    head = artist;
    last = artist;
}
void insertArtist(node* artist){
    artist->name[strcspn(artist->name, "\n")] = '\0';
    artist->music[strcspn(artist->music, "\n")] = '\0';
    size++;
    if(first == NULL){
        createList(artist);
    }else{
        artist->position = size;
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
        listArtistDashes(current, "list");
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
        size = 0;
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
        size--;
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
node* nextMusic(){
    system("cls");
    node* current = head->next;
    if(head == NULL){
        printf("\nLista vazia.\n");
        exit(1);
    }
    head = current;
    return head;
}
node* prevMusic(){
    system("cls");
    node* current = head->prev;
    if(head == NULL){
        printf("\nLista vazia.\n");
        exit(1);
    }
    head = current;
    return head;
}
char* centerString(char *name, int dashes) {
    char nameDashes[2] = "-";
    char newName[35];
    if(dashes == 1){
        sprintf(newName,"%s %s %s", nameDashes, name, nameDashes);
    }else if(dashes == 0){
        sprintf(newName,"%s", name);
    }else{
        printf("Digite o valor de 1 ou 0 para atribuir a função corretamente.");
        return name;
    }
    int len = strlen(newName);
    int totalLength = 84;
    int padding = totalLength - len;
    int leftPadding = padding / 2;
    char* result = (char*)malloc((totalLength + 1) * sizeof(char));
    
    if (result == NULL) {
        printf("Erro de alocação de memória.\n");
        exit(1);
    }
    memset(result, ' ', totalLength);
    result[totalLength] = '\0';
    strncpy(result + leftPadding, newName, len);

    return result;
}

#endif