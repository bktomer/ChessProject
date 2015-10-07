TARGET:= chessprog
O_FILES:= minimax.o gui.o gameflow.o chesslogic.o main.o

all: $(TARGET)

$(TARGET): $(O_FILES)
	gcc  -o $(TARGET) $(O_FILES) -lm -std=c99 -pedantic-errors -g  `sdl-config --libs` `xml2-config --libs`

main.o: main.c main.h chesslogic.h gameflow.h gui.h
	gcc  -std=c99 -pedantic-errors -c -Wall -g -lm main.c `sdl-config --cflags` `xml2-config --cflags`

chesslogic.o: chesslogic.c chesslogic.h
	gcc  -std=c99 -pedantic-errors -c -Wall -g -lm chesslogic.c `sdl-config --cflags` `xml2-config --cflags`
 
gameflow.o: gameflow.c gameflow.h minimax.h
	gcc  -std=c99 -pedantic-errors -c -Wall -g -lm gameflow.c `sdl-config --cflags` `xml2-config --cflags`

gui.o: gui.c gui.h chesslogic.h gameflow.h
	gcc  -std=c99 -pedantic-errors -c -Wall -g -lm gui.c `sdl-config --cflags` `xml2-config --cflags`

minimax.o: minimax.c minimax.h chesslogic.h
	gcc  -std=c99 -pedantic-errors -c -Wall -g -lm minimax.c `sdl-config --cflags` `xml2-config --cflags`

clean:
	-rm -f $(O_FILES) $(TARGET)
