#include "minimax.h"

/*
* Calculating the max depth that doesn't calculate more than 10^6 boards during the minimax algorithm
*/
int bestDepth(char curr_board[BOARD_SIZE][BOARD_SIZE], char playing_color){
	//counts the number of "playing_color" pieces on the board by type
	int* pieces = piecesCounter(playing_color);
	int total_poss_moves = 0;
	for (int i = 0; i < 6; i++){
		total_poss_moves += pieces[i] * MAX_POSS_MOVES; //Upper bound on the number of possible moves in depth 1
	}
	int depth=2;
	while (1){
		if (pow(total_poss_moves, depth)>pow(10, 6)){
			break;
		}
		depth++;
	}
	free(pieces);
	return --depth;
}

/*
* Minimax function - finding the score of the best move possible from the input board
*/
int alphabeta(char playing_color, char curr_board[BOARD_SIZE][BOARD_SIZE], int depth, int alpha, int beta,
	int maximizing, position * white_king_pos, position* black_king_pos) {

	if (depth == 0 ){
		return maximizing ? scoringFunc(curr_board, playing_color,white_king_pos,black_king_pos):
			scoringFunc(curr_board, OppositeColor(playing_color), white_king_pos, black_king_pos);
	}
	int score;
	char board_cpy[BOARD_SIZE][BOARD_SIZE];
	moves * all_moves = getMoves(playing_color, curr_board,white_king_pos,black_king_pos);
	move* curr_move = all_moves->head;
	//if there are no possible moves to the opponent, calculate the score of the current board. this is a terminal node.
	if (curr_move == NULL){
		free(all_moves);
		return maximizing ? scoringFunc(curr_board, playing_color, white_king_pos, black_king_pos) 
			: scoringFunc(curr_board, OppositeColor(playing_color), white_king_pos, black_king_pos);
	}
	if (maximizing) {
		score = INT_MIN;
		while (curr_move != NULL){
			boardCopy(curr_board, board_cpy);
			actualBoardUpdate(curr_move, board_cpy, playing_color, white_king_pos, black_king_pos);
			score = MAX(score,alphabeta(OppositeColor(playing_color), board_cpy, depth - 1, alpha, beta,
				!maximizing,white_king_pos,black_king_pos));
			alpha = MAX(alpha, score);
			if (beta <= alpha){
				break;
			}
			curr_move = curr_move->next;
		}
		freeMoves(all_moves->head); // curr_move
		free(all_moves);
		return alpha;
	}
	else {
		score = INT_MAX;
		while (curr_move != NULL){
			boardCopy(curr_board, board_cpy);
			actualBoardUpdate(curr_move, board_cpy, playing_color, white_king_pos, black_king_pos);
			score = MIN(score, alphabeta(OppositeColor(playing_color), board_cpy, depth - 1, alpha, beta,
				!maximizing, white_king_pos, black_king_pos));
			beta = MIN(beta, score);
			if (beta <= alpha){
				break; 
			}
			curr_move = curr_move->next;
		}
		freeMoves(all_moves->head);
		free(all_moves);
		return beta;
	}
}