all: compile link

compile: main.cpp
	g++ -c main.cpp

link:
	g++ main.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
