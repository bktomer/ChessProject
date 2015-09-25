#ifndef minimaxH
#define minimaxH

#define MAX_POSS_MOVES 27
#include "chesslogic.h"
/*
* Minimax function - finding the score of the best move possible from the input board
*/
int alphabeta(char playing_color, char curr_board[BOARD_SIZE][BOARD_SIZE], int depth, int alpha, int beta, 
	int maximizing, position* w_k_pos, position*  b_k_pos);
int bestDepth(char curr_board[BOARD_SIZE][BOARD_SIZE], char playing_color);

#endif