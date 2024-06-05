#ifndef PRINT
#define PRINT

#include <stdlib.h>

#include "types.h"
#include "colors.h"
#include "operations.h"

#define UP_ARROW 72
#define DOWN_ARROW 80
#define LEFT_ARROW 75
#define RIGHT_ARROW 77
#define ENTER 13
#define ESC 27
#define TAB 9

void header(){
    system("cls");
    printf("\n\n\n");
    printf("        ████████╗ ███╗     ███████╗ ███╗   ███╗███╗    ███╗████████╗█████████╗      \n");
    printf("        ███╔══███╗███║    ███╔══███╗╚███╗ ███╔╝███║    ███║███╔════╝╚══███╔══╝      \n");
    printf("        ████████╔╝███║    █████████║ ╚█████╔╝  ███║    ███║████████╗   ███║         \n");
    printf("        ███╔═══╝  ███║    ███╔══███║  ╚███╔╝   ███║    ███║╚════███║   ███║         \n");
    printf("        ███║      ███████╗███║  ███║   ███║    ███████╗███║████████║   ███║         \n");
    printf("        ╚══╝      ╚══════╝╚══╝  ╚══╝   ╚══╝    ╚══════╝╚══╝ ╚══════╝   ╚══╝         \n");
    printf("\n                     Developed by Pedro Carneiro [version: 1.1]                   \n");
    printf("                        Trabalho de estrutura de dados - UCB                        \n\n\n"); 
}
void printMenu(int currentIndex){
    system("cls");
    header();
    printf("         # Exibir toda lista:\n");
    printf("           %s Ordem por cadastro                                     %s\n", (currentIndex == 1) ? "->" : "  ", (currentIndex == 1) ? "[•]" : "[ ]");
    printf("           %s Ordem alfabética das músicas                           %s\n", (currentIndex == 2) ? "->" : "  ", (currentIndex == 2) ? "[•]" : "[ ]");
    printf("\n         # Modificações:\n");
    printf("           %s Inserir nova música                                    %s\n", (currentIndex == 3) ? "->" : "  ", (currentIndex == 3) ? "[•]" : "[ ]");
    printf("           %s Remover uma música                                     %s\n", (currentIndex == 4) ? "->" : "  ", (currentIndex == 4) ? "[•]" : "[ ]");
    printf("           %s Buscar por uma música                                  %s\n", (currentIndex == 5) ? "->" : "  ", (currentIndex == 5) ? "[•]" : "[ ]");
    printf("\n         # Playlist:\n");
    printf("           %s Reproduzir música                                      %s\n", (currentIndex == 6) ? "->" : "  ", (currentIndex == 6) ? "[•]" : "[ ]");
    printf("                + Avançar para próxima música\n");
    printf("                + Retornar a música anterior\n\n\n");
    printf("                [↑] Subir    [↓] Descer    [ENTER] Selecionar    [TAB] Sair\n\n");
    printf("                             Selecione opção desejada.\n\n");
}
void printselectedOption(int numOption){
    switch(numOption){
        case 1:
            header();
            printf("[ESC] Voltar  |  OPÇÃO SELECIONADA: Ordem por cadastro  |  [TAB] Sair do programa\n\n\n");
            break;
        case 2:
            header();
            printf("[ESC] Voltar   |  OPÇÃO SELECIONADA: Ordem das músicas  |  [TAB] Sair do programa\n\n\n");
            break;
        case 3:
            header();
            printf("[R + ENTER] Voltar  | OPÇÃO SELECIONADA: Adicionar Música |  [TAB] Sair do programa\n\n\n");
            break;
        case 4:
            header();
            printf("[R + ENTER] Voltar  | OPÇÃO SELECIONADA: Remover Música  |   [TAB] Sair do programa\n\n\n");
            break; 
        case 5:
            header();
            printf("[R + ENTER] Voltar  | OPÇÃO SELECIONADA: Buscar Música  |    [TAB] Sair do programa\n\n\n");
            break;
        case 6:
            header();
            printf("[ESC] Voltar   |  OPÇÃO SELECIONADA: Reproduzir Música  |   [TAB] Sair do programa\n\n\n");
            break;
        case 7:
            header();
            printf("[ESC] Voltar                                                [TAB] Sair do programa\n\n\n");
            break;
    }
}
void printAlert(char* typeMenssage){
    system("cls");
    header();
    printselectedOption(7);
    if(strcmp(typeMenssage, "musica") == 0){
        printf("\n------------------------- Aviso --------------------------\n");
        printf(RED);
        printf("    ==================================================\n");
        printf("          Ops! Música não encontrada no arquivo.      \n");
        printf("    ==================================================\n");
        printf(RST);
        printf("----------------------------------------------------------\n");
    }else if(strcmp(typeMenssage, "arquivo") == 0){
        printf("\n------------------------- Aviso --------------------------\n");
        printf(RED);
        printf("    ==================================================\n");
        printf("              Ops! Erro ao abrir o arquivo.           \n");
        printf("    ==================================================\n");
        printf(RST);
        printf("----------------------------------------------------------\n\n");
    }else if(strcmp(typeMenssage, "lista") == 0){
        printf("\n------------------------- Aviso --------------------------\n");
        printf(RED);
        printf("    ==================================================\n");
        printf("           Ops! O conteúdo da lista está vazia.       \n");
        printf("    ==================================================\n");
        printf(RST);
        printf("----------------------------------------------------------\n\n");
    }else if(strcmp(typeMenssage, "memoria") == 0){
        printf("\n------------------------- Aviso --------------------------\n");
        printf(RED);
        printf("    ==================================================\n");
        printf("          Erro ao alocar o conteúdo na memória.       \n");
        printf("    ==================================================\n");
        printf(RST);
        printf("----------------------------------------------------------\n\n");
    }
}
void printBackToMenu(){
    int keyPressed;
    printf("\n");
    while(1){
        if(_kbhit()){
            keyPressed = _getch();
            if(keyPressed == TAB){
                exit(0);
            }
            if(keyPressed == ESC){
                system("cls");
                return;
            }
        }
    }
}
int keyPress(){
    int keyPressed;
    while(1){
        if(_kbhit()){
            keyPressed = _getch();
            return keyPressed;
        }
    }
}
void printHeaderList(char* position){
    if(strcmp(position, "start") == 0){
        printf("  ╭──────────╮\n");
        printf("  │    ♪♪    │ \033[1mMÚSICAS ARQUIVADAS\033[0m\n");
        printf("  │    %.2d    │ ᴅᴇᴠᴇʟᴏᴘᴇᴅ ʙʏ ᴘᴇᴅʀᴏ\n", size);
        printf("  ╰──────────╯\n");
        printf("______________________________________________________________________________________\n\n");
        printf("  #Músicas                               #Artista                                 #ID\n\n");

    }else if(strcmp(position, "end") == 0){
        printf("______________________________________________________________________________________\n\n");
    }
}
node* printInsert(){
    system("cls");
    header();
    printselectedOption(3);
    int keyPressed;
    node* newArtist = (node*)malloc(sizeof(node));
    
    printf("\n--> Digite nome da banda/artista: ");
    fgets(newArtist->name, sizeof(newArtist->name), stdin);
    newArtist->name[strcspn(newArtist->name, "\n")] = '\0';
    if(strcmp(newArtist->name, "R") == 0){
        free(newArtist);
        return 1;
    }
    printf("--> Insira o nome da música: ");
    fgets(newArtist->music, sizeof(newArtist->music), stdin);
    newArtist->music[strcspn(newArtist->music, "\n")] = '\0';
    if(strcmp(newArtist->music, "R") == 0){
        free(newArtist);
        return 1;
    }
    return newArtist;
}
void printStatusInserted(node* newArtist){
    system("cls");
    header();
    printselectedOption(7);
    node* current = first;
    printHeaderList("start");
    do{
        if(strcmp(current->music, newArtist->music) == 0){
            listArtistDashes(current, "insert");
        }else{
            listArtistDashes(current, "list");
        }
        current = current->next;
    }while(first != current);
    printHeaderList("end");
    printBackToMenu();
}
node* printRemove(){
    system("cls");
    header();
    printselectedOption(4);

    node* removeArtist = (node*)malloc(sizeof(node));
    printf("\n--> Insira nome da música que deseja remover: ");
    fflush(stdin);
    fgets(removeArtist->music, sizeof(removeArtist->music), stdin);
    removeArtist->music[strcspn(removeArtist->music, "\n")] = '\0';
    if(strcmp(removeArtist->music, "R") == 0){
        free(removeArtist);
        return 1;
    }
    return removeArtist;
}
void printStatusRemoved(node* artistRemoved){
    if(artistRemoved == NULL){
        printBackToMenu(); 
    }else{
        system("cls");
        header();
        printselectedOption(7);
        node* current = first;
        printHeaderList("start");
        do{
            listArtistDashes(current, "list");
            current = current->next;
        }while(first != current);
        printHeaderList("end");
        listArtistDashes(artistRemoved, "remove");
        printHeaderList("end");
        printBackToMenu();
    } 
}
node* printSearch(){
    system("cls");
    header();
    printselectedOption(5);

    node* artist = (node*)malloc(sizeof(node));
    printf("--> Insira o nome da música que deseja encontrar: ");
    fflush(stdin);
    fgets(artist->music, sizeof(artist->music), stdin);
    artist->music[strcspn(artist->music, "\n")] = '\0';
    if(strcmp(artist->music, "R") == 0){
        free(artist);
        return 1;
    }
    return artist;
}
void printStatusSearched(node *currentArtist){
    system("cls");
    header();
    printselectedOption(7);
    if(currentArtist == NULL){
        printAlert("musica");
    }else{
        printHeaderList("start");
        listArtistDashes(currentArtist, "list");
        printHeaderList("end");
    }
    printBackToMenu();
}
void printStatuslist(){
    node* current = head;
    int soundBar;
    int keyPressed;
    start:
    system("cls");
    printselectedOption(6);
    printf("                  [←] Retroceder [ENTER] Pausa/continua [→] Avançar\n\n");
    printf("                                ⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n");
    printf("                                ⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n");
    printf("                                ⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n");
    printf("                                ⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n");
    printf("                                ⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n");
    printf("                                ⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n");
    printf("                                ⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n");
    printf("                                ⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n");
    printf("                                ⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n\n");
    char* musicName = centerString(current->music, 1);
    printf("%s\n", musicName);
    char* artistName = centerString(current->name, 0);
    printf("%s\n", artistName);
    printf("                        ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    if(soundBar == 1){
        printf("                                     ◄◄ ▶  ►►\n\n\n");
    }else{
        printf("                                     ◄◄ ❚❚ ►►\n\n\n");
    }
    while(1){
        if(_kbhit()){
            keyPressed = _getch();
            if(keyPressed == LEFT_ARROW){
                current = prevMusic();
                goto start;
            }else if(keyPressed == RIGHT_ARROW){
                current = nextMusic();
                goto start;
            }else if(keyPressed == ENTER){
                soundBar = !soundBar;
                goto start;
            }else if(keyPressed == ESC){
                return;
            }
        }
    }
}
void listArtistDashes(node* artist, char* TypeListed){
    node* current = artist;
    if(strcmp(TypeListed, "list") == 0){
        int lengthMusic = strlen(current->music);
        printf("   %s", current->music);

        if (lengthMusic %2 != 0) {
            printf(" ");
        }
        for (int i = 0; i < (38 - lengthMusic) / 2; i++) {
            printf(" -");
        }
        int lengthName = strlen(current->name);
        printf(" %s", current->name);

        if (lengthName %2 != 0) {
            printf(" ");
        }
        for (int i = 0; i < (38 - lengthName) / 2; i++) {
            printf(" -");
        }
        printf("  .%.2d\n", current->position);
    }
    if(strcmp(TypeListed, "remove") == 0){
        printf(BOLD_BRGT_RED);
        int lengthMusic = strlen(current->music);
        printf("   %s", current->music);

        if (lengthMusic %2 != 0) {
            printf(" ");
        }
        for (int i = 0; i < (38 - lengthMusic) / 2; i++) {
            printf(" -");
        }
        int lengthName = strlen(current->name);
        printf(" %s", current->name);

        if (lengthName %2 != 0) {
            printf(" ");
        }
        for (int i = 0; i < (38 - lengthName) / 2; i++) {
            printf(" -");
        }
        printf("  NULL\n");
        printf(RST);

    }
    if(strcmp(TypeListed, "insert") == 0){
        printf(BOLD_BRGT_GRN);
        int lengthMusic = strlen(current->music);
        printf("   %s", current->music);

        if (lengthMusic %2 != 0) {
            printf(" ");
        }
        for (int i = 0; i < (38 - lengthMusic) / 2; i++) {
            printf(" -");
        }
        int lengthName = strlen(current->name);
        printf(" %s", current->name);

        if (lengthName %2 != 0) {
            printf(" ");
        }
        for (int i = 0; i < (38 - lengthName) / 2; i++) {
            printf(" -");
        }
        printf("  .%.2d\n", current->position);
        printf(RST);
    }
}

#endif