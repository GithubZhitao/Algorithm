main: main.o Mystack.o
	g++ -o  main main.o Mystack.o 
main.o:main.cpp
	g++ -c -o main.o main.cpp
Mystack.o:Mystack.cpp Mystack.h
	g++ -c -o Mystack.o Mystack.cpp
clean:
	rm target Mystack.o main.o


