#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#ifndef chesslogicH
#define chesslogicH

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <limits.h>
#include <ctype.h>
#include <math.h>
#include <time.h>


#define WHITE_P 'm'
#define WHITE_B 'b'
#define WHITE_N 'n'
#define WHITE_R 'r'
#define WHITE_Q 'q'
#define WHITE_K 'k'

#define BLACK_P 'M'
#define BLACK_B 'B'
#define BLACK_N 'N'
#define BLACK_R 'R'
#define BLACK_Q 'Q'
#define BLACK_K 'K'

#define EMPTY ' '

#define BOARD_SIZE 8
#define INPUT_SIZE 7

#define ENTER_SETTINGS "Enter game settings:\n" 
#define WRONG_GAME_MODE "Wrong game mode\n"
#define TWO_PLAYERS_GAME_MODE "Running game in 2 players mode\n"
#define PLAYER_VS_AI_GAME_MODE "Running game in player vs. AI mode\n"
#define WRONG_MINIMAX_DEPTH "Wrong value for minimax depth. The value should be between 1 to 4\n"
#define WRONG_FILE_NAME "Wrong file name\n"
#define WRONG_POSITION "Invalid position on the board\n"
#define NO_PIECE "Setting this piece creates an invalid board\n"  
#define WROND_BOARD_INITIALIZATION "Wrong board initialization\n"

#define ILLEGAL_COMMAND "Illegal command, please try again\n"
#define ILLEGAL_MOVE "Illegal move\n"

#define WRONG_ROOK_POSITION "Wrong position for a rook\n" 
#define ILLEGAL_CALTLING_MOVE "Illegal castling move\n"  

#define TIE "The game ends in a tie\n"
#define CHECK "Check!\n"

#define perror_message(func_name) (fprintf(stderr, "Error: standard function %s has failed\n", func_name))
#define print_message(message) (printf("%s", message));

#define MIN(a,b) (((a)<(b))?(a):(b));
#define MAX(a,b) (((a)>(b))?(a):(b));

typedef struct position {
	char x;
	int  y;
	struct position * next;
}position;

typedef struct move {
	position* current_pos;
	char* promotion;
	struct move * next;
}move;

typedef struct {
	move* head;
	move* tail;
}moves;


extern int minimax_depth;
extern int game_mode;
extern char next_player;
extern char user_color;
extern char board[BOARD_SIZE][BOARD_SIZE];
extern moves* best_moves;

extern position* white_kingpos;
extern position* black_kingpos;
/*
* Validates if memory alocated succesfuly
*/
void validate(void* object, char * func_name);
void freePositions(position* pos);
void freeMoves(move* move);
void printMoves(move* move, int print_first_move_only);
void init_board();

char** getInput();
void initMove(move* move);
void initPosition(position* pos, char x, int y);
void FreeInput(char** input);
int* piecesCounter(char playing_color);
int gameOver(int print_bit, char playing_color);

void boardCopy(char curr_board[BOARD_SIZE][BOARD_SIZE], char board_copy[BOARD_SIZE][BOARD_SIZE]);
void clear_board();
int WrongInitialization();
void print_line();
void print_board();

/*
* Checks if the pawn is in the last raw and should be promoted
*/
int isEdge(position* new_pos, char playing_color);
int isEqual(move* move1, move* move2);
int isValidPosition(position pos);
int IsEmpty(int x, int y, char board[BOARD_SIZE][BOARD_SIZE]);
char playingColor(int player1, int player2);
/*
* Updating the board with a legal move
*/
void actualBoardUpdate(move* current_move, char curr_board[BOARD_SIZE][BOARD_SIZE], 
	char playing_color, position* white_king_pos, position* black_king_pos);
int isValidAndLegalPiece(position* current_pos, char playing_color,int print_bit);
char OppositeColor(char playing_color);
void delay(unsigned long ms);
/*
* Checking if the new position conatains piece of the current playing color
*/
int isSameColor(char playing_color, position* new_pos, char curr_board[BOARD_SIZE][BOARD_SIZE]);
position* createPos(char* input);
move* createMoveFromInput(position* current_pos, char* input2, char* input3);
moves* getMovesFromPosition(char playing_color, char board[BOARD_SIZE][BOARD_SIZE], position* current_pos);
moves* getMoves(char playing_color, char board[BOARD_SIZE][BOARD_SIZE], position* white_king_pos, position* black_king_pos);
/*
* Concating a move to a list of moves
*/
moves* concatMoves(moves* moves_1, move* move2);
/*
* Getting all possible moves for a current player
*/
moves* getAllMoves(char playing_color, char curr_board[BOARD_SIZE][BOARD_SIZE]);
/*
* adds valid pawn moves from current position to  a given position
*/
void AddNewPawnMoves(position * current_pos, position * new_pos, char curr_board[BOARD_SIZE][BOARD_SIZE], moves * pawn_moves, char playing_color);
/*
* get all possible pawn moves from the current position
*/
moves * getPawnMoves(char playing_color, char curr_board[BOARD_SIZE][BOARD_SIZE], position* current_pos);
/*
* get all possible rook moves from the current position
*/
moves * getRookMoves(char playing_color, char curr_board[BOARD_SIZE][BOARD_SIZE], position* current_pos);
/*
* get all possible queen moves from the current position , queen moves simply combine rook and bishop moves from a current position.
*/
moves * getQueenMoves(char playing_color, char curr_board[BOARD_SIZE][BOARD_SIZE], position* current_pos);
/*
* get all possible king moves from the current position
*/
moves * getKingMoves(char playing_color, char curr_board[BOARD_SIZE][BOARD_SIZE], position* current_pos);


/*
checks if the playing_color king is threatend by a pawn
*/
int isThreatenedByPawn(position king_pos, char playing_color, char curr_board[BOARD_SIZE][BOARD_SIZE]);
/*
checks if the playing_color king is threatend by a bishop
*/
int isThreatenedByBishopOrQueen(position king_pos, char playing_color, char curr_board[BOARD_SIZE][BOARD_SIZE]);
/*
checks if the playing_color king is threatend by a Rook
*/
int isThreatenedByRookOrQueen(position king_pos, char playing_color, char curr_board[BOARD_SIZE][BOARD_SIZE]);
/*
checks if the playing_color king is threatend by a knight
*/
int isThreatenedByKnight(position king_pos, char playing_color, char curr_board[BOARD_SIZE][BOARD_SIZE]);
/*
checks if the playing_color king is threatend by a king
*/
int isThreatenedByKing(position king_pos, char playing_color, char curr_board[BOARD_SIZE][BOARD_SIZE]);

void removeBadMoves(moves* all_moves, char playing_color, char curr_board[BOARD_SIZE][BOARD_SIZE],
	position* white_king_pos, position* black_king_pos);

/*
* Checking if the game has ended in a Tie
*/
int isTie(char playing_color, char curr_board[BOARD_SIZE][BOARD_SIZE], position* w_king_pos, position* b_king_pos);

/*
* check if there is a legal move
*/
int LegalMoveExists(char playing_color, char curr_board[BOARD_SIZE][BOARD_SIZE], position* w_king_pos, position* b_king_pos);


/*
* Checking if there was a check performed by "playing_color" player
*/
int isCheck(char playing_color, char curr_board[BOARD_SIZE][BOARD_SIZE], position* white_king_pos, position* black_king_pos);
/*
* Checking if a Mate was performed by playing_color player
*/
int isMate(char playing_color, char curr_board[BOARD_SIZE][BOARD_SIZE], position* white_king_pos, position* black_king_pos);
/*
* Creating a copy of a given move
*/
move* copyMove(move* curr_move);
int isLegalMove(move* move1, char playing_color);
int scoringFunc(char curr_board[BOARD_SIZE][BOARD_SIZE], char playing_color, position* white_king_pos, position* black_king_pos);


#endif