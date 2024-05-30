main: main.o Cylinder.o Circle.o
	g++ main.o Cylinder.o Circle.o -o main

main.o: main.cpp
	g++ -c main.cpp

Cylinder.o: Cylinder.cpp Cylinder.h
	g++ -c Cylinder.cpp 

Circle.o: Circle.cpp Circle.h
	g++ -c Circle.cpp 

clean:
	rm *.o main