GXX = g++
CFLAGS = -Wall -Werror

all: run

run: 5_5.o calc.o
	$(GXX) $(CFLAGS) -o run 5_5.o calc.o

5_5.o: 5_5.cpp calc.h
	$(GXX) $(CFLAGS) -c 5_5.cpp

calc.o: calc.cpp calc.h
	$(GXX) $(CFLAGS) -c calc.cpp

clean:
	rm *.o run
