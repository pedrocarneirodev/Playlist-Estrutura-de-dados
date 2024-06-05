#ifndef PRINTF_H
#define PRINTF_H

#include <windows.h>
#include <stdio.h>

void SetConsoleModeCustom(HANDLE consoleHandle, DWORD mode){
    if(!SetConsoleMode(consoleHandle, mode)){
        fprintf(stderr, "Erro ao definir o modo do console\n");
        exit(1);
    }
}
void ReadConsoleInputCustom(HANDLE consoleHandle, INPUT_RECORD *inputRecord){
    DWORD eventsRead;
    if(!ReadConsoleInput(consoleHandle, inputRecord, 1, &eventsRead)){
        fprintf(stderr, "Erro ao ler entrada do console\n");
        exit(1);
    }
}

#endif