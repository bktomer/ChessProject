#ifndef gameflowH
#define gameflowH

#include <libxml/tree.h>
#include <libxml/parser.h>
#include "minimax.h"

/*
* Save board row to a string
*/
char* boardRowToString(int row_num);
/*
* Update board from a given string representing a certain row
*/
void updateBoardFromString(char* curr_row, int row_num);
/*
* Loading game settings from a given file
*/
int loadSettingsFromFile(char* fp,int print_bit);
/* 
* Saving game settings and board to an XML file in a proper format
*/
void saveGameStateToFile(char* fp);
/*
* Maintaining a gaming mode
*/
void gamingMode();
/*
* Maintaining settings mode
*/
void SettingsMode();
/*
* Updating board after a legal move
*/
int updateBoard(move* current_move, char playing_color);
/*
* Getting best possible moves with the minimax depth
*/
moves* getBestMoves(char playing_color);
/*
* Getting a given move's score.
*/
int getMoveScore(char playing_color, move* curr_move);

#endif
