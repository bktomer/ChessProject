#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#ifndef gameflowH
#define gameflowH

#include <libxml/tree.h>
#include <libxml/parser.h>
#include "minimax.h"

char* boardRowToString(int row_num);
void updateBoardFromString(char* curr_row, int row_num);
int loadSettingsFromFile(char* fp,int print_bit);
void saveGameStateToFile(char* fp);
void gamingMode();
void SettingsMode();
int updateBoard(move* current_move, char playing_color);
moves* getBestMoves(char playing_color);
int getMoveScore(char playing_color, move* curr_move);

#endif