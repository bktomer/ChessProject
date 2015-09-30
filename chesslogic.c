#include "chesslogic.h"

int minimax_depth = 1;
int game_mode = 1;
char next_player = 'W';
char user_color = 'W';
char board[BOARD_SIZE][BOARD_SIZE];
moves* best_moves;
position* white_kingpos;
position* black_kingpos;

/*
* Validates if memory alocated succesfuly
*/
void validate(void* object, char * func_name){
	if (object == NULL) {
		perror_message(func_name);
		exit(1);
	}
}
/*
* Freeing a list of positions
*/
void freePositions(position* pos){
	if (pos != NULL){
		freePositions(pos->next);
		free(pos);
	}
}
/*
* Freeing a list of moves
*/
void freeMoves(move* move){
	if (move != NULL){
		freePositions(move->current_pos);
		freeMoves(move->next);
		if (move->promotion != NULL){
			free(move->promotion);
		}
		free(move);
	}
}
/*
* Printing moves in a desirable format
*/
void printMoves(move* head , int print_first_move_only){
	move* curr_move = head;
	if (curr_move == NULL){
		return;
	}
	do{
		position* curr_pos = curr_move->current_pos;
		position* next_pos = curr_move->current_pos->next;
		if (curr_move->promotion != NULL){
			printf("<%c,%d> to <%c,%d> %s", curr_pos->x, curr_pos->y, next_pos->x, next_pos->y, curr_move->promotion);
		}
		else{
			printf("<%c,%d> to <%c,%d>", curr_pos->x, curr_pos->y, next_pos->x, next_pos->y);
		}
		curr_move = curr_move->next;
		printf("\n");
	} while (curr_move != NULL && !print_first_move_only);
}
/*
* Initializing a board function
*/
void init_board(){
	const char* rank = "RNBQKBNR";
	for (int col = 0; col < BOARD_SIZE; col++) {
		board[0][col] = (char)tolower(rank[col]);
		board[1][col] = 'm';
		board[2][col] = EMPTY;
		board[3][col] = EMPTY;
		board[4][col] = EMPTY;
		board[5][col] = EMPTY;
		board[6][col] = 'M';
		board[7][col] = rank[col];
	}
}
/*
* Recieving an input as 7 word string array
*/
char** getInput() {
	char ** input = calloc(INPUT_SIZE, sizeof(char*));
	validate(input, "getInput");
	int i = 0, j = 1, k = 0;
	char* word = calloc(1, sizeof(char));
	validate(word, "getInput");
	char c = '\0';
	while (c != '\n')
	{
		c = getchar();
		if (c == ' ' && word != '\0') {
			word[i] = '\0';
			input[k++] = word;
			word = calloc(1, sizeof(char));
			validate(word, "getInput");
			j = 1, i = 0;
			continue;
		}
		else if (c == ' ') {
			continue;
		}
		j++;
		word = (char*)realloc(word, j*sizeof(char));
		validate(word, "getInput");
		word[i] = c;
		i++;
	}
	word[i - 1] = '\0';
	input[k] = word;
	return input;

}
/*
* Initializing a move with default variables
*/
void initMove(move* move) {
	move->current_pos = NULL;
	move->promotion = NULL;
	move->next = NULL;
}

/*
* Initializing a position with given variables
*/
void initPosition(position* pos, char x, int y){
	pos->x = x;
	pos->y = y;
	pos->next = NULL;
}

/*
* Input freeing function
*/
void FreeInput(char** input) {
	for (int i = 0; i < INPUT_SIZE; i++) {
		if (input[i] != 0){
			free(input[i]);
		}
	}
}
/*
* Counting pieces on the board of the specified player
* 0=rook ; 1=knight ; 2=bishop ; 3=queen ; 4= king ;5=pawn 
*/
int* piecesCounter(char playing_color) {
	int* counter = calloc(6, sizeof(int));
	validate(counter, "piecesCounter");
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			if (playing_color == 'W'){
				if (board[i][j] == WHITE_R){
					counter[0]++;
					continue;
				}
				if (board[i][j] == WHITE_N){
					counter[1]++;
					continue;
				}
				if (board[i][j] == WHITE_B){
					counter[2]++;
					continue;
				}
				if (board[i][j] == WHITE_Q){
					counter[3]++;
					continue;
				}
				if (board[i][j] == WHITE_K){
					counter[4]++;
					continue;
				}
				if (board[i][j] == WHITE_P){
					counter[5]++;
				}
			}
			else {
				if (board[i][j] == BLACK_R){
					counter[0]++;
					continue;
				}
				if (board[i][j] == BLACK_N){
					counter[1]++;
					continue;
				}
				if (board[i][j] == BLACK_B){
					counter[2]++;
					continue;
				}
				if (board[i][j] == BLACK_Q){
					counter[3]++;
					continue;
				}
				if (board[i][j] == BLACK_K){
					counter[4]++;
					continue;
				}
				if (board[i][j] == BLACK_P){
					counter[5]++;
				}
			}
		}
	}
	return counter;
}


/*
checks if the playing_color king is threatend by a pawn
*/
int isThreatenedByPawn(position king_pos, char playing_color, char curr_board[BOARD_SIZE][BOARD_SIZE]){
	int x = king_pos.x - 97;
	int y = king_pos.y - 1;

	position top_right_pos = { king_pos.x + 1, king_pos.y + 1, NULL };
	position top_left_pos = { king_pos.x - 1, king_pos.y + 1, NULL };
	position down_right_pos = { king_pos.x + 1, king_pos.y - 1, NULL };
	position down_left_pos = { king_pos.x - 1, king_pos.y - 1, NULL };

	if (playing_color == 'W') {
		//checks if there is a black pawn at (x+1,y+1) or (x-1,y+1)
		if ((isValidPosition(top_right_pos) && curr_board[y + 1][x + 1] == BLACK_P) || (isValidPosition(top_left_pos) && curr_board[y + 1][x - 1] == BLACK_P)) {
			return 1;
		}
	}
	else {
		//checks if there is a white pawn at (x+1,y-1) or (x-1,y-1)
		if ((isValidPosition(down_right_pos) && curr_board[y - 1][x + 1] == WHITE_P) || (isValidPosition(down_left_pos) && curr_board[y - 1][x - 1] == WHITE_P)) {
			return 1;
		}
	}

	return 0;
}

int isThreatenedByBishopOrQueen(position king_pos, char playing_color, char curr_board[BOARD_SIZE][BOARD_SIZE]) {
	int moved_top_right_diag = 0; int moved_top_left_diag = 0;
	int moved_down_right_diag = 0; int moved_down_left_diag = 0;
	char opposite_bishop = playing_color == 'W' ? BLACK_B : WHITE_B;
	char opposite_queen = playing_color == 'W' ? BLACK_Q : WHITE_Q;
	int x = king_pos.x-97;
	int y = king_pos.y - 1;
	for (int i = 1; i < BOARD_SIZE - 1; i++) {
		if (moved_down_left_diag && moved_down_right_diag && moved_top_right_diag && moved_top_left_diag) {
			return 0;
		}

		//checking (x+i,y+i)
		position top_right_pos = { king_pos.x + i, king_pos.y + i, NULL };
		if (!moved_top_right_diag && isValidPosition(top_right_pos)) {
			if (curr_board[y + i][x + i] == opposite_bishop || curr_board[y+i][x+i] == opposite_queen) {
				return 1;
			}
			//if no bishop/queen found on this diagonal and there is another piece , stop searching this daigonal
			else if (curr_board[y + i][x + i] != EMPTY) {
				moved_top_right_diag = 1;
			}
		}

		//checking (x-i,y+i)
		position top_left_pos = { king_pos.x - i, king_pos.y + i ,NULL};
		if (!moved_top_left_diag && isValidPosition(top_left_pos)) {
			if (curr_board[y + i][x - i] == opposite_bishop || curr_board[y + i][x - i] == opposite_queen) {
				return 1;
			}
			else if (curr_board[y + i][x - i] != EMPTY) {
				moved_top_left_diag = 1;
			}
		}

		//checking (x+i,y-i)
		position down_right_pos = { king_pos.x + i, king_pos.y - i, NULL };
		if (!moved_down_right_diag && isValidPosition(down_right_pos)) {
			if (curr_board[y - i][x + i] == opposite_bishop || curr_board[y - i][x + i] == opposite_queen) {
				return 1;
			}
			else if (curr_board[y - i][x + i] != EMPTY) {
				moved_down_right_diag = 1;
			}
		}

		//checking (x-i,y-i)
		position down_left_pos = { king_pos.x - i, king_pos.y - i, NULL };
		if (!moved_down_left_diag && isValidPosition(down_left_pos)) {
			if (curr_board[y - i][x - i] == opposite_bishop || curr_board[y - i][x - i] == opposite_queen) {
				return 1;
			}
			else if (curr_board[y - i][x - i] != EMPTY) {
				moved_down_left_diag = 1;
			}
		}
	}
	return 0; 
}


int isThreatenedByRookOrQueen(position king_pos, char playing_color, char curr_board[BOARD_SIZE][BOARD_SIZE]) {
	int moved_top = 0; int moved_down = 0;
	int moved_right= 0; int moved_left = 0;
	char opposite_rook = playing_color == 'W' ? BLACK_R : WHITE_R;
	char opposite_queen = playing_color == 'W' ? BLACK_Q : WHITE_Q;
	int x = king_pos.x - 97;
	int y = king_pos.y - 1;
	for (int i = 1; i < BOARD_SIZE ; i++) {
		if (moved_down && moved_right && moved_top && moved_left) {
			return 0;
		}

		//checking (x,y+i)
		position top_pos = { king_pos.x , king_pos.y + i, NULL };
		if (!moved_top && isValidPosition(top_pos)) {
			if (curr_board[y + i][x] == opposite_rook || curr_board[y + i][x] == opposite_queen) {
				return 1;
			}
			//if no rook/queen found on this diagonal and there is another piece , stop searching this daigonal
			else if (curr_board[y + i][x ] != EMPTY) {
				moved_top = 1;
			}
		}

		//checking (x,y-i)
		position down_pos = { king_pos.x , king_pos.y - i, NULL };
		if (!moved_down && isValidPosition(down_pos)) {
			if (curr_board[y - i][x] == opposite_rook || curr_board[y - i][x] == opposite_queen) {
				return 1;
			}
			else if (curr_board[y - i][x] != EMPTY) {
				moved_down = 1;
			}
		}

		//checking (x+i,y)
		position right_pos = { king_pos.x + i, king_pos.y, NULL };
		if (!moved_right && isValidPosition(right_pos)) {
			if (curr_board[y][x + i] == opposite_rook || curr_board[y ][x + i] == opposite_queen) {
				return 1;
			}
			else if (curr_board[y][x + i] != EMPTY) {
				moved_right = 1;
			}
		}

		//checking (x-i,y)
		position left_pos = { king_pos.x - i, king_pos.y, NULL };
		if (!moved_left && isValidPosition(left_pos)) {
			if (curr_board[y ][x - i] == opposite_rook || curr_board[y][x - i] == opposite_queen) {
				return 1;
			}
			else if (curr_board[y][x - i] != EMPTY) {
				moved_left= 1;
			}
		}
	}
	return 0;
}

int isThreatenedByKing(position king_pos , char playing_color, char curr_board[BOARD_SIZE][BOARD_SIZE]) {
	char opp_king = playing_color == 'W' ? BLACK_K : WHITE_K;

	int x = king_pos.x - 97;
	int y = king_pos.y - 1;

	position top_pos = { king_pos.x, king_pos.y + 1, NULL };
	//checks if there is an opposite king at (x,y+1)
	if (isValidPosition(top_pos) && curr_board[y+1][x]==opp_king)	{
		return 1;
	}
	//checks if there is an opposite king at (x+1,y+1)
	position top_right_pos = { king_pos.x+1, king_pos.y + 1, NULL };
	if (isValidPosition(top_right_pos) && curr_board[y + 1][x+1] == opp_king)	{
		return 1;
	}
	position top_left_pos = { king_pos.x-1, king_pos.y + 1, NULL };
	//checks if there is an opposite king at (x-1,y+1)
	if (isValidPosition(top_left_pos) && curr_board[y + 1][x-1] == opp_king)	{
		return 1;
	}
	//checks if there is an opposite king at (x+1,y)
	position right_pos = { king_pos.x + 1, king_pos.y, NULL };
	if (isValidPosition(right_pos) && curr_board[y][x + 1] == opp_king)	{
		return 1;
	}

	//checks if there is an opposite king at (x-1,y)
	position left_pos = { king_pos.x - 1, king_pos.y, NULL };
	if (isValidPosition(left_pos) && curr_board[y][x - 1] == opp_king)	{
		return 1;
	}
	//checks if there is an opposite king at (x,y-1)
	position down_pos = { king_pos.x , king_pos.y-1, NULL };
	if (isValidPosition(down_pos) && curr_board[y-1][x] == opp_king)	{
		return 1;
	}

	//checks if there is an opposite king at (x+1,y-1)
	position down_right_pos = { king_pos.x + 1, king_pos.y-1, NULL };
	if (isValidPosition(down_right_pos) && curr_board[y-1][x + 1] == opp_king)	{
		return 1;
	}
	//checks if there is an opposite king at (x-1,y-1)
	position down_left_pos = { king_pos.x - 1, king_pos.y-1, NULL };
	if (isValidPosition(down_left_pos) && curr_board[y-1][x - 1] == opp_king)	{
		return 1;
	}
	return 0;
	
}


int isThreatenedByKnight(position king_pos, char playing_color, char curr_board[BOARD_SIZE][BOARD_SIZE]) {
	char opp_knight = playing_color == 'W' ? BLACK_N : WHITE_N;

	int x = king_pos.x - 97;
	int y = king_pos.y - 1;

	position top_right1_pos = { king_pos.x+1, king_pos.y + 2, NULL };
	//checks if there is an opposite knight at (x+1,y+2)
	if (isValidPosition(top_right1_pos) && curr_board[y + 2][x+1] == opp_knight)	{
		return 1;
	}
	//checks if there is an opposite knight at (x+2,y+1)
	position top_right2_pos = { king_pos.x + 2, king_pos.y + 1, NULL };
	if (isValidPosition(top_right2_pos) && curr_board[y + 1][x + 2] == opp_knight)	{
		return 1;
	}
	position top_left1_pos = { king_pos.x - 1, king_pos.y + 2, NULL };
	//checks if there is an opposite knight at (x-1,y+2)
	if (isValidPosition(top_left1_pos) && curr_board[y + 2][x - 1] == opp_knight)	{
		return 1;
	}
	//checks if there is an opposite knight at (x-2,y+1)
	position top_left2_pos = { king_pos.x -2, king_pos.y+1, NULL };
	if (isValidPosition(top_left2_pos) && curr_board[y+1][x - 2] == opp_knight)	{
		return 1;
	}

	//checks if there is an opposite knight at (x+1,y-2)
	position down_right1_pos = { king_pos.x + 1, king_pos.y-2, NULL };
	if (isValidPosition(down_right1_pos) && curr_board[y - 2][x + 1] == opp_knight)	{
		return 1;
	}
	//checks if there is an opposite knight at (x+2,y-1)
	position down_right2_pos = { king_pos.x+2, king_pos.y - 1, NULL };
	if (isValidPosition(down_right2_pos) && curr_board[y - 1][x+2] == opp_knight)	{
		return 1;
	}

	//checks if there is an opposite knight at (x-1,y-2)
	position down_left1_pos = { king_pos.x - 1, king_pos.y - 2, NULL };
	if (isValidPosition(down_left1_pos) && curr_board[y - 2][x - 1] == opp_knight)	{
		return 1;
	}
	//checks if there is an opposite knight at (x-2,y-1)
	position down_left2_pos = { king_pos.x - 2, king_pos.y - 1, NULL };
	if (isValidPosition(down_left2_pos) && curr_board[y - 1][x - 2] == opp_knight)	{
		return 1;
	}
	return 0;

}

/*
* Checking if there was a check performed by "playing_color" player
*/
int isCheck(char playing_color , char curr_board[BOARD_SIZE][BOARD_SIZE],position* w_k_pos, position* b_k_pos){
	position king_pos = (playing_color == 'W') ? *b_k_pos : *w_k_pos;
	char opp_color = OppositeColor(playing_color);
	int pawn_threat = isThreatenedByPawn(king_pos, opp_color, curr_board);
	int bishop_or_queen_threat = isThreatenedByBishopOrQueen(king_pos, opp_color, curr_board);
	int rook_or_queen_threat = isThreatenedByRookOrQueen(king_pos, opp_color, curr_board);
	int knight_threat = isThreatenedByKnight(king_pos, opp_color, curr_board);
	int king_threat = isThreatenedByKing(king_pos, opp_color, curr_board);

	return pawn_threat || knight_threat || king_threat || bishop_or_queen_threat || rook_or_queen_threat ;
}

/*
* Checking if a Mate was performed by playing_color player
*/
int isMate(char playing_color, char curr_board[BOARD_SIZE][BOARD_SIZE],position* w_king_pos,position* b_king_pos){
	if (!isCheck(playing_color, curr_board, w_king_pos, b_king_pos)){
		return 0;
	}
	int ret = !LegalMoveExists(OppositeColor(playing_color), curr_board, w_king_pos, b_king_pos);
	return ret;
	
}

/*
* Checking if the game has ended in a Mate or a Tie
*/
int gameOver(int print_bit, char playing_color){
	if (isMate(playing_color, board, white_kingpos, black_kingpos)){
		if (print_bit){
			playing_color=='W' ? printf("Mate! White player wins the game\n") :
								 printf("Mate! Black player wins the game\n") ;
		}
		return 1;
	}
	if (isTie(playing_color,board, white_kingpos, black_kingpos)){
		if (print_bit){
			printf("The game ends in a tie\n");
		}
		return 1;
	}
	return 0;
}

/*
* Creating a copy of a given board
*/
void boardCopy(char curr_board[BOARD_SIZE][BOARD_SIZE], char board_copy[BOARD_SIZE][BOARD_SIZE]){
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			board_copy[i][j] = curr_board[i][j];
		}
	}
}

/*
* Board cleaning function
*/
void clear_board() {
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			board[i][j] = EMPTY;
		}
	}
}

/*
* Checks if the pawn is in the last raw and should be promoted
*/
int isEdge(position* new_pos, char playing_color){
	switch (playing_color) {
	case 'B':
		if (new_pos->y == 1){
			return 1;
		}
		break;
	default:
		if (new_pos->y == BOARD_SIZE){
			return 1;
		}
	}
	return 0;

}

/*
* Checking if the board was not initialized correctly
*/
int WrongInitialization(){

	int* piecesW; int* piecesB;
	piecesW = piecesCounter('W');
	piecesB = piecesCounter('B');
	if (piecesW[4] != 1 || piecesB[4] != 1){
		print_message(WROND_BOARD_INITIALIZATION);
		free(piecesW);
		free(piecesB);
		return 1;
	}
	free(piecesW);
	free(piecesB);
	return 0;
}

/*
* Print line function
*/
void print_line(){
	int i;
	printf("  |");
	for (i = 1; i < BOARD_SIZE * 4; i++){
		printf("-");
	}
	printf("|\n");
}

/*
*  Board printing function
*/
void print_board()
{
	int i, j;
	print_line();
	for (i = BOARD_SIZE - 1; i >= 0; i--)
	{
		printf((i < 9 ? " %d" : "%d"), i + 1);
		for (j = 0; j < BOARD_SIZE; j++){
			printf("| %c ", board[i][j]);
		}
		printf("|\n");
		print_line();
	}
	printf("   ");
	for (j = 0; j < BOARD_SIZE; j++){
		printf(" %c  ", (char)('a' + j));
	}
	printf("\n");
}



/*
* Checking if two given moves are equal by comparing positions
*/
int isEqual(move* move1, move* move2){
	position* pos1 = move1->current_pos;
	position* pos2 = move2->current_pos;
	if ((move1->promotion != NULL && (move2->promotion != NULL))){
		if (strcmp(move1->promotion, move2->promotion)){
			return 0;
		}
	}
	else if ((move1->promotion == NULL && (move2->promotion != NULL)) || (move1->promotion != NULL && (move2->promotion == NULL))){
		return 0;
	}
	while (pos1 != NULL){
		if (pos1->x != pos2->x || pos2->y != pos1->y){
			return 0;
		}
		pos1 = pos1->next;
		pos2 = pos2->next;
	}
	return 1;
}

/*
* Checking if a given position is valid
*/
int isValidPosition(position pos) {
	if ((pos.x > 'h' || pos.x < 'a') || (pos.y < 1 || pos.y>BOARD_SIZE)) {
		return 0;
	}
	return 1;
}

/*
* Checking if a given square is empty
*/
int IsEmpty(int x, int y, char curr_board[BOARD_SIZE][BOARD_SIZE]){
	if (curr_board[y][x] == EMPTY){
		return 1;
	}
	return 0;
}

/*
* Acquiring the current playing color in a given gaming mode
*/
char playingColor(int player1, int player2){
	char curr_playing_color;
	if (game_mode == 2){
		if (player1 && player2){
			curr_playing_color = user_color;
		}
		else{
			if (user_color == 'W'){
				curr_playing_color = 'B';
			}
			else{
				curr_playing_color = 'W';
			}
		}
	}
	else{
		if (player1){
			curr_playing_color = 'W';
		}
		else{
			curr_playing_color = 'B';
		}
	}
	return curr_playing_color;
}

/*
* Updating the board with a legal move
*/
void actualBoardUpdate(move* current_move, char curr_board[BOARD_SIZE][BOARD_SIZE], char playing_color ,position* white_king_pos,position* black_king_pos){
	position* curr_pos = current_move->current_pos;
	int curr_x = curr_pos->x - 97;
	int curr_y = curr_pos->y - 1;

	position* next_pos = curr_pos->next;
	int next_x = next_pos->x - 97;
	int next_y = next_pos->y - 1;

	//promoting the pawn if needed

	if (isEdge(next_pos, playing_color) && ((curr_board[curr_y][curr_x] == BLACK_P && playing_color == 'B') || (curr_board[curr_y][curr_x] == WHITE_P && playing_color == 'W'))){
		char* promotion = current_move->promotion;

		if (promotion == NULL){
			curr_board[next_y][next_x] = (playing_color == 'W') ? WHITE_Q : BLACK_Q;
		}
		else if (!strcmp(promotion, "rook")){
			curr_board[next_y][next_x] = (playing_color == 'W') ? WHITE_R : BLACK_R;
		}
		else if (!strcmp(promotion, "knight")){
			curr_board[next_y][next_x] = (playing_color == 'W') ? WHITE_N : BLACK_N;
		}
		else if (!strcmp(promotion, "bishop")){
			curr_board[next_y][next_x] = (playing_color == 'W') ? WHITE_B : BLACK_B;
		}
		else{
			curr_board[next_y][next_x] = (playing_color == 'W') ? WHITE_Q : BLACK_Q;
		}
	}
	else{
		//updating white/black king position on the board if needed
		if (curr_board[curr_y][curr_x] == BLACK_K){
			black_king_pos->x = next_pos->x;
			black_king_pos->y = next_pos->y;
		}
		else if (curr_board[curr_y][curr_x] == WHITE_K){
			white_king_pos->x = next_pos->x;
			white_king_pos->y = next_pos->y;
		}
		curr_board[next_y][next_x] = curr_board[curr_y][curr_x];
	}
	curr_board[curr_y][curr_x] = EMPTY; //removing the old position of the man from the board	
}


/*
* Checking if the position is valid and that the specified position contains piece of the right color
*/
int isValidAndLegalPiece(position* current_pos, char playing_color,int print_bit){
	position* temp_pos = current_pos;
	while (temp_pos != NULL){
		if (!isValidPosition(*temp_pos)){
			if (print_bit){
				print_message(WRONG_POSITION);
			}
			return 0;
		}
		temp_pos = temp_pos->next;
	}
	if (!isSameColor(playing_color,current_pos,board))
	{
		if (print_bit){
			print_message("The specified position does not contain your piece\n");
		}
		return 0;
	}
	return 1;
}


/*
* Create position from input
*/
position* createPos(char* input){
	position * current_pos = malloc(sizeof(position));
	validate(current_pos, "createPos");
	char x = input[1];
	char* digit_pos = input + 3;
	int y = (int)strtol(digit_pos, (char**)NULL, 10);
	initPosition(current_pos, x, y);
	return current_pos;
}

/*
* Extracting a move from the user input "move <x,y> to <u,v> x"
*/
move* createMoveFromInput(position* current_pos, char* input2, char* input3){
	position* next_pos = createPos(input2);
	move* new_move = malloc(sizeof(move));
	validate(new_move, "createMoveFromInput");
	initMove(new_move);
	new_move->current_pos = current_pos;
	new_move->current_pos->next = next_pos;
	next_pos->next = NULL;
	if (input3!= NULL){
		int len = strlen(input3);
		new_move->promotion = calloc(len + 1, sizeof(char));
		validate(new_move->promotion, "createMoveFromInput");
		strcpy(new_move->promotion, input3);
		new_move->promotion[len] = '\0';
	}
	return new_move;
}

/*
* Concating a move to a list of moves
*/
moves* concatMoves(moves* moves_1, move* move2){
	if (move2==NULL || move2->current_pos == NULL){
		return moves_1;
	}
	if (moves_1->tail == NULL){
		moves_1->head = move2;
		moves_1->tail = move2;
		move2 = move2->next;
	}
	if (move2 != NULL){
		moves_1->tail->next = move2;
		moves_1->tail = move2;
		move* next_move = move2;
		while (next_move->next != NULL) {
			next_move = next_move->next;
			moves_1->tail = next_move;
		}
	}

	return moves_1;
}



/*
* Checking if the new position conatains piece of the current playing color
*/
int isSameColor(char playing_color, position* new_pos, char curr_board[BOARD_SIZE][BOARD_SIZE]) {
	char square = curr_board[new_pos->y - 1][new_pos->x - 97];
	if (square == EMPTY){
		return 0;
	}
	return ((playing_color == 'W' && ((square == WHITE_R || square == WHITE_N) || (square == WHITE_B || square == WHITE_Q) || (square == WHITE_K || square == WHITE_P))) ||
		((playing_color == 'B' && ((square == BLACK_R || square == BLACK_N) || (square == BLACK_B || square == BLACK_Q) || (square == BLACK_K || square == BLACK_P)))));
}

/*
* returning the opposite color of playing_color
*/
char OppositeColor(char playing_color) {
	return playing_color == 'W' ? 'B' : 'W';
}

/*
* removing moves that end up with check on the playing color's king
*/
void removeBadMoves(moves* all_moves, char playing_color, char curr_board[BOARD_SIZE][BOARD_SIZE], position* w_king_pos, position* b_king_pos){
	move* curr_move = all_moves->head;
	position w_k_pos_cpy; position b_k_pos_cpy;
	while (curr_move != NULL){
		char temp_board[BOARD_SIZE][BOARD_SIZE];
		boardCopy(curr_board, temp_board);
		initPosition(&w_k_pos_cpy, w_king_pos->x, w_king_pos->y);
		initPosition(&b_k_pos_cpy, b_king_pos->x, b_king_pos->y);
		actualBoardUpdate(curr_move, temp_board, playing_color, &w_k_pos_cpy, &b_k_pos_cpy);
		if (curr_move == all_moves->head && isCheck(OppositeColor(playing_color), temp_board, &w_k_pos_cpy, &b_k_pos_cpy)) {
			all_moves->head = all_moves->head->next;
			freePositions(curr_move->current_pos);
			if (curr_move->promotion != NULL){
				free(curr_move->promotion);
			}
			free(curr_move);
			curr_move = all_moves->head;
			continue;
		}
		else if (curr_move->next != NULL) {
			boardCopy(curr_board, temp_board);
			initPosition(&w_k_pos_cpy, w_king_pos->x, w_king_pos->y);
			initPosition(&b_k_pos_cpy, b_king_pos->x, b_king_pos->y);
			actualBoardUpdate(curr_move->next, temp_board, playing_color, &w_k_pos_cpy, &b_k_pos_cpy);
			if (isCheck(OppositeColor(playing_color), temp_board, &w_k_pos_cpy, &b_k_pos_cpy)){
				move* temp_move = curr_move->next;
				curr_move->next = curr_move->next->next;
				if (temp_move == all_moves->tail){
					all_moves->tail = curr_move;
				}
				freePositions(temp_move->current_pos);
				if (temp_move->promotion != NULL){
					free(temp_move->promotion);
				}
				free(temp_move);
				continue;
			}
			
		}
		curr_move = curr_move->next;
	}
}


void updateKingsPositions(){
	int w_k_found = 0; int b_k_found = 0;
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			if (w_k_found && b_k_found) {
				break;
			}
			if (board[i][j] == WHITE_K) {
				white_kingpos = calloc(1, sizeof(position));
				validate(white_kingpos, "updateKingsPositions");
				initPosition(white_kingpos, j + 97, i + 1);
				w_k_found = 1;
			}
			else if (board[i][j] == BLACK_K){
				black_kingpos = calloc(1, sizeof(position));
				validate(black_kingpos, "updateKingsPositions");
				initPosition(black_kingpos, j + 97, i + 1);
				b_k_found = 1;
			}
		}
	}
}

/*
* create a move from (x,y) to (x+ x_offset, y+ y_offset)
*/
move* CreateMove(position * current_pos, int x_offset , int y_offset) {
	position * start_pos = calloc(1, sizeof(position));
	validate(start_pos, "CreateMove");
	position * new_pos = calloc(1,sizeof(position));
	validate(new_pos, "CreateMove");
	initPosition(new_pos, current_pos->x+x_offset, current_pos->y+y_offset);
	initPosition(start_pos, current_pos->x , current_pos->y );
	move *new_move = calloc(1,sizeof(move));
	validate(new_move, "CreateMove");
	initMove(new_move);
	new_move->current_pos = start_pos;
	new_move->current_pos->next = new_pos;
	return new_move;
}

/*
* adds valid pawn moves from current position to  a given position
*/
void AddNewPawnMoves(position * current_pos , position * new_pos, char curr_board[BOARD_SIZE][BOARD_SIZE], moves * pawn_moves , char playing_color){
	int x_offset = new_pos->x - current_pos->x;
	int y_offset = new_pos->y - current_pos->y;
	if ((isValidPosition(*new_pos) && !isSameColor(playing_color, new_pos, curr_board) && !IsEmpty(new_pos->x - 97, new_pos->y - 1, curr_board) && (x_offset != 0)) ||
		((x_offset == 0) && isValidPosition(*new_pos) && IsEmpty(new_pos->x-97, new_pos->y-1, curr_board))){
		move * new_move = CreateMove(current_pos, x_offset, y_offset);
		concatMoves(pawn_moves, new_move);
		char* ranks[4] = { "queen", "bishop", "rook", "knight" };
		//adds all possible promotion moves
		if (isEdge(new_pos, playing_color)){
			for (int i = 0; i < 4; i++){
				new_move = CreateMove(current_pos, x_offset, y_offset);
				new_move->promotion = calloc(strlen(ranks[i]) + 1, sizeof(char));
				validate(new_move->promotion, "getPawnMoves");
				strcpy(new_move->promotion, ranks[i]);
				new_move->promotion[strlen(ranks[i])] = '\0';
				concatMoves(pawn_moves, new_move);
			}
		}
	}
}

/*
* get all possible pawn moves from the current position
*/
moves * getPawnMoves(char playing_color, char curr_board[BOARD_SIZE][BOARD_SIZE], position* current_pos){
	moves * pawn_moves = calloc(1, sizeof(moves));
	validate(pawn_moves, "getPawnMoves");
	if (playing_color == 'W'){
		//adds all capture moves to (x+1,y+1)
		position  new_pos = { current_pos->x + 1, current_pos->y + 1, NULL };
		AddNewPawnMoves(current_pos, &new_pos, curr_board, pawn_moves, playing_color);
		//adds all capture moves to (x-1,y+1)
		position  new_pos2 = { current_pos->x - 1, current_pos->y + 1, NULL };
		AddNewPawnMoves(current_pos, &new_pos2, curr_board, pawn_moves, playing_color);
		//adds all  moves to (x,y+1)
		position  new_pos3 = { current_pos->x , current_pos->y + 1, NULL };
		AddNewPawnMoves(current_pos, &new_pos3, curr_board, pawn_moves, playing_color);
	}
	else { //black player turn
		//adds all capture moves to (x-1,y-1)
		position  new_pos = { current_pos->x - 1, current_pos->y - 1, NULL };
		AddNewPawnMoves(current_pos, &new_pos, curr_board, pawn_moves, playing_color);
		//adds all capture moves to (x+1,y-1)
		position  new_pos2 = { current_pos->x + 1, current_pos->y - 1, NULL };
		AddNewPawnMoves(current_pos, &new_pos2, curr_board, pawn_moves, playing_color);
		//adds all  moves to (x,y-1)
		position  new_pos3 = { current_pos->x, current_pos->y - 1, NULL };
		AddNewPawnMoves(current_pos, &new_pos3, curr_board, pawn_moves, playing_color);	
	}
	return pawn_moves;
}

/*
* get all possible bishop moves from the current position
*/
moves * getBishopMoves(char playing_color, char curr_board[BOARD_SIZE][BOARD_SIZE], position* current_pos){
	//flags that symbolizes we cannot move longer on the corresponding diagonal
	int moved_topRight_diag = 0; int moved_topLeft_diag = 0;
	int moved_downRight_diag = 0; int moved_downLeft_diag = 0;
	moves * bishop_moves = calloc(1, sizeof(moves));
	validate(bishop_moves, "getBishopMoves");
	for (int i = 1; i < BOARD_SIZE; i++) {
		if (moved_downLeft_diag && moved_topLeft_diag && moved_downRight_diag && moved_topRight_diag){
			break;
		}
		position next_pos = { current_pos->x + i, current_pos->y + i, NULL };
		move* new_move;
		//check if there is a legal  move from (x,y) to (x+i,y+i)
		if (!moved_topRight_diag && isValidPosition(next_pos)){
			if (IsEmpty(next_pos.x-97, next_pos.y-1, curr_board)){
				new_move = CreateMove(current_pos, i, i);
				concatMoves(bishop_moves, new_move);
			}
			else if (!isSameColor(playing_color, &next_pos, curr_board) && !IsEmpty(next_pos.x-97, next_pos.y-1, curr_board)){
				new_move = CreateMove(current_pos, i, i);
				concatMoves(bishop_moves, new_move);
				moved_topRight_diag = 1;
			}
			else {
				moved_topRight_diag = 1;
			}
		}
		//check if there is a legal non-capture move from (x,y) to (x+i,y-i)
		position next_pos1 = { current_pos->x + i, current_pos->y - i, NULL };
		if (!moved_downRight_diag && isValidPosition(next_pos1)){
			if (IsEmpty(next_pos1.x-97, next_pos1.y-1, curr_board)){
				new_move = CreateMove(current_pos, i, -i);
				concatMoves(bishop_moves, new_move);
			}
			else if (!isSameColor(playing_color, &next_pos1, curr_board) && !IsEmpty(next_pos1.x-97, next_pos1.y-1, curr_board)){
				new_move = CreateMove(current_pos, i, -i);
				concatMoves(bishop_moves, new_move);
				moved_downRight_diag = 1;
			}
			else {
				moved_downRight_diag = 1;
			}
		}
		//check if there is a legal non-capture move from (x,y) to (x-i,y-i)
		position next_pos2 = { current_pos->x - i, current_pos->y - i, NULL };
		if (!moved_downLeft_diag && isValidPosition(next_pos2)){
			if (IsEmpty(next_pos2.x-97, next_pos2.y-1, curr_board)){
				new_move = CreateMove(current_pos, -i, -i);
				concatMoves(bishop_moves, new_move);
			}
			else if (!isSameColor(playing_color, &next_pos2, curr_board) && !IsEmpty(next_pos2.x-97, next_pos2.y-1, curr_board)){
				new_move = CreateMove(current_pos, -i, -i);
				concatMoves(bishop_moves, new_move);
				moved_downLeft_diag = 1;
			}
			else {
				moved_downLeft_diag = 1;
			}
		}
		//check if there is a legal non-capture move from (x,y) to (x-i,y+i)
		position next_pos3 = { current_pos->x - i, current_pos->y + i, NULL };
		if (!moved_topLeft_diag && isValidPosition(next_pos3)){
			if (IsEmpty(next_pos3.x-97, next_pos3.y-1, curr_board)){
				new_move = CreateMove(current_pos, -i, i);
				concatMoves(bishop_moves, new_move);
			}
			else if (!isSameColor(playing_color, &next_pos3, curr_board) && !IsEmpty(next_pos3.x-97, next_pos3.y-1, curr_board)){
				new_move = CreateMove(current_pos, -i, i);
				concatMoves(bishop_moves, new_move);
				moved_topLeft_diag = 1;
			}
			else {
				moved_topLeft_diag = 1;
			}
		}

	}
	return bishop_moves;


}

/*
* get all possible rook moves from the current position
*/
moves * getRookMoves(char playing_color, char curr_board[BOARD_SIZE][BOARD_SIZE], position* current_pos){
	//flags that symbolizes we cannot move longer on the corresponding diagonal
	int moved_top = 0; int moved_Left = 0;
	int moved_Right = 0; int moved_down = 0;
	moves * rook_moves = calloc(1, sizeof(moves));
	validate(rook_moves, "getRookMoves");
	for (int i = 1; i < BOARD_SIZE; i++) {
		if (moved_top && moved_Left && moved_down && moved_Right){
			break;
		}
		position next_pos = { current_pos->x , current_pos->y + i, NULL };
		move* new_move;
		//check if there is a legal non-capture move from (x,y) to (x,y+i)
		if (!moved_top && isValidPosition(next_pos)){
			if (IsEmpty(next_pos.x-97, next_pos.y-1, curr_board)){
				new_move = CreateMove(current_pos, 0, i);
				concatMoves(rook_moves, new_move);
			}
			else if (!isSameColor(playing_color, &next_pos, curr_board) && !IsEmpty(next_pos.x-97, next_pos.y-1, curr_board)){
				new_move = CreateMove(current_pos, 0, i);
				concatMoves(rook_moves, new_move);
				moved_top = 1;
			}
			else {
				moved_top = 1;
			}
		}
		//check if there is a legal non-capture move from (x,y) to (x,y-i)
		position next_pos1 = { current_pos->x , current_pos->y - i, NULL };
		if (!moved_down && isValidPosition(next_pos1)){
			if (IsEmpty(next_pos1.x-97, next_pos1.y-1, curr_board)){
				new_move = CreateMove(current_pos, 0, -i);
				concatMoves(rook_moves, new_move);
			}
			else if (!isSameColor(playing_color, &next_pos1, curr_board) && !IsEmpty(next_pos1.x-97, next_pos1.y-1, curr_board)){
				new_move = CreateMove(current_pos, 0, -i);
				concatMoves(rook_moves, new_move);
				moved_down = 1;
			}
			else {
				moved_down = 1;
			}
		}
		//check if there is a legal non-capture move from (x,y) to (x-i,y)
		position next_pos2 = { current_pos->x - i, current_pos->y , NULL };
		if (!moved_Left && isValidPosition(next_pos2)){
			if (IsEmpty(next_pos2.x-97, next_pos2.y-1, curr_board)){
				new_move = CreateMove(current_pos, -i, 0);
				concatMoves(rook_moves, new_move);
			}
			else if (!isSameColor(playing_color, &next_pos2, curr_board) && !IsEmpty(next_pos2.x-97, next_pos2.y-1, curr_board)){
				new_move = CreateMove(current_pos, -i, 0);
				concatMoves(rook_moves, new_move);
				moved_Left = 1;
			}
			else {
				moved_Left = 1;
			}
		}
		//check if there is a legal non-capture move from (x,y) to (x+i,y)
		position next_pos3 = { current_pos->x + i, current_pos->y, NULL };
		if (!moved_Right && isValidPosition(next_pos3)){
			if (IsEmpty(next_pos3.x-97, next_pos3.y-1, curr_board)){
				new_move = CreateMove(current_pos, i, 0);
				concatMoves(rook_moves, new_move);
			}
			else if (!isSameColor(playing_color, &next_pos3, curr_board) && !IsEmpty(next_pos3.x-97, next_pos3.y-1, curr_board)){
				new_move = CreateMove(current_pos, i, 0);
				concatMoves(rook_moves, new_move);
				moved_Right = 1;
			}
			else {
				moved_Right = 1;
			}
		}

	}
	return rook_moves;
}

/*
* get all possible queen moves from the current position , queen moves simply combine rook and bishop moves from a current position.
*/
moves * getQueenMoves(char playing_color, char curr_board[BOARD_SIZE][BOARD_SIZE], position* current_pos){
	moves * queen_moves = getBishopMoves(playing_color, curr_board, current_pos);
	moves* rook_moves = getRookMoves(playing_color, curr_board, current_pos);
	move* rooks_move_head = rook_moves->head;
	concatMoves(queen_moves, rooks_move_head);
	free(rook_moves);
	return queen_moves;
}

/*
* get all possible knight moves from the current position
*/
moves * getKnightMoves(char playing_color, char curr_board[BOARD_SIZE][BOARD_SIZE], position* current_pos){
	moves * knight_moves = calloc(1, sizeof(moves));
	validate(knight_moves, "getKingMoves");

	position next_pos = { current_pos->x - 1, current_pos->y + 2, NULL };
	move* new_move;
	//check if there is a legal  move from (x,y) to (x-1,y+2)
	if (isValidPosition(next_pos) && (IsEmpty(next_pos.x-97, next_pos.y-1, curr_board) || 
		(!isSameColor(playing_color, &next_pos, curr_board) && !IsEmpty(next_pos.x-97, next_pos.y-1, curr_board)))){

		new_move = CreateMove(current_pos, -1, 2);
		concatMoves(knight_moves, new_move);
	}
	//check if there is a legal move from (x,y) to (x+1,y+2)
	position next_pos1 = { current_pos->x + 1, current_pos->y + 2, NULL };
	if (isValidPosition(next_pos1) && (IsEmpty(next_pos1.x-97, next_pos1.y-1, curr_board) || 
		(!isSameColor(playing_color, &next_pos1, curr_board) && !IsEmpty(next_pos1.x-97, next_pos1.y-1, curr_board)))){

		new_move = CreateMove(current_pos, 1, 2);
		concatMoves(knight_moves, new_move);
	}
	//check if there is a legal move from (x,y) to (x-1,y-2)
	position next_pos2 = { current_pos->x - 1, current_pos->y - 2, NULL };
	if (isValidPosition(next_pos2) && (IsEmpty(next_pos2.x-97, next_pos2.y-1, curr_board) || 
		(!isSameColor(playing_color, &next_pos2, curr_board) && !IsEmpty(next_pos2.x-97, next_pos2.y-1, curr_board)))){

		new_move = CreateMove(current_pos, -1, -2);
		concatMoves(knight_moves, new_move);
	}
	//check if there is a legal move from (x,y) to (x+1,y-2)
	position next_pos3 = { current_pos->x + 1, current_pos->y - 2, NULL };
	if (isValidPosition(next_pos3) && (IsEmpty(next_pos3.x-97, next_pos3.y-1, curr_board) || 
		(!isSameColor(playing_color, &next_pos3, curr_board) && !IsEmpty(next_pos3.x-97, next_pos3.y-1, curr_board)))){

		new_move = CreateMove(current_pos, 1, -2);
		concatMoves(knight_moves, new_move);
	}

	//check if there is a legal move from (x,y) to (x-2,y+1)
	position next_pos4 = { current_pos->x - 2, current_pos->y + 1, NULL };
	if (isValidPosition(next_pos4) && (IsEmpty(next_pos4.x-97, next_pos4.y-1, curr_board) || 
		(!isSameColor(playing_color, &next_pos4, curr_board) && !IsEmpty(next_pos4.x-97, next_pos4.y-1, curr_board)))){

		new_move = CreateMove(current_pos, -2, 1);
		concatMoves(knight_moves, new_move);
	}
	//check if there is a legal  move from (x,y) to (x-2,y-1)
	position next_pos5 = { current_pos->x - 2, current_pos->y - 1, NULL };
	if (isValidPosition(next_pos5) && (IsEmpty(next_pos5.x-97, next_pos5.y-1, curr_board) || 
		(!isSameColor(playing_color, &next_pos5, curr_board) && !IsEmpty(next_pos5.x-97, next_pos5.y-1, curr_board)))){

		new_move = CreateMove(current_pos, -2, -1);
		concatMoves(knight_moves, new_move);
	}
	//check if there is a legal move from (x,y) to (x+2,y+1)
	position next_pos6 = { current_pos->x + 2, current_pos->y + 1, NULL };
	if (isValidPosition(next_pos6) && (IsEmpty(next_pos6.x-97, next_pos6.y-1, curr_board) || 
		(!isSameColor(playing_color, &next_pos6, curr_board) && !IsEmpty(next_pos6.x-97, next_pos6.y-1, curr_board)))){

		new_move = CreateMove(current_pos, 2, 1);
		concatMoves(knight_moves, new_move);
	}
	//check if there is a legal  move from (x,y) to (x+2,y-1)
	position next_pos7 = { current_pos->x + 2, current_pos->y - 1, NULL };
	if (isValidPosition(next_pos7) && (IsEmpty(next_pos7.x-97, next_pos7.y-1, curr_board) || 
		(!isSameColor(playing_color, &next_pos7, curr_board) && !IsEmpty(next_pos7.x-97, next_pos7.y-1, curr_board)))){

		new_move = CreateMove(current_pos, 2, -1);
		concatMoves(knight_moves, new_move);
	}
	return knight_moves;

}

/*
* get all possible king moves from the current position
*/
moves * getKingMoves(char playing_color, char curr_board[BOARD_SIZE][BOARD_SIZE], position* current_pos){
	moves * king_moves = calloc(1, sizeof(moves));
	validate(king_moves, "getKingMoves");

	position next_pos = { current_pos->x, current_pos->y + 1, NULL };
	move* new_move;
	//check if there is a legal  move from (x,y) to (x,y+1)
	if (isValidPosition(next_pos) && (IsEmpty(next_pos.x-97, next_pos.y-1, curr_board) || 
		(!isSameColor(playing_color, &next_pos, curr_board) && !IsEmpty(next_pos.x-97, next_pos.y-1, curr_board)))){

		new_move = CreateMove(current_pos, 0, 1);
		concatMoves(king_moves, new_move);
	}
	//check if there is a legal move from (x,y) to (x,y-1)
	position next_pos1 = { current_pos->x, current_pos->y - 1, NULL };
	if (isValidPosition(next_pos1) && (IsEmpty(next_pos1.x-97, next_pos1.y-1, curr_board) || 
		(!isSameColor(playing_color, &next_pos1, curr_board) && !IsEmpty(next_pos1.x-97, next_pos1.y-1, curr_board)))){

		new_move = CreateMove(current_pos, 0, -1);
		concatMoves(king_moves, new_move);
	}
	//check if there is a legal move from (x,y) to (x-1,y)
	position next_pos2 = { current_pos->x - 1, current_pos->y, NULL };
	if (isValidPosition(next_pos2) && (IsEmpty(next_pos2.x-97, next_pos2.y-1, curr_board) || 
		(!isSameColor(playing_color, &next_pos2, curr_board) && !IsEmpty(next_pos2.x-97, next_pos2.y-1, curr_board)))){

		new_move = CreateMove(current_pos, -1, 0);
		concatMoves(king_moves, new_move);
	}
	//check if there is a legal move from (x,y) to (x+1,y)
	position next_pos3 = { current_pos->x + 1, current_pos->y , NULL };
	if (isValidPosition(next_pos3) && (IsEmpty(next_pos3.x-97, next_pos3.y-1, curr_board) || 
		(!isSameColor(playing_color, &next_pos3, curr_board) && !IsEmpty(next_pos3.x-97, next_pos3.y-1, curr_board)))){

		new_move = CreateMove(current_pos, 1, 0);
		concatMoves(king_moves, new_move);
	}

	//check if there is a legal move from (x,y) to (x+1,y+1)
	position next_pos4 = { current_pos->x + 1, current_pos->y+1, NULL };
	if (isValidPosition(next_pos4) && (IsEmpty(next_pos4.x-97, next_pos4.y-1, curr_board) || 
		(!isSameColor(playing_color, &next_pos4, curr_board) && !IsEmpty(next_pos4.x-97, next_pos4.y-1, curr_board)))){

		new_move = CreateMove(current_pos, 1, 1);
		concatMoves(king_moves, new_move);
	}
	//check if there is a legal  move from (x,y) to (x+1,y-1)
	position next_pos5 = { current_pos->x + 1, current_pos->y-1, NULL };
	if (isValidPosition(next_pos5) && (IsEmpty(next_pos5.x-97, next_pos5.y-1, curr_board) || 
		(!isSameColor(playing_color, &next_pos5, curr_board) && !IsEmpty(next_pos5.x-97, next_pos5.y-1, curr_board)))){

		new_move = CreateMove(current_pos, 1, -1);
		concatMoves(king_moves, new_move);
	}
	//check if there is a legal move from (x,y) to (x-1,y+1)
	position next_pos6 = { current_pos->x - 1, current_pos->y+1, NULL };
	if (isValidPosition(next_pos6) && (IsEmpty(next_pos6.x-97, next_pos6.y-1, curr_board) || 
		(!isSameColor(playing_color, &next_pos6, curr_board) && !IsEmpty(next_pos6.x-97, next_pos6.y-1, curr_board)))){

		new_move = CreateMove(current_pos, -1, 1);
		concatMoves(king_moves, new_move);
	}
	//check if there is a legal  move from (x,y) to (x-1,y-1)
	position next_pos7 = { current_pos->x - 1, current_pos->y-1, NULL };
	if (isValidPosition(next_pos7) && (IsEmpty(next_pos7.x-97, next_pos7.y-1, curr_board) || 
		(!isSameColor(playing_color, &next_pos7, curr_board) && !IsEmpty(next_pos7.x-97, next_pos7.y-1, curr_board)))){

		new_move = CreateMove(current_pos, -1, -1);
		concatMoves(king_moves, new_move);
	}
	return king_moves;
}

/*
* get all possible moves from a given positiion at the board
*/
moves* getMovesFromPosition(char playing_color, char curr_board[BOARD_SIZE][BOARD_SIZE], position* current_pos){
	char square = curr_board[current_pos->y - 1][current_pos->x - 97];
	moves* poss_moves = NULL;
	if (square != EMPTY){
		if (playing_color == 'W'){
			if (square == WHITE_R){
				poss_moves = getRookMoves(playing_color, curr_board, current_pos);
			}
			else if (square == WHITE_N){
				poss_moves = getKnightMoves(playing_color, curr_board, current_pos);
			}
			else if (square == WHITE_B){
				poss_moves = getBishopMoves(playing_color, curr_board, current_pos);
			}
			else if (square == WHITE_Q){
				poss_moves = getQueenMoves(playing_color, curr_board, current_pos);
			}
			else if (square == WHITE_K){
				poss_moves = getKingMoves(playing_color, curr_board, current_pos);
			}
			else {
				poss_moves = getPawnMoves(playing_color, curr_board, current_pos);
			}
		}
		else {
			if (square == BLACK_R){
				poss_moves = getRookMoves(playing_color, curr_board, current_pos);
			}
			else if (square == BLACK_N){
				poss_moves = getKnightMoves(playing_color, curr_board, current_pos);
			}
			else if (square == BLACK_B){
				poss_moves = getBishopMoves(playing_color, curr_board, current_pos);

			}
			else if (square == BLACK_Q){
				poss_moves = getQueenMoves(playing_color, curr_board, current_pos);

			}
			else if (square == BLACK_K){
				poss_moves = getKingMoves(playing_color, curr_board, current_pos);

			}
			else {
				poss_moves = getPawnMoves(playing_color, curr_board, current_pos);
			}
		}
	}
	return poss_moves;
}

/*
* Getting all possible moves for a current player
*/
moves* getAllMoves(char playing_color, char curr_board[BOARD_SIZE][BOARD_SIZE]){
	moves* all_moves = NULL;
	position* curr_pos = NULL;
	moves* pos_moves = NULL;
	move* temp_head = NULL;
	all_moves = calloc(1, sizeof(moves));
	validate(all_moves, "getAllMoves");

	for (int i = 0; i < BOARD_SIZE; i++){
		for (int j = 0; j < BOARD_SIZE; j++){
			curr_pos = calloc(1, sizeof(position));
			validate(curr_pos, "getAllMoves");
			initPosition(curr_pos, j + 97, i + 1);
			if (isSameColor(playing_color, curr_pos, curr_board)){
				pos_moves = getMovesFromPosition(playing_color, curr_board, curr_pos);
				if (pos_moves->head != NULL){
					temp_head = pos_moves->head;
					concatMoves(all_moves, temp_head);
				}
				free(pos_moves);
			}
			freePositions(curr_pos);
		}
	}
	return all_moves;
}

/*
* Getting all possible legal moves for a current player
*/
moves * getMoves(char playing_color, char curr_board[BOARD_SIZE][BOARD_SIZE], position* w_king_pos,position* b_king_pos) {
	moves * all_moves = getAllMoves(playing_color, curr_board);
	removeBadMoves(all_moves, playing_color, curr_board,  w_king_pos,b_king_pos);
	return all_moves;
}



/*
* check if there is a legal move
*/
int LegalMoveExists(char playing_color, char curr_board[BOARD_SIZE][BOARD_SIZE], position* w_king_pos, position* b_king_pos){
	position* curr_pos = NULL;
	moves* pos_moves = NULL;
	move* temp_head = NULL;
	char board_cpy[BOARD_SIZE][BOARD_SIZE];
	for (int i = 0; i < BOARD_SIZE; i++){
		for (int j = 0; j < BOARD_SIZE; j++){
			curr_pos = calloc(1, sizeof(position));
			validate(curr_pos, "LegalMoveExists");
			initPosition(curr_pos, j + 97, i + 1);
			if (isSameColor(playing_color, curr_pos, curr_board)){
				pos_moves = getMovesFromPosition(playing_color, curr_board, curr_pos);
				if (pos_moves->head != NULL){
					temp_head = pos_moves->head;
					while (temp_head != NULL){
						boardCopy(curr_board, board_cpy);
						position w_k_pos_cpy = { w_king_pos->x, w_king_pos->y, NULL };
						position b_k_pos_cpy = { b_king_pos->x, b_king_pos->y, NULL };
						actualBoardUpdate(temp_head, board_cpy, playing_color, &w_k_pos_cpy, &b_k_pos_cpy);
						//if this is a legal move then return 1.
						if (!isCheck(OppositeColor(playing_color), board_cpy, &w_k_pos_cpy, &b_k_pos_cpy)){
							freeMoves(pos_moves->head);
							free(pos_moves);
							freePositions(curr_pos);
							return 1;
						}
						temp_head = temp_head->next;
					}
				}
				freeMoves(pos_moves->head);
				free(pos_moves);
			}
			freePositions(curr_pos);
		}
	}
	return 0;
}

/*
* Checking if the game has ended in a Tie
*/
int isTie(char playing_color, char curr_board[BOARD_SIZE][BOARD_SIZE], position* w_king_pos, position* b_king_pos){

	if (isCheck(playing_color, curr_board, w_king_pos, b_king_pos)) {
		return 0;
	}
	// in case playing_color's opponent don't have moves after the playing_color's move , there is a tie.
	int retval = LegalMoveExists(OppositeColor(playing_color), curr_board, w_king_pos, b_king_pos);
	return  !retval;
	
}

/*
* Checking if the given move is legal
*/
int isLegalMove(move* move1, char playing_color){
	moves* all_moves = getMoves(playing_color, board, white_kingpos, black_kingpos);
	move* move2 = all_moves->head;
	while (move2 != NULL){
		if (isEqual(move2, move1)){
			freeMoves(all_moves->head);
			free(all_moves);
			return 1;
		}
		move2 = move2->next;
	}
	freeMoves(all_moves->head);
	free(all_moves);
	return 0;
}


/*
* Creating a copy of a given move
*/
move* copyMove(move* curr_move){
	move* cpy_move = calloc(1,sizeof(move));
	validate(cpy_move, "copyMove");
	position* curr_pos = calloc(1, sizeof(position));
	validate(curr_pos, "copyMove");
	initPosition(curr_pos, curr_move->current_pos->x, curr_move->current_pos->y);
	position* next_pos = calloc(1, sizeof(position));
	validate(next_pos, "copyMove");
	initPosition(next_pos, curr_move->current_pos->next->x, curr_move->current_pos->next->y);
	curr_pos->next = next_pos;
	cpy_move->current_pos = curr_pos;
	if (curr_move->promotion != NULL){
		cpy_move->promotion = calloc(strlen(curr_move->promotion) + 1, sizeof(char));
		validate(cpy_move->promotion, "copyMove");
		strcpy(cpy_move->promotion, curr_move->promotion);
		cpy_move->promotion[strlen(curr_move->promotion)] = '\0';
	}
	
	return cpy_move;
}


/*
* Computing a score for each move according to the pieces on the board
*/
int scoringFunc(char curr_board[BOARD_SIZE][BOARD_SIZE], char playing_color, position* w_king_pos, position* b_king_pos){
	int total_WS = 0;
	int total_BS = 0;
	for (int i = 0; i<BOARD_SIZE; i++) {
		for (int j = 0; j<BOARD_SIZE; j++) {
			if (curr_board[i][j] == WHITE_P){
				total_WS += 1;
			}
			else if (curr_board[i][j] == WHITE_N || curr_board[i][j] == WHITE_B){
				total_WS += 3;
				continue;
			}
			else if (curr_board[i][j] == WHITE_R){
				total_WS += 5;
				continue;
			}
			else if (curr_board[i][j] == WHITE_Q){
				total_WS += 9;
				continue;
			}
			else if (curr_board[i][j] == WHITE_K){
				total_WS += 400;
				continue;
			}
			else if (curr_board[i][j] == BLACK_P){
				total_BS += 1;
				continue;
			}
			else if (curr_board[i][j] == BLACK_N || curr_board[i][j] == BLACK_B){
				total_BS += 3;
				continue;
			}
			else if (curr_board[i][j] == BLACK_R){
				total_BS += 5;
				continue;
			}
			else if (curr_board[i][j] == BLACK_Q){
				total_BS += 9;
				continue;
			}
			else if (curr_board[i][j] == BLACK_K){
				total_BS += 400;
			}
		}
	}
	
	if (playing_color == 'W'){
		if (isMate('W', curr_board, w_king_pos, b_king_pos)){
			return 1000;
		}
		else if (isMate('B', curr_board, w_king_pos, b_king_pos)){
			return -1000;
		}
		else if (isTie('B',curr_board ,w_king_pos, b_king_pos)){
			return -500;
		}
		else{
			return (total_WS - total_BS);
		}
	}
	else{
		if (isMate('W', curr_board, w_king_pos, b_king_pos)){
			return -1000;
		}
		else if (isMate('B', curr_board, w_king_pos, b_king_pos)){
			return 1000;
		}
		else if (isTie('W',curr_board, w_king_pos, b_king_pos)){
			return -500;
		}
		else{
			return (total_BS - total_WS);
		}
	}
}