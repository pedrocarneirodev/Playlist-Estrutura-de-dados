#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>

//#include "../inc/utils.h"
#include "../inc/sort.h"
#include "../inc/types.h"
#include "../inc/print.h"
#include "../inc/operations.h"
#include "../inc/filesystem.h"
#include "../inc/keylogger.h"

int main(){
    setlocale(LC_ALL, "C.UTF-8");

    HANDLE consoleInputHandle = GetStdHandle(STD_INPUT_HANDLE);
    if (consoleInputHandle == INVALID_HANDLE_VALUE) {
        fprintf(stderr, "Erro ao obter o handle para a entrada padrão\n");
        return 1;
    }
    DWORD originalConsoleMode;
    if (!GetConsoleMode(consoleInputHandle, &originalConsoleMode)) {
        fprintf(stderr, "Erro ao obter o modo do console\n");
        return 1;
    }
    DWORD newConsoleMode = originalConsoleMode & ~(ENABLE_LINE_INPUT | ENABLE_ECHO_INPUT);
    SetConsoleModeCustom(consoleInputHandle, newConsoleMode);
    INPUT_RECORD inputRecord;

    readFile();
    node* playList;
    int selectedOption = 0;
    
    do{
        printMenu(selectedOption);
        ReadConsoleInputCustom(consoleInputHandle, &inputRecord);

        if(inputRecord.EventType == KEY_EVENT && inputRecord.Event.KeyEvent.bKeyDown){
            switch (inputRecord.Event.KeyEvent.wVirtualKeyCode) {
                case VK_DOWN:
                    if (selectedOption < 6) {
                        selectedOption++;
                        printMenu(selectedOption);
                    }
                    break;
                case VK_UP:
                    if (selectedOption > 1) {
                        selectedOption--;
                        printMenu(selectedOption);
                    }
                    break;
                case VK_RETURN:
                    switch(selectedOption){
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
                            if(playList == 1){
                                break;
                            }
                            insertArtist(playList);
                            writeFile();
                            printStatusInserted(playList);
                            break;
                        case 4:
                            playList = printRemove();
                            if(playList == 1){
                                break;
                            }
                            playList = removeMusic(playList->music);    
                            writeFile();
                            printStatusRemoved(playList);
                            break;
                        case 5:
                            playList = printSearch();
                            if(playList == 1){
                                break;
                            }
                            playList = searchArtist(playList->music);
                            printStatusSearched(playList);
                            break;
                        case 6:
                            printStatuslist();
                            break;
                        default:
                            exit(0);
                    }
                break;
                case VK_TAB:
                    return 0;
                break;
            }
        }
    }while(selectedOption != 8);
    SetConsoleModeCustom(consoleInputHandle, originalConsoleMode);
return 0;
}