GXX = g++
CFLAGS = -Wall -Werror

all: run

run: 9_2.o planet.o fragments.o vector.o satellite.o
	$(GXX) $(CFLAGS) -o run 9_2.o planet.o fragments.o vector.o satellite.o

9_2.o: 9_2.cpp vector.h planet.h satellite.h fragments.h
	$(GXX) $(CFLAGS) -c 9_2.cpp

planet.o: planet.cpp planet.h
	$(GXX) $(CFLAGS) -c planet.cpp

fragments.o: fragments.cpp fragments.h
	$(GXX) $(CFLAGS) -c fragments.cpp

vector.o: vector.cpp vector.h
	$(GXX) $(CFLAGS) -c vector.cpp

satellite.o: satellite.cpp satellite.h planet.h
	$(GXX) $(CFLAGS) -c satellite.cpp

clean:
	rm *.o run
