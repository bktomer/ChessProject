#ifndef guiH
#define guiH

#include "SDL.h"
#include "SDL_video.h"
#include "chesslogic.h"
#include "gameflow.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

extern int promoted;
/*
* Freeing all available SDL resources
*/
void freeAll();
/*
* Setting color key with stability check
*/
void safe_SDL_SetColorKey(SDL_Surface* surface, int R, int G, int B);
/*
* Flipping the buffer with stability check
*/
void safe_SDL_Flip(SDL_Surface* surface);
/*
* Applying the surface function
*/
void apply_surface(int x, int y, SDL_Surface* source, SDL_Surface* destination);
/*
* Detecting whether the given coordinates are in a specified Rect
*/
int xyInRect(int x, int y, SDL_Rect rect);
/*
* Loading bitmaps function only if surface does not already exist
*/
SDL_Surface *safe_load_image(char* filename, SDL_Surface* surface);
/*
* Loading bitmaps function
*/
SDL_Surface *load_image(char* filename);
/*
* Loading Main window
*/
void loadMainWindow();
/*
* Loading Players Selection window
*/
void loadPlayersSelectionWindow();
/*
* Loading AI Settings window
*/
void loadAISettingsWindow();
/*
* Loading Board Setting window
*/
void loadBoardSettingWindow();
/*
* Loading Save Game window if save_bit == 1 otherwise loading Load Game window
*/
void loadSaveGameOrLoadGameWindow(int save_bit);
/*
* Applying black or white square in the right place on the board
*/
void applyBlackOrWhiteSquare(int i, int j, SDL_Surface* WS_surr, SDL_Surface* BS_surr);
/*
* Drawing the selected pieces on the board
*/
void drawSelectedPieces(char playing_color, move * curr_move);
/*
* Concatenating two strings
*/
char* concat(char* s1, char* s2);
/*
* Drawing the pieces on the board
*/
void drawboard();
/*
* Loading Game window
*/
void loadGameWindow();
/*
* Loading a window to choose a minimax depth for the Best Move (for a user who chose to play Player vs. Player game mode)
*/
void loadMinimaxDepthWindow();
/*
* Creating a move for a GUI mode with the relevant translated mouse offsets
*/
move* createGuiMove(position* current_pos, int Mrow, char Mcol);
/*
* Updating the board with a legal move in a GUI mode with a window to choose promotion if needed
*/
void actualGUIBoardUpdate(move* current_move, char curr_board[BOARD_SIZE][BOARD_SIZE], char playing_color);
/*
* Updating board after a legal move in a GUI mdoe with appropriate messages
*/
int updateGuiBoard(move* current_move, char playing_color);
/*
* Initializing SDL subsystems and setting up the screen
*/
void initSDL();

#endif
