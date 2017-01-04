
main: main.o matrix.o
	g++ -o main  matrix.o main.o 
main.o:main.cpp
	g++ -c -o main.o main.cpp

matrix.o:matrix.cpp
	g++ -c -o matrix.o matrix.cpp
clean:
	rm main matrix.o main.o


