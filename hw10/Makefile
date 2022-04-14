GXX = g++
CFLAGS = -Wall -Werror

all: run

run: 11_2.o pattern.o
	$(GXX) $(CFLAGS) -o run 11_2.o pattern.o

11_2.o: 11_2.cpp pattern.h
	$(GXX) $(CFLAGS) -c 11_2.cpp

pattern.o: pattern.cpp pattern.h
	$(GXX) $(CFLAGS) -c pattern.cpp

clean:
	rm *.o run
