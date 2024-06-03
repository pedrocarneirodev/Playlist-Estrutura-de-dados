#ifndef PRINT
#define PRINT

#include "types.h"

void printMenu(){
    system("cls");
    printf("\n\n    ====================== Menu ======================\n\n");
    printf("           [1] Exibição por ordem de cadastro\n");
    printf("           [2] Exibição pelo nome das músicas\n");
    printf("           [3] Adicionar nova música\n");
    printf("           [4] Remover uma musica\n");
    printf("           [5] Buscar por uma musica\n");
    printf("           [6] Avançar para próxima música\n");
    printf("           [7] Retornar a música anterior\n");
    printf("           [8] Sair do programa\n");
    printf("\n    ==================================================\n\n");
    printf("----------------------------------------------------------\n");
    printf("--> Escolha uma opção: ");
}
void printselectedOption(int numOption){
    switch(numOption){
        case 1:
            system("cls");
            printf("\n------------------- Opção Selecionada --------------------\n");
            printf("    ==================================================    \n");
            printf("            [1] Exibição por ordem de cadastro            \n");
            printf("    ==================================================    \n");
            printf("----------------------------------------------------------\n\n");
            break;
        case 2:
            system("cls");
            printf("\n------------------- Opção Selecionada --------------------\n");
            printf("    ==================================================    \n");
            printf("            [2] Exibição pelo nome das músicas            \n");
            printf("    ==================================================    \n");
            printf("----------------------------------------------------------\n\n");
            break;
        case 3:
            system("cls");
            printf("\n------------------- Opção Selecionada --------------------\n");
            printf("    ==================================================    \n");
            printf("                [3] Adicionar nova música                 \n");
            printf("    ==================================================    \n");
            printf("----------------------------------------------------------\n\n");
            break;
        case 4:
            system("cls");
            printf("\n------------------- Opção Selecionada --------------------\n");
            printf("    ==================================================    \n");
            printf("                  [4] Remover uma musica                  \n");
            printf("    ==================================================    \n");
            printf("----------------------------------------------------------\n\n");
            break; 
        case 5:
            system("cls");
            printf("\n------------------- Opção Selecionada --------------------\n");
            printf("    ==================================================    \n");
            printf("                [5] Buscar por uma musica                 \n");
            printf("    ==================================================    \n");
            printf("----------------------------------------------------------\n\n");
            break;
        case 6:
            system("cls");
            printf("\n------------------- Opção Selecionada --------------------\n");
            printf("    ==================================================    \n");
            printf("             [6] Avançar para próxima música              \n");
            printf("    ==================================================    \n");
            printf("----------------------------------------------------------\n\n");
            break;
        case 7:
            system("cls");
            printf("\n------------------- Opção Selecionada --------------------\n");
            printf("    ==================================================    \n");
            printf("              [7] Retornar a música anterior              \n");
            printf("    ==================================================    \n");
            printf("----------------------------------------------------------\n\n");
            break;
        case 8:
            break;
    }
}
void printAlert(char* typeMenssage){
    system("cls");
    if(strcmp(typeMenssage, "musica") == 0){
        printf("\n------------------------- Aviso --------------------------\n");
        printf("\033[31m    ==================================================\033[0m\n");
        printf("\033[31m          Ops! Música não encontrada no arquivo.      \033[0m\n");
        printf("\033[31m    ==================================================\033[0m\n");
        printf("----------------------------------------------------------\n");
    }else if(strcmp(typeMenssage, "arquivo") == 0){
        printf("\n------------------------- Aviso --------------------------\n");
        printf("\033[31m    ==================================================\033[0m\n");
        printf("\033[31m              Ops! Erro ao abrir o arquivo.           \033[0m\n");
        printf("\033[31m    ==================================================\033[0m\n");
        printf("----------------------------------------------------------\n\n");
    }else if(strcmp(typeMenssage, "lista") == 0){
        printf("\n------------------------- Aviso --------------------------\n");
        printf("\033[31m    ==================================================\033[0m\n");
        printf("\033[31m           Ops! O conteúdo da lista está vazia.       \033[0m\n");
        printf("\033[31m    ==================================================\033[0m\n");
        printf("----------------------------------------------------------\n\n");
    }else if(strcmp(typeMenssage, "memoria") == 0){
        printf("\n------------------------- Aviso --------------------------\n");
        printf("\033[31m    ==================================================\033[0m\n");
        printf("\033[31m          Erro ao alocar o conteúdo na memória.       \033[0m\n");
        printf("\033[31m    ==================================================\033[0m\n");
        printf("----------------------------------------------------------\n\n");
    }
}
void printBackToMenu(){
    char option;
    printf("\nDeseja voltar para o menu(s/n): ");
    scanf("%s", &option);
    if(option == 's' || option == 'S'){
        system("cls");
        return;
    }else if(option == 'n' || option == 'N'){
        exit(0);
    }
}
void printHeaderList(char* position){
    if(strcmp(position, "start") == 0){
        printf("------------------------ Playlist ------------------------\n\n");
    }else if(strcmp(position, "end") == 0){
        printf("\n----------------------------------------------------------\n");
    }
}
void printContent(node* currentArtist){
    printf("    ==================================================    \n");
    printf("     Artista: %s\n", currentArtist->name);
    printf("     Música : %s\n", currentArtist->music);
    printf("    ==================================================    \n");
}
node* printInsert(){
    system("cls");

    node* newArtist = (node*)malloc(sizeof(node));
    printf("\n\033[1;31mATENCAO:\033[0m Insira os dados no campo abaixo para adicionar artista.\n");
    printf("\n    -------------  Artista \033[92m(Adicionando)\033[0m  ------------\n");
    printf("     -> Nome: ");
    fflush(stdin);
    fgets(newArtist->name, sizeof(newArtist->name), stdin);
    printf("     -> Música: ");
    fflush(stdin);
    fgets(newArtist->music, sizeof(newArtist->music), stdin);
    printf("    --------------------------------------------------\n");
    Sleep(500);
    return newArtist;
}
void printStatusInserted(node* newArtist){
    system("cls");
    printf("\n\033[1;32m       ============================================\033[0m\n");
    printf("\033[1;32m        MENSAGEM: Artista adicionado com sucesso!  \033[0m\n");
    printf("\033[1;32m       ============================================\033[0m\n");
    printf("\n------------------- Artista Adicionado -------------------\n");
    printf("    ==================================================    \n");
    printf("     Artista: %s\n", newArtist->name);
    printf("     Música : %s\n", newArtist->music);
    printf("    ==================================================    \n");
    printf("----------------------------------------------------------\n");
    printBackToMenu(); 
}
node* printRemove(){
    system("cls");
    printselectedOption(4);

    node* removeArtist = (node*)malloc(sizeof(node));
    printf("--> Insira nome da música: ");
    fflush(stdin);
    fgets(removeArtist->music, sizeof(removeArtist->music), stdin);
    removeArtist->music[strcspn(removeArtist->music, "\n")] = '\0';
    return removeArtist;
}
void printStatusRemoved(node* artistRemoved){
    if(artistRemoved == NULL){
        printBackToMenu(); 
    }else{
        printf("\n\033[1;32m       ============================================\033[0m\n");
        printf("\033[1;32m         MENSAGEM: Artista removido com sucesso!   \033[0m\n");
        printf("\033[1;32m       ============================================\033[0m\n");
        printf("\n-------------------- Artista Removido --------------------\n");
        printf("    ==================================================    \n");
        printf("     Artista: %s\n", artistRemoved->name);
        printf("     Música : %s\n", artistRemoved->music);
        printf("    ==================================================    \n");
        printf("----------------------------------------------------------\n");
        printBackToMenu();
    } 
}
node* printSearch(){
    system("cls");
    printselectedOption(5);

    node* artist = (node*)malloc(sizeof(node));
    printf("--> Insira o nome da música que deseja encontrar: ");
    fflush(stdin);
    fgets(artist->music, sizeof(artist->music), stdin);
    artist->music[strcspn(artist->music, "\n")] = '\0';
    return artist;
}
void printStatusSearched(node *currentArtist){
    system("cls");
    if(currentArtist == NULL){
        printAlert("musica");
    }else{
        printf("\n------------------- Música Encontrada --------------------\n");
        printf("    ==================================================    \n");
        printf("     Artista: %s\n", currentArtist->name);
        printf("     Música : %s\n", currentArtist->music);
        printf("    ==================================================    \n");
        printf("----------------------------------------------------------\n");
    }
    printBackToMenu();
}
node* printStatuslist(node* currentArtist, int type){
    char option;
    start:
    system("cls");
    printselectedOption(6);
    printHeaderList("start");
    printf("    ==================== Anterior ====================    \n");
    printf("     Artista: %s\n", currentArtist->prev->name);
    printf("     Música : %s\n", currentArtist->prev->music);
    printf("    ==================================================    \n");
    printf("    ===================== Actual =====================    \n");
    printf("     Artista: %s\n", currentArtist->name);
    printf("     Música : %s\n", currentArtist->music);
    printf("    ==================================================    \n");
    printf("    ==================== Próxima =====================    \n");
    printf("     Artista: %s\n", currentArtist->next->name);
    printf("     Música : %s\n", currentArtist->next->music);
    printf("    ==================================================    \n");
    printHeaderList("end");
    if(type == 1){
        printf("Deseja passar para próxima música(s/n): ");
        scanf("%s", &option);
        if(option == 's' || option == 'S'){
            currentArtist = currentArtist->next;
            goto start;
        }else if(option == 'n' || option == 'N'){
            return currentArtist;
        }
    } else if(type == 2){
        printf("Deseja passar para música anterior(s/n): ");
        scanf("%s", &option);
        if(option == 's' || option == 'S'){
            currentArtist = currentArtist->prev;
            goto start;
        }else if(option == 'n' || option == 'N'){
            return currentArtist;
        }
    }
    return currentArtist;
}


#endif