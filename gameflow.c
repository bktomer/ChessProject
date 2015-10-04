#include "gameflow.h"

/*
* Save board row to a string
*/
char* boardRowToString(int row_num){
	char str[8];
	char* new_str = calloc(9, sizeof(char));
	validate(new_str, "boardRowToString");
	for (int i = 0; i < BOARD_SIZE; i++){
		if (board[row_num][i] == EMPTY){
			str[i] = '_';
		}
		else{
			str[i] = board[row_num][i];
		}

	}
	strncpy(new_str, str, 8);
	new_str[8] = '\0';
	return new_str;
}

/*
* Update board from a given string representing a certain row
*/
void updateBoardFromString(char* curr_row, int row_num){
	for (int i = 0; i < BOARD_SIZE; i++){
		if (curr_row[i] == WHITE_B){
			board[row_num][i] = WHITE_B;
		}
		else if (curr_row[i] == WHITE_K){
			board[row_num][i] = WHITE_K;
		}
		else if (curr_row[i] == WHITE_N){
			board[row_num][i] = WHITE_N;
		}
		else if (curr_row[i] == WHITE_P){
			board[row_num][i] = WHITE_P;
		}
		else if (curr_row[i] == WHITE_Q){
			board[row_num][i] = WHITE_Q;
		}
		else if (curr_row[i] == WHITE_R){
			board[row_num][i] = WHITE_R;
		}

		else if (curr_row[i] == BLACK_B){
			board[row_num][i] = BLACK_B;
		}
		else if (curr_row[i] == BLACK_K){
			board[row_num][i] = BLACK_K;
		}
		else if (curr_row[i] == BLACK_N){
			board[row_num][i] = BLACK_N;
		}
		else if (curr_row[i] == BLACK_P){
			board[row_num][i] = BLACK_P;
		}
		else if (curr_row[i] == BLACK_Q){
			board[row_num][i] = BLACK_Q;
		}
		else if (curr_row[i] == BLACK_R){
			board[row_num][i] = BLACK_R;
		}
		else{
			board[row_num][i] = EMPTY;
		}

	}
}

/*
* Loading game settings from a given file
*/
int loadSettingsFromFile(char* fp, int print_bit){
	xmlDocPtr doc;
	xmlNodePtr cur;
	xmlChar* key;
	doc = xmlReadFile(fp, NULL, 0);
	if (doc == NULL) {
		print_message(WRONG_FILE_NAME);
		return 0;
	}
	cur = xmlDocGetRootElement(doc);
	cur = cur->xmlChildrenNode;
	while (cur != NULL) {
		// Exctracting the <next_turn> element from the XML file
		if ((!xmlStrcmp(cur->name, (const xmlChar *)"next_turn"))){
			key = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
			if (key != NULL){
				if (!strcmp((char*)key, "White")){
					next_player = 'W';
				}
				else{
					next_player = 'B';
				}
			}
			xmlFree(key);
		}
		// Exctracting the <game_mode> element from the XML file
		if ((!xmlStrcmp(cur->name, (const xmlChar *)"game_mode"))){
			key = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
			if (key != NULL){
				game_mode = key[0] - '0';
			}
			xmlFree(key);
		}
		// Exctracting the <difficulty> element from the XML file
		if ((!xmlStrcmp(cur->name, (const xmlChar *)"difficulty"))){
			key = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
			if (key != NULL){
				if (!strcmp((char*)key, "best")){
					minimax_depth = 0;
				}
				else{
					minimax_depth = key[0] - '0';
				}
			}
			xmlFree(key);
		}
		// Exctracting the <user_color> element from the XML file
		if ((!xmlStrcmp(cur->name, (const xmlChar *)"user_color"))){
			key = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
			if (key != NULL){
				if (!strcmp((char*)key, "White")){
					user_color = 'W';
				}
				else{
					user_color = 'B';
				}
			}
			xmlFree(key);
		}
		// Exctracting the <board> element from the XML file
		if ((!xmlStrcmp(cur->name, (const xmlChar *)"board"))){
			cur = cur->xmlChildrenNode;
			while (cur != NULL) {
				//Extracting board children - rows
				if ((!xmlStrcmp(cur->name, (const xmlChar *)"row_8"))) {
					key = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
					updateBoardFromString((char*)key, 7);
					xmlFree(key);
				}
				else if ((!xmlStrcmp(cur->name, (const xmlChar *)"row_7"))) {
					key = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
					updateBoardFromString((char*)key, 6);
					xmlFree(key);
				}
				else if ((!xmlStrcmp(cur->name, (const xmlChar *)"row_6"))) {
					key = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
					updateBoardFromString((char*)key, 5);
					xmlFree(key);
				}
				else if ((!xmlStrcmp(cur->name, (const xmlChar *)"row_5"))) {
					key = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
					updateBoardFromString((char*)key, 4);
					xmlFree(key);
				}
				else if ((!xmlStrcmp(cur->name, (const xmlChar *)"row_4"))) {
					key = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
					updateBoardFromString((char*)key, 3);
					xmlFree(key);
				}
				else if ((!xmlStrcmp(cur->name, (const xmlChar *)"row_3"))) {
					key = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
					updateBoardFromString((char*)key, 2);
					xmlFree(key);
				}
				else if ((!xmlStrcmp(cur->name, (const xmlChar *)"row_2"))) {
					key = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
					updateBoardFromString((char*)key, 1);
					xmlFree(key);
				}
				else if ((!xmlStrcmp(cur->name, (const xmlChar *)"row_1"))) {
					key = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
					updateBoardFromString((char*)key, 0);
					xmlFree(key);
				}
				cur = cur->next;
			}
		}
		if (cur != NULL){
			cur = cur->next;
		}
	}
	if (print_bit){
		print_board();
	}
	xmlFreeDoc(doc);
	xmlCleanupParser();
	return 1;
}

/* 
* Saving game settings and board to an XML file in a proper format
*/
void saveGameStateToFile(char* fp){
	xmlDocPtr doc = NULL;    /* document pointer */
	xmlNodePtr game_node = NULL, board_node = NULL; /* node pointers */

	char* np_color;
	char* up_color;
	char diff_str[2];
	char gm_str[2];

	if (next_player == 'W'){
		np_color = "White";
	}
	else{
		np_color = "Black";
	}
	if (user_color == 'W'){
		up_color = "White";
	}
	else{
		up_color = "Black";
	}

	sprintf(gm_str, "%d", game_mode);

	doc = xmlNewDoc(BAD_CAST "1.0");
	game_node = xmlNewNode(NULL, BAD_CAST "game");
	xmlDocSetRootElement(doc, game_node);

	xmlNewChild(game_node, NULL, BAD_CAST "next_turn", BAD_CAST np_color);
	xmlNewChild(game_node, NULL, BAD_CAST "game_mode", BAD_CAST gm_str);

	if (game_mode == 1){
		xmlNewChild(game_node, NULL, BAD_CAST "difficulty", BAD_CAST "");
		xmlNewChild(game_node, NULL, BAD_CAST "user_color", BAD_CAST "");
	}
	else{
		// if minimax_depth equals best depth 
		if (!minimax_depth){
			xmlNewChild(game_node, NULL, BAD_CAST "difficulty", BAD_CAST "best");
		}
		else{
			sprintf(diff_str, "%d", minimax_depth);
			xmlNewChild(game_node, NULL, BAD_CAST "difficulty", BAD_CAST diff_str);
		}
		xmlNewChild(game_node, NULL, BAD_CAST "user_color", BAD_CAST up_color);
	}

	board_node = xmlNewNode(NULL, BAD_CAST "board");
	xmlAddChild(game_node, board_node);

	for (int i = 0; i < BOARD_SIZE; i++){
		char buf[6];
		sprintf(buf, "row_%d", BOARD_SIZE - i);
		char* temp_row = boardRowToString(7 - i);
		xmlNewChild(board_node, NULL, BAD_CAST buf, BAD_CAST temp_row);
		free(temp_row);
	}

	xmlSaveFormatFileEnc(fp, doc, "UTF-8", 1);
	xmlFreeDoc(doc);
	xmlCleanupParser();
}

/*
* Updating board after a legal move
*/
int updateBoard(move* current_move, char playing_color){
	if (!isValidAndLegalPiece(current_move->current_pos, playing_color,1)){
		return 0;
	}
	if (isLegalMove(current_move, playing_color)){
		actualBoardUpdate(current_move, board, playing_color,white_kingpos,black_kingpos);
	}
	else {
		print_message(ILLEGAL_MOVE);
		return 0;
	}
	return 1;
}




/*
* Maintaining a gaming mode
*/
void gamingMode() {
	int player1 = 0;
	int player2 = 0;
	char* u_color;
	if (game_mode == 1){
		if (next_player == 'W'){
			player1 = 1;
		}
		else{
			player2 = 1;
		}
	}
	else{
		if (next_player == user_color){
			player1 = player2 = 1;
		}
		else{
			player1 = player2 = 0;
		}
	}
	// Getting the colors for a player vs. AI mode
	if (user_color == 'W') {
		u_color = "White";
	}
	else {
		u_color = "Black";
	}
	char** input;
	char playing_color = playingColor(player1, player2);
	int w_k_found = 0; int b_k_found = 0;
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			if (w_k_found && b_k_found) {
				break;
			}
			if (board[i][j] == WHITE_K) {
				white_kingpos = calloc(1, sizeof(position));
				validate(white_kingpos, "gamingMode");
				initPosition(white_kingpos, j + 97, i + 1);
				w_k_found = 1;
			}
			else if (board[i][j] == BLACK_K){
				black_kingpos = calloc(1, sizeof(position));
				validate(black_kingpos, "gamingMode");
				initPosition(black_kingpos, j + 97, i + 1);
				b_k_found = 1;
			}
		}
	}
	int game_over = gameOver(1, OppositeColor(playing_color));
	
	while (!game_over) {
		
		if (player1 || player2) {
			if (player1 && player2){
				printf("%s player - enter your move:\n", u_color);
			}
			else{
				if (player1){
					print_message("White player - enter your move:\n");
				}
				else{
					print_message("Black player - enter your move:\n");
				}
			}
			playing_color = playingColor(player1, player2);
			input = getInput();
			if (!strcmp(input[0], "quit")){
				FreeInput(input);
				free(input);
				free(white_kingpos);
				free(black_kingpos);
				exit(0);
			}
			else if (!strcmp(input[0], "move")) { //extracting player's move from input
				position* current_pos = createPos(input[1]);
				move* current_move = createMoveFromInput(current_pos, input[3], input[4]);
				int board_updated = updateBoard(current_move, playing_color);
				freeMoves(current_move);
				if (board_updated) {
					print_board();
					if (player1 && player2){
						player1 = player2 = 0;
					}
					else{
						player1 = !player1;
						player2 = !player2;
					}
				}
			}
			else if (!strcmp(input[0], "get_moves")){
				position* current_pos = createPos(input[1]);
				if (!isValidAndLegalPiece(current_pos, playing_color,1)){
					freePositions(current_pos);
					continue;
				}
				moves* possible_moves = getMovesFromPosition(playing_color, board, current_pos);
				removeBadMoves(possible_moves, playing_color, board, white_kingpos, black_kingpos);
				printMoves(possible_moves->head,0);
				freeMoves(possible_moves->head);
				free(possible_moves);
				freePositions(current_pos);
			}
			else if (!strcmp(input[0], "get_best_moves")){
				int d = (int)strtol(input[1], (char**)NULL, 10); // if d == 0 then the value of d should be "best"
				int last_minimax_depth = minimax_depth;
				minimax_depth = d;
				moves* best_moves = getBestMoves(playing_color);
				printMoves(best_moves->head,0);
				minimax_depth = last_minimax_depth;
				freeMoves(best_moves->head);
				free(best_moves);
			}
			else if (!strcmp(input[0], "get_score")){
				int d = (int)strtol(input[1], (char**)NULL, 10); // if d == 0 then the value of d should be "best"
				int last_minimax_depth = minimax_depth;
				minimax_depth = d;
				position* current_pos = createPos(input[3]);
				move* m = createMoveFromInput(current_pos, input[5], input[6]);
				if (!isLegalMove(m, playing_color)){
					print_message(ILLEGAL_MOVE);
					freeMoves(m);				
					minimax_depth = last_minimax_depth;
					continue;
				}
				int move_score = getMoveScore(playing_color, m);
				minimax_depth = last_minimax_depth;
				printf("%d\n", move_score);
				freeMoves(m);
			}
			else if (!strcmp(input[0], "save")){
				char* fp = input[1];
				saveGameStateToFile(fp);
			}
			else {
				print_message(ILLEGAL_COMMAND);

			}
			FreeInput(input);
			free(input);
		}
		else{ //pc turn
			playing_color = playingColor(player1, player2);
			moves* best_moves = getBestMoves(playing_color);
			move* computer_move = best_moves->head;
			print_message("\nComputer: move ");
			printMoves(computer_move,1);
			actualBoardUpdate(computer_move, board, playing_color, white_kingpos, black_kingpos);
			print_board();
			freeMoves(best_moves->head);
			free(best_moves);
			player1 = player2 = 1;
		}
		// Checking if there was a check after a move
		game_over = gameOver(1, playing_color);
		if (!game_over){
			if (isCheck(playing_color, board, white_kingpos, black_kingpos)){
				print_message(CHECK);
			}
		}
	}

	free(white_kingpos);
	free(black_kingpos); 
}


/*
* Getting best possible moves with the minimax depth
*/
moves* getBestMoves(char playing_color){

	best_moves = calloc(1, sizeof(moves));
	validate(best_moves, "getBestMoves");
	moves * all_moves = getMoves(playing_color, board, white_kingpos, black_kingpos);
	move* head = all_moves->head;
	int max_score = INT_MIN;
	int score;
	while (head != NULL){
		score = getMoveScore(playing_color, head);
		//found a better move than the current best moves
		if (score > max_score){
			max_score = score;
			freeMoves(best_moves->head);
			free(best_moves);
			best_moves = calloc(1, sizeof(moves));
			validate(best_moves, "getBestMoves");
			concatMoves(best_moves, copyMove(head));
		}
		//found a move with an equal score of the best move - adds it to the best moves list
		else if (score == max_score){
			concatMoves(best_moves, copyMove(head));
		}
		head = head->next;
	}
	freeMoves(all_moves->head);
	free(all_moves);
	return best_moves;
	
}

/*
* Getting a given move's score.
*/
int getMoveScore(char playing_color, move* curr_move){
	int score;
	char board_cpy[BOARD_SIZE][BOARD_SIZE];
	position black_king_pos_cpy;
	position white_king_pos_cpy;
	initPosition(&black_king_pos_cpy, black_kingpos->x, black_kingpos->y);
	initPosition(&white_king_pos_cpy, white_kingpos->x, white_kingpos->y);
	boardCopy(board, board_cpy);
	actualBoardUpdate(curr_move, board_cpy, playing_color,&white_king_pos_cpy,&black_king_pos_cpy);
	if (minimax_depth == 1) {
		return scoringFunc(board_cpy, playing_color, white_kingpos, black_kingpos);
	}
	if (minimax_depth){
		score = alphabeta(OppositeColor(playing_color), board_cpy, minimax_depth - 1, INT_MIN, INT_MAX, 0, &white_king_pos_cpy, &black_king_pos_cpy);
	}
	else{
		minimax_depth = bestDepth(board_cpy, playing_color);
		score = alphabeta(OppositeColor(playing_color), board_cpy, minimax_depth - 1, INT_MIN, INT_MAX, 0, &white_king_pos_cpy, &black_king_pos_cpy);
		printf("best depth is : %d\n", minimax_depth);
		minimax_depth = 0;
	}
	return score;
}

/*
* Maintaining settings mode
*/
void SettingsMode() {
	init_board();
	print_board();
	print_message(ENTER_SETTINGS);
	char** input = getInput();
	while (strcmp(input[0], "quit")){

		if (!strcmp(input[0], "game_mode")){
			int last_game_mode = game_mode;
			game_mode = (int)strtol(input[1], (char **)NULL, 10);
			if (game_mode == 1){
				print_message(TWO_PLAYERS_GAME_MODE);
			}
			else if (game_mode == 2){
				print_message(PLAYER_VS_AI_GAME_MODE);
			}
			else{
				game_mode = last_game_mode;
				print_message(WRONG_GAME_MODE);
			}
		}

		else if (!strcmp(input[0], "difficulty")){
			if (game_mode == 2){
				if (!strcmp(input[1], "depth")){
					minimax_depth = (int)strtol(input[2], (char **)NULL, 10);
					if (minimax_depth > 4 || minimax_depth < 1) {
						minimax_depth = 1;
						print_message(WRONG_MINIMAX_DEPTH);
					}
				}
				else{
					// Denoting difficulty best as minimax depth 0
					minimax_depth = 0;
				}

			}
			else{
				minimax_depth = 1;
				print_message(ILLEGAL_COMMAND);
			}
		}

		else if (!strcmp("user_color", input[0])){
			if (game_mode == 2){
				if (!strcmp(input[1], "black")){
					user_color = 'B';
				}
				else {
					user_color = 'W';
				}
			}
			else{
				print_message(ILLEGAL_COMMAND);
			}
		}

		else if (!strcmp(input[0], "load")){
			char* fp = input[1];
			loadSettingsFromFile(fp,1);

		}

		else if (!strcmp(input[0], "clear")){
			clear_board();
		}

		else if (!strcmp(input[0], "next_player")){
			if (!strcmp(input[1], "black")){
				next_player = 'B';
			}
			else {
				next_player = 'W';
			}
		}

		else if (!strcmp(input[0], "rm")) {
			char x = input[1][1];
			char* digit_pos = input[1] + 3;
			int y = (int)strtol(digit_pos, (char**)NULL, 10);
			if ((x > 'h' || x<'a') || (y < 1 || y>8)) {
				print_message(WRONG_POSITION);
			}
			else {
				board[y - 1][x - 97] = EMPTY;
			}
		}

		else if (!strcmp(input[0], "set")) {
			char x = input[1][1];
			char* digit_pos = input[1] + 3;
			int y = (int)strtol(digit_pos, (char**)NULL, 10);
			if ((x>'h' || x < 'a') || (y < 1 || y>8)) {
				print_message(WRONG_POSITION);
			}
			else {
				char a = input[2][0];
				char b1 = input[3][0];
				char b2 = input[3][1];
				char orig_piece = board[y - 1][x - 97];
				if (a == 'w') {
					if (b1 == 'k') {
						if (b2 == 'n'){
							board[y - 1][x - 97] = WHITE_N;
						}
						else{
							board[y - 1][x - 97] = WHITE_K;
						}
					}
					else if (b1 == 'q') {
						board[y - 1][x - 97] = WHITE_Q;
					}
					else if (b1 == 'r') {
						board[y - 1][x - 97] = WHITE_R;
					}
					else if (b1 == 'b') {
						board[y - 1][x - 97] = WHITE_B;
					}

					else {
						board[y - 1][x - 97] = WHITE_P;
					}
				}
				else {
					if (b1 == 'k') {
						if (b2 == 'n'){
							board[y - 1][x - 97] = BLACK_N;
						}
						else{
							board[y - 1][x - 97] = BLACK_K;
						}
					}
					else if (b1 == 'q') {
						board[y - 1][x - 97] = BLACK_Q;
					}
					else if (b1 == 'r') {
						board[y - 1][x - 97] = BLACK_R;
					}
					else if (b1 == 'b') {
						board[y - 1][x - 97] = BLACK_B;
					}

					else {
						board[y - 1][x - 97] = BLACK_P;
					}
				}
				int* piecesW; int* piecesB;
				piecesW = piecesCounter('W');
				piecesB = piecesCounter('B');
				if ((((piecesW[0] > 2 || piecesB[0] > 2) || (piecesW[1] > 2 || piecesB[1] > 2)) || ((piecesW[2] > 2 || piecesB[2] > 2) || (piecesW[3] > 1 || piecesB[3] > 1)))
					|| ((piecesW[4] > 1 || piecesB[4] > 1) || (piecesW[5] > 8 || piecesB[5] > 8))){
					board[y - 1][x - 97] = orig_piece;
					print_message(NO_PIECE);
				}
				free(piecesW);
				free(piecesB);
			}
		}
		else if (!strcmp(input[0], "print")) {
			print_board(board);
		}
		else if (!strcmp(input[0], "start")){
			FreeInput(input);
			free(input);
			//wrong board initialization
			if (WrongInitialization()) {
				input = getInput();
				continue;
			}
			gamingMode();
			return;
		}
		else {
			print_message(ILLEGAL_COMMAND);
		}
		FreeInput(input);
		free(input);
		print_message(ENTER_SETTINGS);
		input = getInput();
	}
	FreeInput(input);
	free(input);
	exit(0);

}
