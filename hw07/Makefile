GXX = g++
CFLAGS = -Wall -Werror

all: run

run: 8_3.o vector.o
	$(GXX) $(CFLAGS) -o run 8_3.o vector.o

8_3.o: 8_3.cpp vector.h
	$(GXX) $(CFLAGS) -c 8_3.cpp

vector.o: vector.cpp vector.h
	$(GXX) $(CFLAGS) -c vector.cpp

clean:
	rm *.o run
