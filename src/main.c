#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>

#include "../inc/sort.h"
#include "../inc/types.h"
#include "../inc/print.h"
#include "../inc/operations.h"
#include "../inc/filesystem.h"

int main(){
    setlocale(LC_ALL, "C.UTF-8");
    readFile();
    node* playList;
    int input = 0;
    do{
        printMenu();
        scanf("%d", &input);

        switch(input){
            playList = NULL;
            case 1:
                printselectedOption(1);
                list(first);
                break;
            case 2:
                printselectedOption(2);
                sort(); 
                break;
            case 3:
                playList = printInsert();
                insertArtist(playList);
                writeFile();
                printStatusInserted(playList);
                break;
            case 4:
                playList = printRemove();
                playList = removeMusic(playList->music);    
                writeFile();
                printStatusRemoved(playList);
                break;
            case 5:
                playList = printSearch();
                playList = searchArtist(playList->music);
                printStatusSearched(playList);
                break;
            case 6:
                nextMusic();
                break;
            case 7:
                prevMusic();
                break;
            case 8:
                exit(0);
                break;
        }
    }while (input != 8);
return 0;
}