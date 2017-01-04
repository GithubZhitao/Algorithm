main: main.o TwoStackQueue.o
	g++ -o  main main.o TwoStackQueue.o 
main.o:main.cpp
	g++ -c -o main.o main.cpp
TwoStackQueue.o:TwoStackQueue.cpp TwoStackQueue.h
	g++ -c -o TwoStackQueue.o TwoStackQueue.cpp
clean:
	rm main TwoStackQueue.o main.o


