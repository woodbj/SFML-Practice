all: main preyboid flock link
	./app

flock: Flock.cpp
	g++ -c Flock.cpp -o flock.o

# boid: Boid.cpp 
# 	g++ -c Boid.cpp -o boid.o

preyboid: PreyBoid.cpp 
	g++ -c PreyBoid.cpp -o preyboid.o

main: main.cpp 
	g++ -c main.cpp -o main.o

link:
	g++ preyboid.o flock.o main.o -o app -lsfml-graphics -lsfml-window -lsfml-system

clean:
	rm app main.o flock.o boid.o 
