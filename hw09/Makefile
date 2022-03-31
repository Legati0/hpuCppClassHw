GXX = g++
CFLAGS = -Wall -Werror

all: run

run: 10_3.o filestreambuf.o
	$(GXX) $(CFLAGS) -o run 10_3.o filestreambuf.o

10_3.o: 10_3.cpp filestreambuf.h
	$(GXX) $(CFLAGS) -c 10_3.cpp

filestreambuf.o: filestreambuf.cpp filestreambuf.h
	$(GXX) $(CFLAGS) -c filestreambuf.cpp

clean:
	rm *.o run
