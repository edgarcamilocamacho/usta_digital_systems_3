all: main

main: main.o arithmetic.o statistics.o
	g++ -o main main.o arithmetic.o statistics.o

main.o: main.cpp arithmetic.h statistics.h
	g++ -c -o main.o main.cpp

arithmetic.o: arithmetic.cpp arithmetic.h
	g++ -c -o arithmetic.o arithmetic.cpp

statistics.o: statistics.cpp statistics.h arithmetic.h
	g++ -c -o statistics.o statistics.cpp

run: main
	./main

.PHONY: clean
clean:
	rm *.o main