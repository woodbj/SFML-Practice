all: main boid flock link
	./app

flock: Flock.cpp
	g++ -c Flock.cpp -o flock.o

boid: Boid.cpp 
	g++ -c Boid.cpp -o boid.o

main: main.cpp 
	g++ -c main.cpp -o main.o

link:
	g++ boid.o flock.o main.o -o app -lsfml-graphics -lsfml-window -lsfml-system
