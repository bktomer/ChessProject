#include "gui.h"

SDL_Surface* chess_logo = NULL;
SDL_Surface* background = NULL;
SDL_Surface* screen = NULL;
SDL_Surface* next_player_logo = NULL;
SDL_Surface* game_mode_logo = NULL;
SDL_Surface* set_the_board_button = NULL;
SDL_Surface* pvp_button = NULL;
SDL_Surface* pvc_button = NULL;
SDL_Surface* white_button = NULL;
SDL_Surface* black_button = NULL;
SDL_Surface* white_s_button = NULL;
SDL_Surface* black_s_button = NULL;
SDL_Surface* cancel_button = NULL;
SDL_Surface* new_game_button = NULL;
SDL_Surface* load_game_button = NULL;
SDL_Surface* quit_game_button = NULL;
SDL_Surface* pvc_s_button = NULL;
SDL_Surface* pvp_s_button = NULL;
SDL_Surface* dol_logo = NULL;

SDL_Surface* player_col_logo = NULL;
SDL_Surface* difficulty_logo = NULL;
SDL_Surface* best_depth_button = NULL;
SDL_Surface* best_depth_s_button = NULL;
SDL_Surface* depth_1_button = NULL;
SDL_Surface* depth_1_s_button = NULL;
SDL_Surface* depth_2_button = NULL;
SDL_Surface* depth_2_s_button = NULL;
SDL_Surface* depth_3_button = NULL;
SDL_Surface* depth_3_s_button = NULL;
SDL_Surface* depth_4_button = NULL;
SDL_Surface* depth_4_s_button = NULL;
SDL_Surface* start_the_game_button = NULL;
SDL_Surface* cmd_logo = NULL;
SDL_Surface* thinking_label = NULL;

SDL_Surface* chessboard = NULL;
SDL_Surface* mainmenu_button = NULL;
SDL_Surface* savegame_button = NULL;
SDL_Surface* bestmove_button = NULL;
SDL_Surface* last_move_button = NULL;
SDL_Surface* WK = NULL;
SDL_Surface* WQ = NULL;
SDL_Surface* WR = NULL;
SDL_Surface* WB = NULL;
SDL_Surface* WN = NULL;
SDL_Surface* WP = NULL;
SDL_Surface* BK = NULL;
SDL_Surface* BQ = NULL;
SDL_Surface* BR = NULL;
SDL_Surface* BB = NULL;
SDL_Surface* BN = NULL;
SDL_Surface* BP = NULL;
SDL_Surface* WS = NULL;
SDL_Surface* BS = NULL;
SDL_Surface* WK_S = NULL;
SDL_Surface* WQ_S = NULL;
SDL_Surface* WR_S = NULL;
SDL_Surface* WB_S = NULL;
SDL_Surface* WN_S = NULL;
SDL_Surface* WP_S = NULL;
SDL_Surface* BK_S = NULL;
SDL_Surface* BQ_S = NULL;
SDL_Surface* BR_S = NULL;
SDL_Surface* BB_S = NULL;
SDL_Surface* BN_S = NULL;
SDL_Surface* BP_S = NULL;
SDL_Surface* WS_S = NULL;
SDL_Surface* BS_S = NULL;
SDL_Surface* check_logo = NULL;
SDL_Surface* mate_w_logo = NULL;
SDL_Surface* mate_b_logo = NULL;
SDL_Surface* tie_logo = NULL;
SDL_Surface* illegal_move_logo = NULL;
SDL_Surface* set_and_ret_button = NULL;
SDL_Surface* clear_button = NULL;
SDL_Surface* wb_init_logo = NULL;
SDL_Surface* wrong_piece_logo = NULL;
SDL_Surface* rook_p = NULL;
SDL_Surface* knight_p = NULL;
SDL_Surface* queen_p = NULL;
SDL_Surface* bishop_p = NULL;
SDL_Surface* choose_p = NULL;

SDL_Surface* click_ts_logo = NULL;
SDL_Surface* click_tl_logo = NULL;
SDL_Surface* ns_logo = NULL;
SDL_Surface* slot1_button = NULL;
SDL_Surface* slot2_button = NULL;
SDL_Surface* slot3_button = NULL;
SDL_Surface* slot4_button = NULL;
SDL_Surface* slot5_button = NULL;
SDL_Surface* slot6_button = NULL;
SDL_Surface* slot7_button = NULL;
SDL_Surface* click_tr_button = NULL;
SDL_Surface* game_saved_logo = NULL;

SDL_Rect NG_button = { 550, 150, 204, 54 };
SDL_Rect LG_button = { 550, 250, 204, 54 };
SDL_Rect Q_button = { 550, 350, 204, 54 };
SDL_Rect PVP_button = { 270, 150, 212, 50 };
SDL_Rect PVC_button = { 490, 150, 212, 50 };
SDL_Rect Cancel_button = { 490, 400, 212, 50 };
SDL_Rect STB_button = { 490, 330, 212, 50 };
SDL_Rect W_button = { 270, 220, 212, 50 };
SDL_Rect B_button = { 490, 220, 212, 50 };
SDL_Rect D1_button = { 250, 170, 75, 50 };
SDL_Rect D2_button = { 330, 170, 75, 50 };
SDL_Rect D3_button = { 410, 170, 75, 50 };
SDL_Rect D4_button = { 490, 170, 75, 50 };
SDL_Rect BD_button = { 570, 170, 212, 50 };
SDL_Rect return_AI_button = { 390, 310, 285, 50 };

SDL_Rect D1_M_button = { 140, 220, 75, 50 };
SDL_Rect D2_M_button = { 220, 220, 75, 50 };
SDL_Rect D3_M_button = { 300, 220, 75, 50 };
SDL_Rect D4_M_button = { 380, 220, 75, 50 };
SDL_Rect BD_M_button = { 460, 220, 212, 50 };
SDL_Rect return_M_button = { 390, 300, 285, 50 };

SDL_Rect W_AI_button = { 300, 240, 212, 50 };
SDL_Rect B_AI_button = { 530, 240, 212, 50 };
SDL_Rect SG_button = { 610, 0, 190, 50 };
SDL_Rect MM_button = { 610, 100, 190, 50 };
SDL_Rect Q_GW_button = { 610, 550, 190, 50 };
SDL_Rect CB_logo = { 0, 0, 600, 600 };
SDL_Rect bm_button = { 610, 200, 190, 50 };
SDL_Rect lm_button = {610, 250, 190, 50};
SDL_Rect start_PSW_button = { 270, 330, 212, 50 };

SDL_Rect s1_button = { 150, 200, 212, 50 };
SDL_Rect s2_button = { 150, 270, 212, 50 };
SDL_Rect s3_button = { 150, 340, 212, 50 };
SDL_Rect s4_button = { 450, 200, 212, 50 };
SDL_Rect s5_button = { 450, 270, 212, 50 };
SDL_Rect s6_button = { 450, 340, 212, 50 };
SDL_Rect s7_button = { 450, 410, 212, 50 };
SDL_Rect ctr_button = { 250, 550, 285, 50 };


SDL_Rect WP_box = { 620, 0 , 75 , 75 };
SDL_Rect WN_box = { 620, 80, 75, 75 };
SDL_Rect WR_box = { 620, 160, 75, 75 };
SDL_Rect WB_box = { 620, 240, 75, 75 };
SDL_Rect WQ_box = { 620, 320, 75, 75 };
SDL_Rect WK_box = { 620, 400, 75, 75 };

SDL_Rect BP_box = { 700, 0, 75, 75 };
SDL_Rect BN_box = { 700, 80, 75, 75 };
SDL_Rect BR_box = { 700, 160, 75, 75 };
SDL_Rect BB_box = { 700, 240, 75, 75 };
SDL_Rect BQ_box = { 700, 320, 75, 75 };
SDL_Rect BK_box = { 700, 400, 75, 75 };
SDL_Rect sat_button = { 607, 550, 190, 50 };
SDL_Rect clr_button = { 607, 480, 190, 50 };

//promotions buttons
SDL_Rect KP_button = { 610, 100, 190, 50 };
SDL_Rect BP_button = { 610, 175, 190, 50 };
SDL_Rect RP_button = { 610, 250, 190, 50 };
SDL_Rect QP_button = { 610, 325, 190, 50 };

SDL_Rect thinking_button = { 610, 325, 200, 60 };

SDL_Event event;

/*
* Freeing all available SDL resources
*/
void freeAll(){
	//Free the following surfaces
	SDL_FreeSurface(chess_logo);
	SDL_FreeSurface(background);
	SDL_FreeSurface(quit_game_button);
	SDL_FreeSurface(new_game_button);
	SDL_FreeSurface(load_game_button);

	SDL_FreeSurface(game_mode_logo);
	SDL_FreeSurface(set_the_board_button);
	SDL_FreeSurface(white_button);
	SDL_FreeSurface(black_button);
	SDL_FreeSurface(white_s_button);
	SDL_FreeSurface(black_s_button);
	SDL_FreeSurface(cancel_button);
	SDL_FreeSurface(pvp_button);
	SDL_FreeSurface(pvc_button);
	SDL_FreeSurface(next_player_logo);
	SDL_FreeSurface(dol_logo);
	SDL_FreeSurface(pvc_s_button);
	SDL_FreeSurface(pvp_s_button);

	SDL_FreeSurface(player_col_logo);
	SDL_FreeSurface(difficulty_logo);
	SDL_FreeSurface(best_depth_button);
	SDL_FreeSurface(depth_1_button);
	SDL_FreeSurface(depth_2_button);
	SDL_FreeSurface(depth_3_button);
	SDL_FreeSurface(depth_4_button);
	SDL_FreeSurface(depth_1_s_button);
	SDL_FreeSurface(depth_2_s_button);
	SDL_FreeSurface(depth_3_s_button);
	SDL_FreeSurface(depth_4_s_button);
	SDL_FreeSurface(best_depth_s_button);
	SDL_FreeSurface(start_the_game_button);
	SDL_FreeSurface(cmd_logo);
	SDL_FreeSurface(set_and_ret_button);
	SDL_FreeSurface(clear_button);
	SDL_FreeSurface(wb_init_logo);
	SDL_FreeSurface(wrong_piece_logo);

	SDL_FreeSurface(chessboard);
	SDL_FreeSurface(mainmenu_button);
	SDL_FreeSurface(savegame_button);
	SDL_FreeSurface(WK);
	SDL_FreeSurface(WQ);
	SDL_FreeSurface(WR);
	SDL_FreeSurface(WB);
	SDL_FreeSurface(WN);
	SDL_FreeSurface(WP);
	SDL_FreeSurface(BK);
	SDL_FreeSurface(BQ);
	SDL_FreeSurface(BR);
	SDL_FreeSurface(BB);
	SDL_FreeSurface(BN);
	SDL_FreeSurface(BP);
	SDL_FreeSurface(WS);
	SDL_FreeSurface(BS);
	SDL_FreeSurface(WK_S);
	SDL_FreeSurface(WQ_S);
	SDL_FreeSurface(WR_S);
	SDL_FreeSurface(WB_S);
	SDL_FreeSurface(WN_S);
	SDL_FreeSurface(WP_S);
	SDL_FreeSurface(BK_S);
	SDL_FreeSurface(BQ_S);
	SDL_FreeSurface(BR_S);
	SDL_FreeSurface(BB_S);
	SDL_FreeSurface(BN_S);
	SDL_FreeSurface(BP_S);
	SDL_FreeSurface(WS_S);
	SDL_FreeSurface(BS_S);
	SDL_FreeSurface(check_logo);
	SDL_FreeSurface(mate_w_logo);
	SDL_FreeSurface(mate_b_logo);
	SDL_FreeSurface(tie_logo);
	SDL_FreeSurface(illegal_move_logo);
	SDL_FreeSurface(bestmove_button);
    SDL_FreeSurface(thinking_label);
	SDL_FreeSurface(last_move_button);
	SDL_FreeSurface(rook_p);
	SDL_FreeSurface(choose_p);
	SDL_FreeSurface(knight_p);
	SDL_FreeSurface(bishop_p);
	SDL_FreeSurface(queen_p);

	SDL_FreeSurface(click_ts_logo);
	SDL_FreeSurface(click_tl_logo);
	SDL_FreeSurface(ns_logo);
	SDL_FreeSurface(slot1_button);
	SDL_FreeSurface(slot2_button);
	SDL_FreeSurface(slot3_button);
	SDL_FreeSurface(slot4_button);
	SDL_FreeSurface(slot5_button);
	SDL_FreeSurface(slot6_button);
	SDL_FreeSurface(slot7_button);
	SDL_FreeSurface(click_tr_button);
	SDL_FreeSurface(game_saved_logo);

	SDL_FreeSurface(screen);
}

/*
* Setting color key with stability check
*/
void safe_SDL_SetColorKey(SDL_Surface* surface, int R, int G, int B){
	if (SDL_SetColorKey(surface, SDL_SRCCOLORKEY, SDL_MapRGB(surface->format, R, G, B)) != 0) {
		printf("ERROR: failed to set color key: %s\n", SDL_GetError());
		freeAll();
		exit(1);
	}
}
/*
* Flipping the buffer with stability check
*/
void safe_SDL_Flip(SDL_Surface* surface){
	//Update the surface
	if (surface != NULL){
		if (SDL_Flip(surface) != 0)
		{
			printf("ERROR: failed to flip buffer: %s\n", SDL_GetError());
			freeAll();
			exit(1);
		}
	}
}

/*
* Applying the surface function
*/
void apply_surface(int x, int y, SDL_Surface* source, SDL_Surface* destination)
{
	//Make a temporary rectangle to hold the offsets
	SDL_Rect offset;
	//Give the offsets to the rectangle
	offset.x = x;
	offset.y = y;
	//Blit the surface
	if (SDL_BlitSurface(source, NULL, destination, &offset) != 0){
		printf("ERROR: failed to blit image: %s\n", SDL_GetError());
		freeAll();
		exit(1);
	}
}
/*
* Detecting whether the given coordinates are in a specified Rect
*/
int xyInRect(int x, int y, SDL_Rect rect){
	return ((x > rect.x) && (x < rect.x + rect.w) && (y > rect.y) && (y < rect.y + rect.h));
}


/*
* Loading bitmaps function
*/
SDL_Surface *load_image(char* filename)
{
	//Temporary storage for the image that's loaded
	SDL_Surface* loadedImage = NULL;

	//The optimized image that will be used
	SDL_Surface* optimizedImage = NULL;

	char* full_path = concat("images/", filename);

	//Load the image
	loadedImage = SDL_LoadBMP(full_path);

	free(full_path);

	//If nothing went wrong in loading the image
	if (loadedImage != NULL)
	{
		//Create an optimized image
		optimizedImage = SDL_DisplayFormat(loadedImage);

		//Free the old image
		SDL_FreeSurface(loadedImage);
	}
	//Return the optimized image
	return optimizedImage;
}

/*
* Concatenating two strings
*/
char* concat(char* s1, char* s2)
{
	char* result = calloc(strlen(s1) + strlen(s2) + 1,sizeof(char)); //+1 for the zero-terminator
	validate(result, "concat");
	int i;
	for ( i = 0; i < (int)strlen(s1); i++){
		result[i] = s1[i];
	}
	for (int j = 0; j < (int)strlen(s2); j++){
		result[i++] = s2[j];
	}
	return result;
}

/*
* Loading Main window
*/
void loadMainWindow(){
	//Load the images 
	chess_logo = load_image("chesslogo.bmp");
	background = load_image("background.bmp");
	quit_game_button = load_image("quit.bmp");
	new_game_button = load_image("newgame.bmp");
	load_game_button = load_image("loadgame.bmp");
	//Set the window caption
	SDL_WM_SetCaption("Main Window", NULL);
	//Check if bitmap loading have succeeded
	if (chess_logo == NULL || background == NULL || quit_game_button == NULL || load_game_button == NULL || new_game_button == NULL)
	{
		printf("ERROR: unable to load bitmap: %s\n", SDL_GetError());
		freeAll();
		exit(1);
	}
	//Apply the background to the screen
	apply_surface(0, 0, background, screen);
	//Apply the logo to the screen
	apply_surface(250, 0, chess_logo, screen);
	//Apply the quit button to the screen
	apply_surface(550, 350, quit_game_button, screen);
	//Apply the New Game button to the screen
	apply_surface(550, 150, new_game_button, screen);
	//Apply the Load Game button to the screen
	apply_surface(550, 250, load_game_button, screen);
	//The mouse offsets
	int x = 0, y = 0;
	int running = 1;
	while (running){
		//While there's an event to handle
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_MOUSEBUTTONDOWN)
			{
				//Get the mouse offsets
				x = event.button.x;
				y = event.button.y;
				//If the left mouse button was pressed
				if (event.button.button == SDL_BUTTON_LEFT)
				{
					//If New Game button was clicked
					if (xyInRect(x, y, NG_button))
					{
						//Show the selection window for a player to choose his options
						loadPlayersSelectionWindow(0);
					}
					//If Load Game button was clicked
					if (xyInRect(x, y, LG_button))
					{
						// Loading the saved board and showing the selection window to the user -> Loading saved board must be implemented here
						loadSaveGameOrLoadGameWindow(0);
					}
					//If Quit Game button was clicked
					if (xyInRect(x, y, Q_button))
					{
						running = 0;
					}

				}

			}
			//If the user has Xed out the window
			if (event.type == SDL_QUIT)
			{
				//Quit the program
				running = 0;
			}
			safe_SDL_Flip(screen);
		}
	}
	freeAll();
	//Quit SDL
	SDL_Quit();
	exit(0);
}

/*
* Loading Players Selection window
*/
void loadPlayersSelectionWindow(){
	apply_surface(0, 0, background, screen);
	apply_surface(250, 0, chess_logo, screen);
	//Load the relevant images 
	set_the_board_button = load_image("set_the_board.bmp");
	next_player_logo = load_image("nextplayer.bmp");
	game_mode_logo = load_image("gamemode.bmp");
	pvc_button = load_image("pvc.bmp");
	pvp_button = load_image("pvp.bmp");
	pvc_s_button = load_image("pvc_s.bmp");
	pvp_s_button = load_image("pvp_s.bmp");
	dol_logo = load_image("dol_logo.bmp");
	cancel_button = load_image("cancel.bmp");
	black_button = load_image("black.bmp");
	white_button = load_image("white.bmp");
	white_s_button = load_image("white_s.bmp");
	black_s_button = load_image("black_s.bmp");
	start_the_game_button = load_image("start_the_game.bmp");
	//Set the window caption
	SDL_WM_SetCaption("Player Selection Window", NULL);
	//Check if bitmap loading have succeeded
	if (set_the_board_button == NULL || next_player_logo == NULL || game_mode_logo == NULL || pvc_button == NULL || pvp_button == NULL || cancel_button == NULL
		|| black_button == NULL || white_button == NULL || white_s_button == NULL || black_s_button == NULL || start_the_game_button == NULL)
	{
		printf("ERROR: unable to load bitmap: %s\n", SDL_GetError());
		freeAll();
		exit(1);
	}
	//Apply the game mode logo to the screen
	apply_surface(50, 150, game_mode_logo, screen);
	//Apply the set the board button to the screen
	apply_surface(490, 330, set_the_board_button, screen);
	//Apply the Start The Game button
	apply_surface(270, 330, start_the_game_button, screen);
	//Apply the next player logo to the screen
	apply_surface(50, 220, next_player_logo, screen);

	if (game_mode == 1){
		//Apply the PVP button to the screen
		apply_surface(490, 150, pvc_button, screen);
		apply_surface(270, 150, pvp_s_button, screen);
	}
	else{
		//Apply the PVC button to the screen
		apply_surface(490, 150, pvc_s_button, screen);
		apply_surface(270, 150, pvp_button, screen);
	}

	//Apply the White,Black buttons to the screen according to the settings
	if (next_player == 'W'){
		apply_surface(270, 220, white_s_button, screen);
		apply_surface(490, 220, black_button, screen);
	}
	else{
		apply_surface(270, 220, white_button, screen);
		apply_surface(490, 220, black_s_button, screen);
	}
	//Apply the Cancel button to the screen
	apply_surface(490, 400, cancel_button, screen);
	//Apply the "default or loaded settings are highlighted" logo
	apply_surface(200, 565, dol_logo, screen);
	//The mouse offsets
	int x = 0, y = 0;
	int running = 1;
	while (running){
		//While there's an event to handle
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_MOUSEBUTTONDOWN)
			{
				//Get the mouse offsets
				x = event.button.x;
				y = event.button.y;
				//If the left mouse button was pressed
				if (event.button.button == SDL_BUTTON_LEFT)
				{
					if (xyInRect(x, y, W_button))
					{
						//Setting next player color to white
						apply_surface(270, 220, white_s_button, screen);
						apply_surface(490, 220, black_button, screen);
						next_player = 'W';
					}
					if (xyInRect(x, y, B_button))
					{
						//Setting next player color to black
						apply_surface(270, 220, white_button, screen);
						apply_surface(490, 220, black_s_button, screen);
						next_player = 'B';
					}
					if (xyInRect(x, y, PVP_button))
					{
						//Set game mode to player vs. player and load window to choose minimax depth for the best move option
						game_mode = 1;
						loadMinimaxDepthWindow();
					}
					if (xyInRect(x, y, PVC_button))
					{
						//Set game mode to player vs. computer and load AI Settings Window
						game_mode = 2;
						loadAISettingsWindow();
					}
					if (xyInRect(x, y, STB_button))
					{
						//Setting the game board
						loadBoardSettingWindow();
						
					}
					if (xyInRect(x, y, start_PSW_button))
					{
						//After all settings were set , start the game
						loadGameWindow();
					}
					if (xyInRect(x, y, Cancel_button))
					{
						//Return to main window
						minimax_depth = 1;
						game_mode = 1;
						user_color = 'W';
						next_player = 'W';
						init_board();
						loadMainWindow();
					}
				}
			}
			//If the user has Xed out the window
			if (event.type == SDL_QUIT)
			{
				//Quit the program
				running = 0;
			}
			safe_SDL_Flip(screen);
		}
	}
	freeAll();
	//Quit SDL
	SDL_Quit();
	exit(0);
}

/*
* Loading a window to choose a minimax depth for the Best Move (for a user who chose to play Player vs. Player game mode)
*/
void loadMinimaxDepthWindow(){
	apply_surface(0, 0, background, screen);
	apply_surface(250, 0, chess_logo, screen);
	//Load the relevant images 
	depth_1_button = load_image("1.bmp");
	depth_1_s_button = load_image("1_s.bmp");
	depth_2_button = load_image("2.bmp");
	depth_2_s_button = load_image("2_s.bmp");
	depth_3_button = load_image("3.bmp");
	depth_3_s_button = load_image("3_s.bmp");
	depth_4_button = load_image("4.bmp");
	depth_4_s_button = load_image("4_s.bmp");
	best_depth_button = load_image("best.bmp");
	best_depth_s_button = load_image("best_s.bmp");
	cmd_logo = load_image("cmd_logo.bmp");
	click_tr_button = load_image("click_tr.bmp");
	//Set the window caption
	SDL_WM_SetCaption("Minimax Depth Settings Window", NULL);
	//Check if bitmap loading have succeeded
	if (depth_1_button == NULL || depth_2_button == NULL || depth_3_button == NULL || depth_4_button == NULL
		 || best_depth_button == NULL || depth_1_s_button == NULL || depth_2_s_button == NULL
		 || depth_3_s_button == NULL || depth_4_s_button == NULL || click_tr_button == NULL || best_depth_s_button == NULL || cmd_logo == NULL)
	{
		printf("ERROR: unable to load bitmap: %s\n", SDL_GetError());
		freeAll();
		exit(1);
	}

	//Apply the Choose Minimax Depth logo
	apply_surface(110, 150, cmd_logo, screen);
	//Apply start the game button to the screen
	apply_surface(390, 300, click_tr_button, screen);
	//Apply the minimax depth buttons according to the minimax_depth
	if (minimax_depth == 1){
		apply_surface(140, 220, depth_1_s_button, screen);
		apply_surface(220, 220, depth_2_button, screen);
		apply_surface(300, 220, depth_3_button, screen);
		apply_surface(380, 220, depth_4_button, screen);
		apply_surface(460, 220, best_depth_button, screen);
	}
	else if (minimax_depth == 2){
		apply_surface(140, 220, depth_1_button, screen);
		apply_surface(220, 220, depth_2_s_button, screen);
		apply_surface(300, 220, depth_3_button, screen);
		apply_surface(380, 220, depth_4_button, screen);
		apply_surface(460, 220, best_depth_button, screen);
	}
	else if (minimax_depth == 3){
		apply_surface(140, 220, depth_1_button, screen);
		apply_surface(220, 220, depth_2_button, screen);
		apply_surface(300, 220, depth_3_s_button, screen);
		apply_surface(380, 220, depth_4_button, screen);
		apply_surface(460, 220, best_depth_button, screen);
	}
	else if (minimax_depth == 4){
		apply_surface(140, 220, depth_1_button, screen);
		apply_surface(220, 220, depth_2_button, screen);
		apply_surface(300, 220, depth_3_button, screen);
		apply_surface(380, 220, depth_4_s_button, screen);
		apply_surface(460, 220, best_depth_button, screen);
	}
	else{
		apply_surface(140, 220, depth_1_button, screen);
		apply_surface(220, 220, depth_2_button, screen);
		apply_surface(300, 220, depth_3_button, screen);
		apply_surface(380, 220, depth_4_button, screen);
		apply_surface(460, 220, best_depth_s_button, screen);
	}

	//Apply the "default or loaded settings are highlighted" logo
	apply_surface(200, 565, dol_logo, screen);

	int x = 0, y = 0;
	int running = 1;
	while (running){
		//While there's an event to handle
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_MOUSEBUTTONDOWN)
			{
				//Get the mouse offsets
				x = event.button.x;
				y = event.button.y;
				//If the left mouse button was pressed
				if (event.button.button == SDL_BUTTON_LEFT)
				{
					if (xyInRect(x, y, D1_M_button))
					{
						//Setting minimax depth to 1
						apply_surface(140, 220, depth_1_s_button, screen);
						apply_surface(220, 220, depth_2_button, screen);
						apply_surface(300, 220, depth_3_button, screen);
						apply_surface(380, 220, depth_4_button, screen);
						apply_surface(460, 220, best_depth_button, screen);

						minimax_depth = 1;
					}
					if (xyInRect(x, y, D2_M_button))
					{
						//Setting minimax depth to 2
						apply_surface(140, 220, depth_1_button, screen);
						apply_surface(220, 220, depth_2_s_button, screen);
						apply_surface(300, 220, depth_3_button, screen);
						apply_surface(380, 220, depth_4_button, screen);
						apply_surface(460, 220, best_depth_button, screen);

						minimax_depth = 2;
					}
					if (xyInRect(x, y, D3_M_button))
					{
						//Setting minimax depth to 3
						apply_surface(140, 220, depth_1_button, screen);
						apply_surface(220, 220, depth_2_button, screen);
						apply_surface(300, 220, depth_3_s_button, screen);
						apply_surface(380, 220, depth_4_button, screen);
						apply_surface(460, 220, best_depth_button, screen);

						minimax_depth = 3;
					}
					if (xyInRect(x, y, D4_M_button))
					{
						//Setting minimax depth to 4
						apply_surface(140, 220, depth_1_button, screen);
						apply_surface(220, 220, depth_2_button, screen);
						apply_surface(300, 220, depth_3_button, screen);
						apply_surface(380, 220, depth_4_s_button, screen);
						apply_surface(460, 220, best_depth_button, screen);

						minimax_depth = 4;
					}
					if (xyInRect(x, y, BD_M_button))
					{
						//Setting minimax depth to best
						apply_surface(140, 220, depth_1_button, screen);
						apply_surface(220, 220, depth_2_button, screen);
						apply_surface(300, 220, depth_3_button, screen);
						apply_surface(380, 220, depth_4_button, screen);
						apply_surface(460, 220, best_depth_s_button, screen);

						minimax_depth = 0;
					}
					if (xyInRect(x, y, return_M_button))
					{
						//Return to Players Selection Window
						loadPlayersSelectionWindow();
					}

				}
			}
			//If the user has Xed out the window
			if (event.type == SDL_QUIT)
			{
				//Quit the program
				running = 0;
			}
			safe_SDL_Flip(screen);
		}
	}
	freeAll();
	//Quit SDL
	SDL_Quit();
	exit(0);
}

/*
* Loading AI Settings window
*/
void loadAISettingsWindow(){
	apply_surface(0, 0, background, screen);
	apply_surface(250, 0, chess_logo, screen);
	//Load the relevant images 
	difficulty_logo = load_image("difficulty.bmp");
	player_col_logo = load_image("player_color.bmp");
	depth_1_button = load_image("1.bmp");
	depth_1_s_button = load_image("1_s.bmp");
	depth_2_button = load_image("2.bmp");
	depth_2_s_button = load_image("2_s.bmp");
	depth_3_button = load_image("3.bmp");
	depth_3_s_button = load_image("3_s.bmp");
	depth_4_button = load_image("4.bmp");
	depth_4_s_button = load_image("4_s.bmp");
	black_button = load_image("black.bmp");
	white_button = load_image("white.bmp");
	white_s_button = load_image("white_s.bmp");
	black_s_button = load_image("black_s.bmp");
	best_depth_button = load_image("best.bmp");
	best_depth_s_button = load_image("best_s.bmp");
	click_tr_button = load_image("click_tr.bmp");

	//Set the window caption
	SDL_WM_SetCaption("AI Settings Window", NULL);
	//Check if bitmap loading have succeeded
	if (difficulty_logo == NULL || player_col_logo == NULL || depth_1_button == NULL || depth_2_button == NULL || depth_3_button == NULL || depth_4_button == NULL
		|| black_button == NULL || white_button == NULL || best_depth_button == NULL || depth_1_s_button == NULL || depth_2_s_button == NULL
		|| depth_3_s_button == NULL || depth_4_s_button == NULL || black_s_button == NULL || white_s_button == NULL || click_tr_button == NULL || best_depth_s_button == NULL)
	{
		printf("ERROR: unable to load bitmap: %s\n", SDL_GetError());
		freeAll();
		exit(1);
	}
	//Apply the difficulty logo to the screen
	apply_surface(0, 170, difficulty_logo, screen);
	//Apply the player color logo to the screen
	apply_surface(12, 240, player_col_logo, screen);

	if (minimax_depth == 1){
		apply_surface(250, 170, depth_1_s_button, screen);
		apply_surface(330, 170, depth_2_button, screen);
		apply_surface(410, 170, depth_3_button, screen);
		apply_surface(490, 170, depth_4_button, screen);
		apply_surface(570, 170, best_depth_button, screen);
	}
	else if (minimax_depth == 2){
		apply_surface(250, 170, depth_1_button, screen);
		apply_surface(330, 170, depth_2_s_button, screen);
		apply_surface(410, 170, depth_3_button, screen);
		apply_surface(490, 170, depth_4_button, screen);
		apply_surface(570, 170, best_depth_button, screen);
	}
	else if (minimax_depth == 3){
		apply_surface(250, 170, depth_1_button, screen);
		apply_surface(330, 170, depth_2_button, screen);
		apply_surface(410, 170, depth_3_s_button, screen);
		apply_surface(490, 170, depth_4_button, screen);
		apply_surface(570, 170, best_depth_button, screen);
	}
	else if (minimax_depth == 4){
		apply_surface(250, 170, depth_1_button, screen);
		apply_surface(330, 170, depth_2_button, screen);
		apply_surface(410, 170, depth_3_button, screen);
		apply_surface(490, 170, depth_4_s_button, screen);
		apply_surface(570, 170, best_depth_button, screen);
	}
	else{
		apply_surface(250, 170, depth_1_button, screen);
		apply_surface(330, 170, depth_2_button, screen);
		apply_surface(410, 170, depth_3_button, screen);
		apply_surface(490, 170, depth_4_button, screen);
		apply_surface(570, 170, best_depth_s_button, screen);
	}
	
	if (user_color == 'W'){
		//Apply the White button to the screen highlighted
		apply_surface(300, 240, white_s_button, screen);
		//Apply the Black button to the screen
		apply_surface(530, 240, black_button, screen);
	}
	else{
		//Apply the White button to the screen
		apply_surface(300, 240, white_button, screen);
		//Apply the Black button to the screen highlighted
		apply_surface(530, 240, black_s_button, screen);
	}
	//Apply the start the game button to the screen
	apply_surface(390, 310, click_tr_button, screen);
	//Apply the "default or loaded settings are highlighted" logo
	apply_surface(200, 565, dol_logo, screen);
	//The mouse offsets
	int x = 0, y = 0;
	int running = 1;
	while (running){
		//While there's an event to handle
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_MOUSEBUTTONDOWN)
			{
				//Get the mouse offsets
				x = event.button.x;
				y = event.button.y;
				//If the left mouse button was pressed
				if (event.button.button == SDL_BUTTON_LEFT)
				{
					if (xyInRect(x, y, W_AI_button))
					{
						//Setting user color to white
						apply_surface(300, 240, white_s_button, screen);
						apply_surface(530, 240, black_button, screen);
						user_color = 'W';
					}
					if (xyInRect(x, y, B_AI_button))
					{
						//Setting user color to black
						apply_surface(300, 240, white_button, screen);
						apply_surface(530, 240, black_s_button, screen);
						user_color = 'B';
					}
					if (xyInRect(x, y, D1_button))
					{
						//Setting minimax depth to 1
						apply_surface(250, 170, depth_1_s_button, screen);
						apply_surface(330, 170, depth_2_button, screen);
						apply_surface(410, 170, depth_3_button, screen);
						apply_surface(490, 170, depth_4_button, screen);
						apply_surface(570, 170, best_depth_button, screen);

						minimax_depth = 1;
					}
					if (xyInRect(x, y, D2_button))
					{
						//Setting minimax depth to 2
						apply_surface(250, 170, depth_1_button, screen);
						apply_surface(330, 170, depth_2_s_button, screen);
						apply_surface(410, 170, depth_3_button, screen);
						apply_surface(490, 170, depth_4_button, screen);
						apply_surface(570, 170, best_depth_button, screen);

						minimax_depth = 2;
					}
					if (xyInRect(x, y, D3_button))
					{
						//Setting minimax depth to 3
						apply_surface(250, 170, depth_1_button, screen);
						apply_surface(330, 170, depth_2_button, screen);
						apply_surface(410, 170, depth_3_s_button, screen);
						apply_surface(490, 170, depth_4_button, screen);
						apply_surface(570, 170, best_depth_button, screen);

						minimax_depth = 3;
					}
					if (xyInRect(x, y, D4_button))
					{
						//Setting minimax depth to 4
						apply_surface(250, 170, depth_1_button, screen);
						apply_surface(330, 170, depth_2_button, screen);
						apply_surface(410, 170, depth_3_button, screen);
						apply_surface(490, 170, depth_4_s_button, screen);
						apply_surface(570, 170, best_depth_button, screen);

						minimax_depth = 4;
					}
					if (xyInRect(x, y, BD_button))
					{
						//Setting minimax depth to best
						apply_surface(250, 170, depth_1_button, screen);
						apply_surface(330, 170, depth_2_button, screen);
						apply_surface(410, 170, depth_3_button, screen);
						apply_surface(490, 170, depth_4_button, screen);
						apply_surface(570, 170, best_depth_s_button, screen);

						minimax_depth = 0;
					}
					if (xyInRect(x, y, return_AI_button))
					{
						//Return to Player Selection Window
						loadPlayersSelectionWindow();
					}

				}
			}
			//If the user has Xed out the window
			if (event.type == SDL_QUIT)
			{
				//Quit the program
				running = 0;
			}
			safe_SDL_Flip(screen);
		}
	}
	freeAll();
	//Quit SDL
	SDL_Quit();
	exit(0);
}
/*
* Loading Board Setting window
*/
void loadBoardSettingWindow(){

	if (SDL_FillRect(screen, 0, SDL_MapRGB(screen->format,255,255,255)) != 0) {
		printf("ERROR: failed to draw rect: %s\n", SDL_GetError());
		freeAll();
		exit(1);
	}
	//Load the relevant images 
	chessboard = load_image("chessboard.bmp");
	WK = load_image("WK.bmp");
	WN = load_image("WN.bmp");
	WB = load_image("WB.bmp");
	WQ = load_image("WQ.bmp");
	WP = load_image("WP.bmp");
	WR = load_image("WR.bmp");
	BK = load_image("BK.bmp");
	BN = load_image("BN.bmp");
	BB = load_image("BB.bmp");
	BQ = load_image("BQ.bmp");
	BP = load_image("BP.bmp");
	BR = load_image("BR.bmp");
	WS = load_image("WS.bmp");
	BS = load_image("BS.bmp");
	wb_init_logo = load_image("wb_init.bmp");
	wrong_piece_logo = load_image("wrong_piece.bmp");

	set_and_ret_button = load_image("setandreturn.bmp");
	clear_button = load_image("clear.bmp");

	safe_SDL_SetColorKey(WP, 255, 255, 255);
	safe_SDL_SetColorKey(WN, 255, 255, 255);
	safe_SDL_SetColorKey(WB, 255, 255, 255);
	safe_SDL_SetColorKey(WQ, 255, 255, 255);
	safe_SDL_SetColorKey(WR, 255, 255, 255);
	safe_SDL_SetColorKey(WK, 255, 255, 255);
	safe_SDL_SetColorKey(BP, 255, 255, 255);
	safe_SDL_SetColorKey(BN, 255, 255, 255);
	safe_SDL_SetColorKey(BB, 255, 255, 255);
	safe_SDL_SetColorKey(BQ, 255, 255, 255);
	safe_SDL_SetColorKey(BR, 255, 255, 255);
	safe_SDL_SetColorKey(BK, 255, 255, 255);
	//Set the window caption
	SDL_WM_SetCaption("Board Setting Window", NULL);
	//Check if bitmap loading have succeeded
	if (chessboard == NULL  || WK == NULL || WN == NULL || WB == NULL || WQ == NULL || WP == NULL || WR == NULL 
		|| BK == NULL || BN == NULL || BB == NULL || BQ == NULL || BP == NULL || BR == NULL || set_and_ret_button == NULL 
		|| clear_button == NULL || wb_init_logo == NULL || wrong_piece_logo == NULL)
	{
		printf("ERROR: unable to load bitmap: %s\n", SDL_GetError());
		freeAll();
		exit(1);
	}
	//Apply the chessboard to the screen
	apply_surface(0, 0, chessboard, screen);
	//Apply the pieces to the screen on the right side of the chessboard
	apply_surface(620, 0, WP, screen);
	apply_surface(700, 0, BP, screen);

	apply_surface(620, 80, WN, screen);
	apply_surface(700, 80, BN, screen);

	apply_surface(620, 160, WR, screen);
	apply_surface(700, 160, BR, screen);

	apply_surface(620, 240, WB, screen);
	apply_surface(700, 240, BB, screen);

	apply_surface(620, 320, WQ, screen);
	apply_surface(700, 320, BQ, screen);

	apply_surface(620, 400, WK, screen);
	apply_surface(700, 400, BK, screen);

	apply_surface(607, 480, clear_button, screen);
	apply_surface(607, 550, set_and_ret_button, screen);

	int running = 1;
	int x = 0, y = 0;
	int Srow = 0, Mrow = 0;
	char Scol = 0, Mcol = 0;
	int piece_clicked = 0;
	char piece_selected;
	int board_updated = 1;
	int after_clear = 0;
	int button_up = 0, button_down = 0;
	char orig_piece=0;
	int* piecesW; int* piecesB;

	while (running){
		//While there's an event to handle
		while (SDL_PollEvent(&event))
		{
			switch (event.type){ 
			case (SDL_MOUSEBUTTONDOWN) :
				//Get the mouse offsets
				x = event.button.x;
				y = event.button.y;
				if (xyInRect(x, y, WP_box))
				{
					piece_selected = WHITE_P;
					piece_clicked = 1;
				}
				else if (xyInRect(x, y, WN_box))
				{
					piece_selected = WHITE_N;
					piece_clicked = 1;
				}
				else if (xyInRect(x, y, WB_box))
				{
					piece_selected = WHITE_B;
					piece_clicked = 1;
				}
				else if (xyInRect(x, y, WQ_box))
				{
					piece_selected = WHITE_Q;
					piece_clicked = 1;
				}
				else if (xyInRect(x, y, WK_box))
				{
					piece_selected = WHITE_K;
					piece_clicked = 1;
				}
				else if (xyInRect(x, y, WR_box))
				{
					piece_selected = WHITE_R;
					piece_clicked = 1;
				}
				else if (xyInRect(x, y, BP_box))
				{
					piece_selected = BLACK_P;
					piece_clicked = 1;
				}
				else if (xyInRect(x, y, BN_box))
				{
					piece_selected = BLACK_N;
					piece_clicked = 1;
				}
				else if (xyInRect(x, y, BB_box))
				{
					piece_selected = BLACK_B;
					piece_clicked = 1;
				}
				else if (xyInRect(x, y, BQ_box))
				{
					piece_selected = BLACK_Q;
					piece_clicked = 1;
				}
				else if (xyInRect(x, y, BK_box))
				{
					piece_selected = BLACK_K;
					piece_clicked = 1;
				}
				else if (xyInRect(x, y, BR_box))
				{
					piece_selected = BLACK_R;
					piece_clicked = 1;
				}	
				else if (xyInRect(x, y, sat_button))
				{
					piecesW = piecesCounter('W');
					piecesB = piecesCounter('B');
					if (piecesW[4] != 1 || piecesB[4] != 1){
						//Show the "Wrong Board Initialization" message if board was not initialized properly
						apply_surface(180, 250, wb_init_logo, screen);
						safe_SDL_Flip(screen);
						SDL_Delay(2000);
						drawboard();
						free(piecesW);
						free(piecesB);
					}
					else{
						free(piecesW);
						free(piecesB);
						loadPlayersSelectionWindow();
					}
				}
				else if (xyInRect(x, y, clr_button))
				{
					after_clear = 1;
					clear_board();
					button_up = button_down = 0;
					Mrow = Srow = 0;
					Mcol = Scol = 0;
					drawboard();
					break;
				}
				x = event.button.x;
				y = event.button.y;
				Srow = BOARD_SIZE - (y / 75);
				Scol = 'a' + (x / 75);
				button_down = 1;
				break;
			
			case  (SDL_MOUSEBUTTONUP):
				if (after_clear){
					after_clear = 0;
					break;
				}
				x = event.button.x;
				y = event.button.y;
				Mrow = BOARD_SIZE - (y / 75);
				Mcol = 'a' + (x / 75);
				button_up = 1;
				break;

			//If the user has Xed out the window
			case (SDL_QUIT):
				//Quit the program
				running = 0;
				break;
			default :
				break;
			}

			if ((button_up && button_down) || board_updated){
				//If piece was selected and dragged from outside to the chessboard
				if (piece_clicked){
					if ((Mcol <= 'h' && Mcol >= 'a' && Mrow <= 8 && Mrow >= 1)){
						orig_piece = board[Mrow - 1][Mcol - 97];
						board[Mrow - 1][Mcol - 97] = piece_selected;
						board_updated = 1;
						piece_clicked = 0;
					}
				}
				//The piece was dragged away from the board , so we will remove it
				if ((Scol <= 'h' && Scol >= 'a' && Srow <= 8 && Srow >= 1)){
					if ((Mcol > 'h' || Mcol < 'a' || Mrow > 8 || Mrow < 1)  && !(Mcol==Scol && Srow==Mrow)){
						board[Srow - 1][Scol - 97] = EMPTY;
						board_updated = 1;
					}
				}
				
				//If piece was dragged inside the board to another place
				if ((Scol <= 'h' && Scol >= 'a' && Srow <= 8 && Srow >= 1) && (Mcol <= 'h' && Mcol >= 'a' && Mrow <= 8 && Mrow >= 1)){
					if (board[Srow - 1][Scol - 97] != EMPTY){
						board[Mrow - 1][Mcol - 97] = board[Srow - 1][Scol - 97];
						if ((Mrow != Srow) || (Mcol != Scol)){
							board[Srow - 1][Scol - 97] = EMPTY;
						}
						board_updated = 1;
					}
				}

				//Checking if the board setting is valid and notifying the user if it's not
				piecesW = piecesCounter('W');
				piecesB = piecesCounter('B');
				if ((((piecesW[0] > 2 || piecesB[0] > 2) || (piecesW[1] > 2 || piecesB[1] > 2)) || ((piecesW[2] > 2 || piecesB[2] > 2) || (piecesW[3] > 1 || piecesB[3] > 1)))
					|| ((piecesW[4] > 1 || piecesB[4] > 1) || (piecesW[5] > 8 || piecesB[5] > 8))){
					board[Mrow - 1][Mcol - 97] = orig_piece;
					//Show the "Setting this piece creates an invalid board" message if there were too much pieces of the same kind
					apply_surface(80, 250, wrong_piece_logo, screen);
					safe_SDL_Flip(screen);
					SDL_Delay(2000);
					drawboard();
				}

				free(piecesW);
				free(piecesB);
				button_up = button_down = 0;
				Mrow = Srow = 0;
				Mcol = Scol = 0;
				if (board_updated){
					drawboard();
					board_updated = 0;

				}
			}
			
		}
		
	}

	freeAll();
	//Quit SDL
	SDL_Quit();
	exit(0);
}

/*
* Loading Save Game window if save_bit == 1 otherwise loading Load Game window
*/
void loadSaveGameOrLoadGameWindow(int save_bit){
	apply_surface(0, 0, background, screen);
	apply_surface(250, 0, chess_logo, screen);
	//Load the relevant images 
	if (save_bit){
		click_ts_logo = load_image("click_ts.bmp");
		game_saved_logo = load_image("game_saved.bmp");
		SDL_WM_SetCaption("Save Game Window", NULL);
	}
	else{
		click_tl_logo = load_image("click_tl.bmp");
		ns_logo = load_image("nothing_saved.bmp");
		SDL_WM_SetCaption("Load Game Window", NULL);
	}

	slot1_button = load_image("slot1.bmp");
	slot2_button = load_image("slot2.bmp");
	slot3_button = load_image("slot3.bmp");
	slot4_button = load_image("slot4.bmp");
	slot5_button = load_image("slot5.bmp");
	slot6_button = load_image("slot6.bmp");
	slot7_button = load_image("slot7.bmp");
	click_tr_button = load_image("click_tr.bmp");
	//Check if bitmap loading have succeeded
	if (save_bit){
		if (click_ts_logo == NULL || slot1_button == NULL || slot2_button == NULL || slot3_button == NULL || slot4_button == NULL || slot5_button == NULL
			|| slot6_button == NULL || slot7_button == NULL || click_tr_button == NULL || game_saved_logo == NULL)
		{
			printf("ERROR: unable to load bitmap: %s\n", SDL_GetError());
			freeAll();
			exit(1);
		}
	}
	else{
		if (slot1_button == NULL || slot2_button == NULL || slot3_button == NULL || slot4_button == NULL || slot5_button == NULL
			|| slot6_button == NULL || slot7_button == NULL || click_tl_logo == NULL || ns_logo == NULL || click_tr_button == NULL)
		{
			printf("ERROR: unable to load bitmap: %s\n", SDL_GetError());
			freeAll();
			exit(1);
		}
	}
	
	//Applying the rellevant surfaces
	if (save_bit){
		apply_surface(150, 130, click_ts_logo, screen);
	}
	else{
		apply_surface(150, 130, click_tl_logo, screen);
	}
	apply_surface(150, 200, slot1_button, screen);
	apply_surface(150, 270, slot2_button, screen);
	apply_surface(150, 340, slot3_button, screen);
	apply_surface(450, 200, slot4_button, screen);
	apply_surface(450, 270, slot5_button, screen);
	apply_surface(450, 340, slot6_button, screen);
	apply_surface(450, 410, slot7_button, screen);
	apply_surface(250, 550, click_tr_button, screen);

	//The mouse offsets
	int x = 0, y = 0;
	int running = 1;
	while (running){
		//While there's an event to handle
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_MOUSEBUTTONDOWN)
			{
				//Get the mouse offsets
				x = event.button.x;
				y = event.button.y;
				//If the left mouse button was pressed
				if (event.button.button == SDL_BUTTON_LEFT)
				{
					if (xyInRect(x, y, s1_button))
					{
						//SLOT1 game save/load button was clicked
						if (save_bit){
							saveGameStateToFile("slot1.xml");
							apply_surface(150, 200, game_saved_logo, screen);
							safe_SDL_Flip(screen);
							SDL_Delay(2000);
							apply_surface(150, 200, slot1_button, screen);
						}
						else{
							if (loadSettingsFromFile("slot1.xml",0)){
								
								loadPlayersSelectionWindow();
							}
							else{
								apply_surface(150, 200, ns_logo, screen);
							}
						}
					}
					if (xyInRect(x, y, s2_button))
					{
						//SLOT2 game save/load button was clicked
						if (save_bit){
							saveGameStateToFile("slot2.xml");
							apply_surface(150, 270, game_saved_logo, screen);
							safe_SDL_Flip(screen);
							SDL_Delay(2000);
							apply_surface(150, 270, slot2_button, screen);
						}
						else{
							if (loadSettingsFromFile("slot2.xml",0)){
								
								loadPlayersSelectionWindow();
							}
							else{
								apply_surface(150, 270, ns_logo, screen);
							}
						}
					}
					if (xyInRect(x, y, s3_button))
					{
						//SLOT3 game save/load button was clicked
						if (save_bit){
							saveGameStateToFile("slot3.xml");
							apply_surface(150, 340, game_saved_logo, screen);
							safe_SDL_Flip(screen);
							SDL_Delay(2000);
							apply_surface(150, 340, slot3_button, screen);
						}
						else{
							if (loadSettingsFromFile("slot3.xml",0)){
								
								loadPlayersSelectionWindow();
							}
							else{
								apply_surface(150, 340, ns_logo, screen);
							}
						}
					}
					if (xyInRect(x, y, s4_button))
					{
						//SLOT4 game save/load button was clicked
						if (save_bit){
							saveGameStateToFile("slot4.xml");
							apply_surface(450, 200, game_saved_logo, screen);
							safe_SDL_Flip(screen);
							SDL_Delay(2000);
							apply_surface(450, 200, slot4_button, screen);
						}
						else{
							if (loadSettingsFromFile("slot4.xml",0)){
	
								loadPlayersSelectionWindow();
							}
							else{
								apply_surface(450, 200, ns_logo, screen);
							}
						}
					}
					if (xyInRect(x, y, s5_button))
					{
						//SLOT5 game save/load button was clicked
						if (save_bit){
							saveGameStateToFile("slot5.xml");
							apply_surface(450, 270, game_saved_logo, screen);
							safe_SDL_Flip(screen);
							SDL_Delay(2000);
							apply_surface(450, 270, slot5_button, screen);
						}
						else{
							if (loadSettingsFromFile("slot5.xml",0)){
								loadPlayersSelectionWindow();
							}
							else{
								apply_surface(450, 270, ns_logo, screen);
							}
						}
					}
					if (xyInRect(x, y, s6_button))
					{
						//SLOT6 game save/load button was clicked
						if (save_bit){
							saveGameStateToFile("slot6.xml");
							apply_surface(450, 340, game_saved_logo, screen);
							safe_SDL_Flip(screen);
							SDL_Delay(2000);
							apply_surface(450, 340, slot6_button, screen);
						}
						else{
							if (loadSettingsFromFile("slot6.xml",0)){
								loadPlayersSelectionWindow();
							}
							else{
								apply_surface(450, 340, ns_logo, screen);
							}
						}	
					}
					if (xyInRect(x, y, s7_button))
					{
						//SLOT7 game save button was clicked
						if (save_bit){
							saveGameStateToFile("slot7.xml");
							apply_surface(450, 410, game_saved_logo, screen);
							safe_SDL_Flip(screen);
							SDL_Delay(2000);
							apply_surface(450, 410, slot7_button, screen);
						}
						else{
							if (loadSettingsFromFile("slot7.xml",0)){
								loadPlayersSelectionWindow();
							}
							else{
								apply_surface(450, 410, ns_logo, screen);
							}
						}
					}
					if (xyInRect(x, y, ctr_button))
					{
						//If the game was saved we may return to Game Window, otherwise if we are loading and we regreted somewhy we may return to the Main Window
						if (save_bit){
							loadGameWindow();
						}
						else{
							loadMainWindow();
						}
					}
				}
			}
			//If the user has Xed out the window
			if (event.type == SDL_QUIT)
			{
				//Quit the program
				running = 0;
			}
			safe_SDL_Flip(screen);
		}
	}
	freeAll();
	//Quit SDL
	SDL_Quit();
	exit(0);
}

/*
* Applying black or white square in the right place on the board
*/
void applyBlackOrWhiteSquare(int i, int j, SDL_Surface* WS_surr, SDL_Surface* BS_surr){
	if ((i + j) % 2){
		apply_surface(75 * j, 75 * (7 - i), BS_surr, screen);
	}
	else{
		apply_surface(75 * j, 75 * (7 - i), WS_surr, screen);
	}
}

/*
* Drawing the selected pieces on the board
*/
void drawSelectedPieces(char playing_color,move * curr_move ){
	
	move* head = curr_move;
	position* curr_pos = head->current_pos;
	int i=0, j=0;
	while (curr_pos != NULL){
		i = curr_pos->y - 1;
		j = curr_pos->x - 97;

		if (board[i][j] == WHITE_P)
		{
			apply_surface(75 * j, 75 * (7 - i), WP_S, screen);
		}
		else if (board[i][j] == WHITE_N)
		{
			apply_surface(75 * j, 75 * (7 - i), WN_S, screen);
		}
		else if (board[i][j] == WHITE_B)
		{
			apply_surface(75 * j, 75 * (7 - i), WB_S, screen);
		}
		else if (board[i][j] == WHITE_R)
		{
			apply_surface(75 * j, 75 * (7 - i), WR_S, screen);
		}
		else if (board[i][j] == WHITE_Q)
		{
			apply_surface(75 * j, 75 * (7 - i), WQ_S, screen);
		}
		else if (board[i][j] == WHITE_K)
		{
			apply_surface(75 * j, 75 * (7 - i), WK_S, screen);
		}
		else if (board[i][j] == BLACK_P)
		{
			apply_surface(75 * j, 75 * (7 - i), BP_S, screen);
		}
		else if (board[i][j] == BLACK_N)
		{
			apply_surface(75 * j, 75 * (7 - i), BN_S, screen);
		}
		else if (board[i][j] == BLACK_B)
		{
			apply_surface(75 * j, 75 * (7 - i), BB_S, screen);
		}
		else if (board[i][j] == BLACK_R)
		{
			apply_surface(75 * j, 75 * (7 - i), BR_S, screen);
		}
		else if (board[i][j] == BLACK_Q)
		{
			apply_surface(75 * j, 75 * (7 - i), BQ_S, screen);
		}
		else if (board[i][j] == BLACK_K)
		{
			apply_surface(75 * j, 75 * (7 - i), BK_S, screen);
		}
		else{
			applyBlackOrWhiteSquare(i, j, WS_S, BS_S);
		}

		curr_pos = curr_pos->next;
	}
	safe_SDL_Flip(screen);
}

/*
* Drawing the pieces on the board
*/
void drawboard()
{
	for (int i = 7; i >= 0; i--)
	{
		for (int j = 0; j < 8; j++){

			switch (board[i][j]) {
			case (WHITE_P) :
				applyBlackOrWhiteSquare(i, j, WS, BS);
				apply_surface(75 * j, 75 * (7 - i), WP, screen);
				break;

			case (WHITE_N) :

				applyBlackOrWhiteSquare(i, j, WS, BS);
				apply_surface(75 * j, 75 * (7 - i), WN, screen);
				break;
			case (WHITE_B) :

				applyBlackOrWhiteSquare(i, j, WS, BS);
				apply_surface(75 * j, 75 * (7 - i), WB, screen);
				break;

			case (WHITE_R) :

				applyBlackOrWhiteSquare(i, j, WS, BS);
				apply_surface(75 * j, 75 * (7 - i), WR, screen);
				break;

			case (WHITE_Q) :

				applyBlackOrWhiteSquare(i, j, WS, BS);
				apply_surface(75 * j, 75 * (7 - i), WQ, screen);
				break;

			case (WHITE_K) :

				applyBlackOrWhiteSquare(i, j, WS, BS);
				apply_surface(75 * j, 75 * (7 - i), WK, screen);
				break;

			case (BLACK_P) :

				applyBlackOrWhiteSquare(i, j, WS, BS);
				apply_surface(75 * j, 75 * (7 - i), BP, screen);
				break;

			case (BLACK_N) :

				applyBlackOrWhiteSquare(i, j, WS, BS);
				apply_surface(75 * j, 75 * (7 - i), BN, screen);
				break;

			case (BLACK_B) :

				applyBlackOrWhiteSquare(i, j, WS, BS);
				apply_surface(75 * j, 75 * (7 - i), BB, screen);
				break;
			case (BLACK_R) :

				applyBlackOrWhiteSquare(i, j, WS, BS);
				apply_surface(75 * j, 75 * (7 - i), BR, screen);
				break;

			case (BLACK_Q) :

				applyBlackOrWhiteSquare(i, j, WS, BS);
				apply_surface(75 * j, 75 * (7 - i), BQ, screen);
				break;
			case (BLACK_K) :

				applyBlackOrWhiteSquare(i, j, WS, BS);
				apply_surface(75 * j, 75 * (7 - i), BK, screen);
				break;

			default:// IF EMPTY PUT BLACK OR WHITE SQUARE
				applyBlackOrWhiteSquare(i, j, WS, BS);
				break;

			}
		}
	}
	//Update the screen
	safe_SDL_Flip(screen);
}

/*
* Creating a move for a GUI mode with the relevant translated mouse offsets
*/
move* createGuiMove(position* current_pos, int Mrow, char Mcol){
	position* next_pos = calloc(1, sizeof(position));
	validate(next_pos, "createGuiMove");
	initPosition(next_pos, Mcol, Mrow);
	move* new_move = calloc(1,sizeof(move));
	validate(new_move, "createGuiMove");
	new_move->current_pos = current_pos;
	new_move->current_pos->next = next_pos;
	next_pos->next = NULL;
	return new_move;
}

/*
* Updating the board with a legal move in a GUI mode with a window to choose promotion if needed
*/
void actualGUIBoardUpdate(move* current_move, char curr_board[BOARD_SIZE][BOARD_SIZE], char playing_color){
	position* curr_pos = current_move->current_pos;
	int curr_x = curr_pos->x - 97;
	int curr_y = curr_pos->y - 1;

	position* next_pos = curr_pos->next;
	int next_x = next_pos->x - 97;
	int next_y = next_pos->y - 1;

	//Showing an appropriate GUI options for pawn promotion 

	if (isEdge(next_pos, playing_color) && ((curr_board[curr_y][curr_x] == BLACK_P && playing_color == 'B') || (curr_board[curr_y][curr_x] == WHITE_P && playing_color == 'W'))){
		if (SDL_FillRect(screen, 0, 0) != 0) {
			printf("ERROR: failed to draw rect: %s\n", SDL_GetError());
			freeAll();
			exit(1);
		}
		//Load the relevant images 
		knight_p = load_image("knight_p.bmp");
		bishop_p = load_image("bishop_p.bmp");
		queen_p = load_image("queen_p.bmp");
		rook_p = load_image("rook_p.bmp");
		choose_p = load_image("choose_p.bmp");

		//Check if bitmap loading have succeeded
		if (knight_p == NULL || bishop_p == NULL || queen_p == NULL || rook_p == NULL || choose_p == NULL)
		{
			printf("ERROR: unable to load bitmap: %s\n", SDL_GetError());
			freeAll();
			exit(1);
		}
		//Apply the chessboard to the screen
		apply_surface(0, 0, chessboard, screen);
		//Apply the Choose prom. logo to the screen
		apply_surface(610, 0, choose_p, screen);
		//Apply the Knight prom. button to the screen
		apply_surface(610, 100, knight_p, screen);
		//Apply the Bishop prom.  button to the screen
		apply_surface(610, 175, bishop_p, screen);
		//Apply the Rook prom. button to the screen
		apply_surface(610, 250, rook_p, screen);
		//Apply the Queen prom. button to the screen
		apply_surface(610, 325, queen_p, screen);
		//Draw chess pieces to the screen
		drawboard();

		//The mouse offsets
		int x = 0, y = 0;
		int running = 1;

		while (running){
			while (SDL_PollEvent(&event))
			{
				if (event.type == SDL_MOUSEBUTTONDOWN)
				{
					//Get the mouse offsets
					x = event.button.x;
					y = event.button.y;
					//If the left mouse button was pressed
					if (event.button.button == SDL_BUTTON_LEFT)
					{
						//If Knight Prom. button was clicked
						if (xyInRect(x, y, KP_button))
						{
							curr_board[next_y][next_x] = (playing_color == 'W') ? WHITE_N : BLACK_N;
							running = 0;
						}
						//If Rook Prom. button was clicked
						if (xyInRect(x, y, RP_button))
						{
							curr_board[next_y][next_x] = (playing_color == 'W') ? WHITE_R : BLACK_R;
							running = 0;
						}
						//If Queen Prom. button was clicked
						if (xyInRect(x, y, QP_button))
						{
							curr_board[next_y][next_x] = (playing_color == 'W') ? WHITE_Q : BLACK_Q;
							running = 0;
						}
						//If Bishop Prom. button was clicked
						if (xyInRect(x, y, BP_button))
						{
							curr_board[next_y][next_x] = (playing_color == 'W') ? WHITE_B : BLACK_B;
							running = 0;
						}

					}

				}
			}
			//If the user has Xed out the window
			if (event.type == SDL_QUIT)
			{
				//Quit the program
				freeAll();
				//Quit SDL
				SDL_Quit();
				exit(0);
			}
		}
		if (SDL_FillRect(screen, 0, 0) != 0) {
			printf("ERROR: failed to draw rect: %s\n", SDL_GetError());
			freeAll();
			exit(1);
		}
		//Apply the chessboard to the screen
		apply_surface(0, 0, chessboard, screen);
		//Apply the save game button to the screen
		apply_surface(610, 0, savegame_button, screen);
		//Apply the main menu button to the screen
		apply_surface(610, 100, mainmenu_button, screen);
		//Apply the best move  button to the screen
		apply_surface(610, 200, bestmove_button, screen);
		//Apply the last move  button to the screen
		apply_surface(610, 250, last_move_button, screen);
		//Apply the quit game button to the screen
		apply_surface(610, 550, quit_game_button, screen);
		drawboard();
	}
	else{
		curr_board[next_y][next_x] = curr_board[curr_y][curr_x];

	}
	//updating white/black king position on the board if needed
	if (curr_board[curr_y][curr_x] == BLACK_K){
		black_kingpos->x = next_pos->x;
		black_kingpos->y = next_pos->y;
	}
	else if (curr_board[curr_y][curr_x] == WHITE_K){
		white_kingpos->x = next_pos->x;
		white_kingpos->y = next_pos->y;
	}
	curr_board[curr_y][curr_x] = EMPTY; //removing the old position of the man from the board
}

/*
* Updating board after a legal move in a GUI mdoe with appropriate messages
*/
int updateGuiBoard(move* current_move, char playing_color){
	if (!isValidAndLegalPiece(current_move->current_pos, playing_color,0)){
		return 0;
	}
	if (isLegalMove(current_move, playing_color)){
		actualGUIBoardUpdate(current_move, board, playing_color);
	}
	else {
		//PRINTING ILLEGAL MOVE in GUI MODE
		apply_surface(220, 250, illegal_move_logo, screen);
		safe_SDL_Flip(screen);
		SDL_Delay(2000);
		drawboard();
		return 0;
	}
	return 1;
}

/*
* Loading Game window
*/
void loadGameWindow(){
	if (SDL_FillRect(screen, 0, 0) != 0) {
		printf("ERROR: failed to draw rect: %s\n", SDL_GetError());
		freeAll();
		exit(1);
	}
	//Load the relevant images 
	chessboard = load_image("chessboard.bmp");
	mainmenu_button = load_image("mainmenu.bmp");
	savegame_button = load_image("savegame.bmp");
	quit_game_button = load_image("quit.bmp");
	bestmove_button = load_image("best_move.bmp");
	thinking_label = load_image("thinking.bmp");
	last_move_button = load_image("last_move.bmp");
	WK = load_image("WK.bmp");
	WN = load_image("WN.bmp");
	WB = load_image("WB.bmp");
	WQ = load_image("WQ.bmp");
	WP = load_image("WP.bmp");
	WR = load_image("WR.bmp");
	BK = load_image("BK.bmp");
	BN = load_image("BN.bmp");
	BB = load_image("BB.bmp");
	BQ = load_image("BQ.bmp");
	BP = load_image("BP.bmp");
	BR = load_image("BR.bmp");
	WS = load_image("WS.bmp");
	BS = load_image("BS.bmp");

	WK_S = load_image("WK_S.bmp");
	WN_S = load_image("WN_S.bmp");
	WB_S = load_image("WB_S.bmp");
	WQ_S = load_image("WQ_S.bmp");
	WP_S = load_image("WP_S.bmp");
	WR_S = load_image("WR_S.bmp");
	BK_S = load_image("BK_S.bmp");
	BN_S = load_image("BN_S.bmp");
	BB_S = load_image("BB_S.bmp");
	BQ_S = load_image("BQ_S.bmp");
	BP_S = load_image("BP_S.bmp");
	BR_S = load_image("BR_S.bmp");
	WS_S = load_image("WS_S.bmp");
	BS_S = load_image("BS_S.bmp");

	check_logo = load_image("check.bmp");
	mate_w_logo = load_image("mate_w.bmp");
	mate_b_logo = load_image("mate_b.bmp");
	tie_logo = load_image("tie.bmp");
	illegal_move_logo = load_image("illegal_move.bmp");
	safe_SDL_SetColorKey(WP, 255, 255, 255);
	safe_SDL_SetColorKey(WN, 255, 255, 255);
	safe_SDL_SetColorKey(WB, 255, 255, 255);
	safe_SDL_SetColorKey(WQ, 255, 255, 255);
	safe_SDL_SetColorKey(WR, 255, 255, 255);
	safe_SDL_SetColorKey(WK, 255, 255, 255);
	safe_SDL_SetColorKey(BP, 255, 255, 255);
	safe_SDL_SetColorKey(BN, 255, 255, 255);
	safe_SDL_SetColorKey(BB, 255, 255, 255);
	safe_SDL_SetColorKey(BQ, 255, 255, 255);
	safe_SDL_SetColorKey(BR, 255, 255, 255);
	safe_SDL_SetColorKey(BK, 255, 255, 255);
	//Set the window caption
	SDL_WM_SetCaption("Game Window", NULL);
	//Check if bitmap loading have succeeded
	if (chessboard == NULL || mainmenu_button == NULL || savegame_button == NULL || quit_game_button == NULL || WK == NULL || WN == NULL
		|| WB == NULL || WQ == NULL || WP == NULL || WR == NULL || BK == NULL || BN == NULL || BB == NULL || BQ == NULL || BP == NULL || BR == NULL || WS == NULL || BS == NULL
		|| check_logo == NULL || mate_w_logo == NULL || mate_b_logo == NULL || tie_logo == NULL || illegal_move_logo == NULL || bestmove_button == NULL || thinking_label== NULL
		|| WK_S == NULL || WN_S == NULL || WB_S == NULL || WQ_S == NULL || WP_S == NULL || WR_S == NULL || BK_S == NULL || BN_S == NULL || BB_S == NULL || BQ_S == NULL || BP_S == NULL 
		|| BR_S == NULL || WS_S == NULL || BS_S == NULL || last_move_button == NULL)
	{
		printf("ERROR: unable to load bitmap: %s\n", SDL_GetError());
		freeAll();
		exit(1);
	}
	//Apply the chessboard to the screen
	apply_surface(0, 0, chessboard, screen);
	//Apply the save game button to the screen
	apply_surface(610, 0, savegame_button, screen);
	//Apply the main menu button to the screen
	apply_surface(610, 100, mainmenu_button, screen);
	//Apply the best move  button to the screen
	apply_surface(610, 200, bestmove_button, screen);
	//Apply the last move  button to the screen
	apply_surface(610, 250, last_move_button, screen);
	//Apply the quit game button to the screen
	apply_surface(610, 550, quit_game_button, screen);
	//Drawing the pieces as they appear on the board
	drawboard();
	//The mouse offsets
	int x = 0, y = 0;
	int Mrow = 0, Srow = 0;
	char Mcol = 0, Scol = 0;
	int running = 1;

	int player1 = 0;
	int player2 = 0;
	int best_move_pressed = 0;
	moves* best_poss_moves = NULL;
	if (game_mode == 1){
		user_color = next_player;
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
	move * last_move = NULL;
	char playing_color = playingColor(player1, player2);
	int w_k_found = 0; int b_k_found = 0;
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			if (w_k_found && b_k_found) {
				break;
			}
			if (board[i][j] == WHITE_K) {
				white_kingpos = calloc(1, sizeof(position));
				validate(white_kingpos, "loadGameWindow");
				initPosition(white_kingpos, j+97, i+1);
				w_k_found = 1;
			}
			else if (board[i][j] == BLACK_K){
				black_kingpos = calloc(1, sizeof(position));
				validate(black_kingpos, "loadGameWindow");
				initPosition(black_kingpos, j + 97, i + 1);
				b_k_found = 1;
			}
		}
	}
	
	int game_over = gameOver(0,OppositeColor(playing_color));
	int button_down = 0,button_up = 0;

	
	//If it's first iteration and when we start playing there was a  mate or tie made by opposite player , we want to notify the user about it.
	if (game_over){
		
		if (isMate(OppositeColor(playing_color), board, white_kingpos, black_kingpos)){
			//graphical print of mate to playing_color
			playing_color == 'W' ? apply_surface(150, 250, mate_b_logo, screen) : apply_surface(150, 250, mate_w_logo, screen);
			safe_SDL_Flip(screen);
			SDL_Delay(2000);
			drawboard();
		}
		
		else if (isTie(OppositeColor(playing_color), board, white_kingpos, black_kingpos)){
			//graphical print of a tie
			apply_surface(220, 250, tie_logo, screen);
			safe_SDL_Flip(screen);
			SDL_Delay(2000);
			drawboard();
		}
		
	}
	else if (isCheck(OppositeColor(playing_color), board, white_kingpos, black_kingpos)){
		//graphical print of check
		apply_surface(220, 250, check_logo, screen);
		safe_SDL_Flip(screen);
		SDL_Delay(2000);
		drawboard();
	}

	while (running){
		//While there's an event to handle
		while (SDL_PollEvent(&event) || (!player1 && !player2))
		{
			if (event.type == SDL_MOUSEBUTTONDOWN)
			{
				//Get the mouse offsets
				x = event.button.x;
				y = event.button.y;
				//If the left mouse button was pressed
				if (event.button.button == SDL_BUTTON_LEFT)
				{
					if (xyInRect(x, y, SG_button))
					{
						//Saving current game state
						next_player = playingColor(player1, player2);
						loadSaveGameOrLoadGameWindow(1);
					}
					if (xyInRect(x, y, MM_button))
					{
						//Main menu button was pressed
						minimax_depth = 1;
						game_mode = 1;
						user_color = 'W';
						next_player = 'W';
						init_board();
						loadMainWindow();
					}
					if (xyInRect(x, y, Q_GW_button))
					{
						//Quit button was pressed
						running = 0;
					}
					if (xyInRect(x, y, bm_button) && !game_over && !(!player1 && !player2))
					{
						//Best move button was pressed for the first time in this turn
						if (!best_move_pressed){
							playing_color = playingColor(player1, player2);
							apply_surface(610, 325, thinking_label, screen);
							safe_SDL_Flip(screen);
							SDL_FillRect(screen, &thinking_button, 0x000000);
							best_poss_moves = getBestMoves(playing_color);
							best_move_pressed = 1;
						}
						//draw the move on the gui board
						drawSelectedPieces(playing_color, best_poss_moves->head);
						SDL_Delay(2000);
						drawboard();
					}
					if (xyInRect(x, y, lm_button) && !game_over && last_move != NULL){
						playing_color = playingColor(player1, player2);
						//draw the move on the gui board
						drawSelectedPieces(playing_color, last_move);
						SDL_Delay(2000);
						drawboard();
					}
					if (xyInRect(x, y, CB_logo))
					{
						x = event.button.x;
						y = event.button.y;
						Srow = BOARD_SIZE - (y / 75);
						Scol = 'a' + (x / 75);
						button_down = 1;
					}
				}
			}
			if (event.type == SDL_MOUSEBUTTONUP){
				if (event.button.button == SDL_BUTTON_LEFT){
					if (xyInRect(x, y, CB_logo))
					{
						x = event.button.x;
						y = event.button.y;
						Mrow = BOARD_SIZE - (y / 75);
						Mcol = 'a' + (x / 75);
						button_up = 1;
					}
				}
			}
			//If it's computer turn , I don't need to click so that he will be able to move
			if ((game_mode == 2) && !player1 && !player2){
				button_up = button_down = 1;
			}

			//If the user has Xed out the window
			if (event.type == SDL_QUIT)
			{
				//Quit the program
				
				running = 0;
			}

			if ((Mcol > 'h' || Scol > 'h') || (Mcol < 'a' || Scol < 'a') || (Mrow > 8 || Srow > 8) || (Mrow < 1 || Srow < 1)){
				continue;
			}

			if (button_down && button_up && !game_over){
				if (player1 || player2) {
					playing_color = playingColor(player1, player2);
					position * current_pos = malloc(sizeof(position));
					validate(current_pos, "loadGameWindow");
					initPosition(current_pos, Scol, Srow);
					move* current_move = createGuiMove(current_pos, Mrow, Mcol);
					int board_updated = updateGuiBoard(current_move, playing_color);
					
					if (board_updated) {
						freeMoves(last_move);
						last_move = current_move;
						//freeing the best move
						if (best_move_pressed){
							freeMoves(best_poss_moves->head);
							free(best_poss_moves);
							best_move_pressed = 0;
						}
						drawboard();
						if (player1 && player2){
							player1 = player2 = 0;
						}
						else{
							player1 = !player1;
							player2 = !player2;
						}
					}
				}
				else{
					//pc turn
					playing_color = playingColor(player1, player2);
					//applying thinking label
					apply_surface(610, 325, thinking_label, screen);
					safe_SDL_Flip(screen);
					moves* best_moves = getBestMoves(playing_color);
					move* computer_move = best_moves->head;
					freeMoves(last_move);
					last_move = computer_move;
					best_moves->head = computer_move->next;
					actualBoardUpdate(computer_move, board, playing_color, white_kingpos, black_kingpos);
					drawboard();
					SDL_FillRect(screen, &thinking_button, 0x000000);
					freeMoves(best_moves->head);
					free(best_moves);
					last_move->next = NULL;
					player1 = player2 = 1;
				}

				if (isMate(playing_color, board, white_kingpos, black_kingpos)){
					//graphical print of mate to playing_color
					playing_color == 'W' ? apply_surface(150, 250, mate_w_logo, screen) : apply_surface(150, 250, mate_b_logo, screen);
					safe_SDL_Flip(screen);
					SDL_Delay(2000);
					drawboard();
					game_over = 1;
				}
				if (!game_over && (isTie(playing_color, board, white_kingpos, black_kingpos))){
					//graphical print of a tie
					apply_surface(220, 250, tie_logo, screen);
					safe_SDL_Flip(screen);
					SDL_Delay(2000);
					drawboard();
					game_over = 1;
				}

				// Checking if there was a check after a move
				if (!game_over){
					if (isCheck(playing_color, board, white_kingpos, black_kingpos)){
						//graphical print of check
						apply_surface(220, 250, check_logo, screen);
						safe_SDL_Flip(screen);
						SDL_Delay(2000);
						drawboard();
					}
				}

				safe_SDL_Flip(screen);
				button_down = button_up = 0;
			}
			
		}
	}
	freeAll();
	free(white_kingpos);
	free(black_kingpos);
	//Quit SDL
	SDL_Quit();
	exit(0);
}

/*
* Initializing SDL subsystems and setting up the screen
*/
void initSDL(){
	//Initialize all SDL subsystems
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
	{
		printf("ERROR: unable to init SDL: %s\n", SDL_GetError());
		freeAll();
		exit(1);
	}
	atexit(SDL_Quit);
	//Set up the screen
	screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 0, SDL_HWSURFACE | SDL_DOUBLEBUF);
	//If there was an error in setting up the screen
	if (screen == NULL)
	{
		printf("ERROR: unable to initialize screen: %s\n", SDL_GetError());
		freeAll();
		exit(1);
	}
}