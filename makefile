app: main.o
	g++ main.o --std=c++20 -o app

main.o: main.cpp
	g++ -c main.cpp --std=c++20