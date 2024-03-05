OBJECT_FILES = $(wildcard out/*.o)

app: main.o
	g++ $(OBJECT_FILES) --std=c++20 -o out/xoapp

main.o: main.cpp
	g++ -c main.cpp --std=c++20 -o out/main.o