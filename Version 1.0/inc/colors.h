#ifndef COLORS
#define COLORS

#include <stdio.h>
#include <string.h>

#define RST "\033[0m"
#define BLK "\033[0;30m"
#define RED "\033[0;31m"
#define GRN "\033[0;32m"
#define YLW "\033[0;33m"
#define BLU "\033[0;34m"
#define MGT "\033[0;35m"
#define CYN "\033[0;36m"
#define WHT "\033[0;37m"

#define BOLD_BLK "\033[1;30m"
#define BOLD_RED "\033[1;31m"
#define BOLD_GRN "\033[1;32m"
#define BOLD_YLW "\033[1;33m"
#define BOLD_BLU "\033[1;34m"
#define BOLD_MGT "\033[1;35m"
#define BOLD_CYN "\033[1;36m"
#define BOLD_WHT "\033[1;37m"

#define BRGT_BLK "\033[0;90m"
#define BRGT_RED "\033[0;91m"
#define BRGT_GRN "\033[0;92m"
#define BRGT_YLW "\033[0;93m"
#define BRGT_BLU "\033[0;94m"
#define BRGT_MGT "\033[0;95m"
#define BRGT_CYN "\033[0;96m"
#define BRGT_WHT "\033[0;97m"

#define BOLD_BRGT_BLK "\033[1;90m"
#define BOLD_BRGT_RED "\033[1;91m"
#define BOLD_BRGT_GRN "\033[1;92m"
#define BOLD_BRGT_YLW "\033[1;93m"
#define BOLD_BRGT_BLU "\033[1;94m"
#define BOLD_BRGT_MGT "\033[1;95m"
#define BOLD_BRGT_CYN "\033[1;96m"
#define BOLD_BRGT_WHT "\033[1;97m"

// void colorMultipleLines(char* position, char* color, int bold, int bright) {
//     if(bold == 1 && color == NULL){
//         printf("\033[1m");
//     }
//     if(bright && color != NULL){
//         // High intensity text color
//         if (color == BLK) color = BRGT_BLK;
//         else if (color == RED) color = BRGT_RED;
//         else if (color == GRN) color = BRGT_GRN;
//         else if (color == YLW) color = BRGT_YLW;
//         else if (color == BLU) color = BRGT_BLU;
//         else if (color == MGT) color = BRGT_MGT;
//         else if (color == CYN) color = BRGT_CYN;
//         else if (color == WHT) color = BRGT_WHT;
//     }
//     if(bright && bold && color != NULL){
//         // High intensity text color
//         if (color == BLK) color = BOLD_BRGT_BLK;
//         else if (color == RED) color = BOLD_BRGT_RED;
//         else if (color == GRN) color = BOLD_BRGT_GRN;
//         else if (color == YLW) color = BOLD_BRGT_YLW;
//         else if (color == BLU) color = BOLD_BRGT_BLU;
//         else if (color == MGT) color = BOLD_BRGT_MGT;
//         else if (color == CYN) color = BOLD_BRGT_CYN;
//         else if (color == WHT) color = BOLD_BRGT_WHT;
//     }
//     if(position == "start"){
//         printf(color);
//     }else if(position == "end"){
//         printf(RST);
//     }
// }

#endif