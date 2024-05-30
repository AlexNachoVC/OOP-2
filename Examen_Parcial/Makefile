main: main.o NumComplejo.o ArregloComplejos.o 
	g++ main.o NumComplejo.o ArregloComplejos.o -o main

main.o: main.cpp
	g++ -c main.cpp

ArregloComplejos.o: ArregloComplejos.cpp ArregloComplejos.h
	g++ -c ArregloComplejos.cpp 

NumComplejo.o: NumComplejo.cpp NumComplejo.h
	g++ -c NumComplejo.cpp

clean:
	rm *.o main