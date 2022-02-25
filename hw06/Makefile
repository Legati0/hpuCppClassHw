GXX = g++
CFLAGS = -Wall -Werror -lportaudio

all: run

run: 7_2.o calc.o
	$(GXX) $(CFLAGS) -o run 7_2.o calc.o

7_2.o: 7_2.cpp calc.h
	$(GXX) $(CFLAGS) -c 7_2.cpp

calc.o: calc.cpp calc.h
	$(GXX) $(CFLAGS) -c calc.cpp

clean:
	rm *.o run
