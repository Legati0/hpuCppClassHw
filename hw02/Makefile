GXX = g++
CFLAGS = -Wall -Werror

all: run

run: 3_4.o calc.o
	$(GXX) $(CFLAGS) -o run 3_4.o calc.o

3_4.o: 3_4.cpp calc.h
	$(GXX) $(CFLAGS) -c 3_4.cpp

calc.o: calc.cpp calc.h
	$(GXX) $(CFLAGS) -c calc.cpp

clean:
	rm *.o run
