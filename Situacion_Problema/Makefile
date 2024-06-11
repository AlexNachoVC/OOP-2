main: main.o CSVLoader.o  Episodio.o Pelicula.o Video.o
	g++ -g -Wall --pedantic main.o CSVLoader.o  Episodio.o Pelicula.o Video.o -o main

main.o: main.cpp
	g++ -c -g -Wall --pedantic main.cpp

CSVLoader.o: CSVLoader.cpp CSVLoader.h
	g++ -c -g -Wall --pedantic CSVLoader.cpp 

Episodio.o: Episodio.cpp Episodio.h
	g++ -c -g -Wall --pedantic Episodio.cpp 

Pelicula.o: Pelicula.cpp Pelicula.h
	g++ -c -g -Wall --pedantic Pelicula.cpp 

Video.o: Video.cpp Video.h
	g++ -c -g -Wall --pedantic Video.cpp

clean:
	rm *.o main