MAIN: main.o BigInt.o
	g++ BigInt.o main.o -o a.out -Wall -O2
	rm *.o
main.o: main.cpp
	g++ -c main.cpp -o main.o
BigInt.o: BigInt.cpp
	g++ -c BigInt.cpp -o BigInt.o
