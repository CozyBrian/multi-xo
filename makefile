OBJECT_FILES = $(wildcard out/*.o)

app: xo_game.o main.o
	g++ $(OBJECT_FILES) --std=c++20 -o out/xoapp

main.o: main.cpp
	g++ -c main.cpp --std=c++20 -o out/main.o

xo_game.o: game/xo_game.cpp
	g++ -c game/xo_game.cpp --std=c++20 -o out/xo_game.o

test: main.cpp
	g++ main.cpp -lncurses -o out/test

clean:
	rm out/*.o out/xoapp out/test