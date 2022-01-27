GXX = g++
CFLAGS = -Wall -Werror

all: run

run: 4_4.o calc.o
	$(GXX) $(CFLAGS) -o run 4_4.o calc.o

4_4.o: 4_4.cpp calc.h
	$(GXX) $(CFLAGS) -c 4_4.cpp

calc.o: calc.cpp calc.h
	$(GXX) $(CFLAGS) -c calc.cpp

clean:
	rm *.o run
