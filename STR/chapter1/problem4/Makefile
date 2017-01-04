
main: main.o Pet.o DogCatQueue.o
	g++ -o main  Pet.o DogCatQueue.o main.o 
main.o:main.cpp
	g++ -c -o main.o main.cpp

Pet.o:Pet.cpp
	g++ -c -o Pet.o Pet.cpp
DogCatQueue.o:DogCatQueue.cpp
	g++ -c -o DogCatQueue.o  DogCatQueue.cpp

clean:
	rm main DogCatQueue.o Pet.o main.o


