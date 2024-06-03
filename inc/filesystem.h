<<<<<<< HEAD
#ifndef FILESYSTEM
#define FILESYSTEM

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "types.h"

void readFile(){
    FILE* file = fopen("../musicas.txt", "r");
    if(file == NULL){
        printAlert("arquivo");
    }
    
    char line[100];
    while(fgets(line,sizeof(line), file) != NULL){
        node* newArtist = (node*)malloc(sizeof(node));
        char* token = strtok(line, ";");
        if(token != NULL){
            strcpy(newArtist->name, token);
            token = strtok(NULL, ";");
            if(token != NULL){
                strcpy(newArtist->music, token);
            }else{
                strcpy(newArtist->music, "");
            }
        }else{
            strcpy(newArtist->name, "");
            strcpy(newArtist->music, "");
        }
        insertArtist(newArtist);
    }
    fclose(file);
}
void writeFile(){
    FILE* file = fopen("../musicas.txt", "w");
    if(file == NULL){
        printAlert("arquivo");
        exit(1);
    }
    node** stack = NULL;
    int stackSize = 0;

    node* current = first;
    do{
        stackSize++;
        stack = (node**)realloc(stack, stackSize * sizeof(node*));
        if(stack == NULL){
            printAlert("memoria");
            exit(1);
        }
        stack[stackSize - 1] = current;
        current = current->next;
    }while(first != current);

    while (stackSize > 0) {
        current = stack[--stackSize];
        fprintf(file,"%s;%s\n", current->name, current->music);
    }
    free(stack);
    fclose(file);
}

=======
#ifndef FILESYSTEM
#define FILESYSTEM

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "types.h"

void readFile(){
    FILE* file = fopen("musicas.txt", "r");
    if(file == NULL){
        printAlert("arquivo");
    }
    
    char line[100];
    while(fgets(line,sizeof(line), file) != NULL){
        node* newArtist = (node*)malloc(sizeof(node));
        char* token = strtok(line, ";");
        if(token != NULL){
            strcpy(newArtist->name, token);
            token = strtok(NULL, ";");
            if(token != NULL){
                strcpy(newArtist->music, token);
            }else{
                strcpy(newArtist->music, "");
            }
        }else{
            strcpy(newArtist->name, "");
            strcpy(newArtist->music, "");
        }
        insertArtist(newArtist);
    }
    fclose(file);
}
void writeFile(){
    FILE* file = fopen("musicas.txt", "w");
    if(file == NULL){
        printAlert("arquivo");
        exit(1);
    }
    node** stack = NULL;
    int stackSize = 0;

    node* current = first;
    do{
        stackSize++;
        stack = (node**)realloc(stack, stackSize * sizeof(node*));
        if(stack == NULL){
            printAlert("memoria");
            exit(1);
        }
        stack[stackSize - 1] = current;
        current = current->next;
    }while(first != current);

    while (stackSize > 0) {
        current = stack[--stackSize];
        fprintf(file,"%s;%s\n", current->name, current->music);
    }
    free(stack);
    fclose(file);
}

>>>>>>> d88951a1fc1c276674e5424f6415d916dd1a8075
#endif