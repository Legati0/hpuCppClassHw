GXX = g++
CFLAGS = -Wall -Werror

all: run

run: main.o chArray.o cannon.o
	$(GXX) $(CFLAGS) -o run main.o chArray.o cannon.o

main.o: main.cpp chArray.h cannon.h
	$(GXX) $(CFLAGS) -c main.cpp

chArray.o: chArray.cpp chArray.h
	$(GXX) $(CFLAGS) -c chArray.cpp

cannon.o: cannon.cpp cannon.h
	$(GXX) $(CFLAGS) -c cannon.cpp

clean:
	rm *.o run
