#ifndef guiH
#define guiH

#include "SDL.h"
#include "SDL_video.h"
#include "chesslogic.h"
#include "gameflow.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

void loadPlayersSelectionWindow();
void loadMainWindow();
void loadBoardSettingWindow();
void loadGameWindow();
void loadAISettingsWindow();
void freeAllSDL();
void freeAll();
void safe_SDL_SetColorKey(SDL_Surface* surface, int R, int G, int B);
void safe_SDL_Flip(SDL_Surface* surface);
void apply_surface(int x, int y, SDL_Surface* source, SDL_Surface* destination);
int xyInRect(int x, int y, SDL_Rect rect);
SDL_Surface *load_image(char* filename);
void loadMainWindow();
void loadPlayersSelectionWindow();
void loadAISettingsWindow();
void loadBoardSettingWindow();
void loadSaveGameOrLoadGameWindow(int save_bit);
/*
* Drawing the selected pieces on the board
*/
void drawSelectedPieces(char playing_color, move * curr_move);
char* concat(char* s1, char* s2);
void drawboard();
void loadGameWindow();
void loadMinimaxDepthWindow();
void initSDL();

#endif