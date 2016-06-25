all: main.o mystring.o
	g++ main.o mystring.o -o out
	rm *.o

main.o: main.cpp
	g++ -c main.cpp

mystring.o: ./../String/mystring.cpp
	g++ -c ./../String/mystring.cpp 