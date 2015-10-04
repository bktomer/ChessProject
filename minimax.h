#ifndef minimaxH
#define minimaxH


#include "chesslogic.h"

#define PIECES_TYPES_NUM 6 

/*
* 0=rook ; 1=knight ; 2=bishop ; 3=queen ; 4=king ; 5=pawn
*/
extern int max_poss_moves[PIECES_TYPES_NUM];

/*
* Minimax function - finding the score of the best move possible from the input board
*/
int alphabeta(char playing_color, char curr_board[BOARD_SIZE][BOARD_SIZE], int depth, int alpha, int beta, 
	int maximizing, position* w_k_pos, position*  b_k_pos);
/*
* Calculating the max depth that doesn't calculate more than 10^6 boards during the minimax algorithm
*/
int bestDepth(char curr_board[BOARD_SIZE][BOARD_SIZE], char playing_color);

#endif
