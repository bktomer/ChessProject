#include "main.h"

int main(int argc, char* argv[]){
	/*
	if (argc > 1){
		if (!strcmp(argv[1], "console")){
			// launch console mode
			init_board();
			SettingsMode();
		}
		else if (!strcmp(argv[1], "gui")){
			// launch gui mode
	      init_board();
			initSDL();
			loadMainWindow();
			freeAll();
			SDL_Quit();
		}
	}
	else{
	//launch console mode
		init_board();
		SettingsMode();
	}*/
	init_board();
	//SettingsMode();
	initSDL();
	loadMainWindow();
	freeAll();
	SDL_Quit();
	return 0;
}


