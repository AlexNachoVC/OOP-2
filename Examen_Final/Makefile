CXXFLAGS = -g -Wall --pedantic

main: main-1.o Vaca.o Gato.o Perro.o Animal.o
	g++ $(CXXFLAGS) main-1.o Vaca.o Gato.o Perro.o Animal.o -o main

main-1.o: main-1.cpp
	g++ -c $(CXXFLAGS) main-1.cpp

Vaca.o: Vaca.cpp Vaca.h
	g++ -c $(CXXFLAGS) Vaca.cpp 

Gato.o: Gato.cpp Gato.h
	g++ -c $(CXXFLAGS) Gato.cpp 

Perro.o: Perro.cpp Perro.h
	g++ -c $(CXXFLAGS) Perro.cpp 

Animal.o: Animal.cpp Animal.h
	g++ -c $(CXXFLAGS) Animal.cpp

clean:
	rm *.o main