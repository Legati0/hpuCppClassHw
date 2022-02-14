#include <cstdio>
#include "chArray.h"


void printChArr(char** array, int height) {
	for (int i = 0; i < height; ++i)
		printf("%s\n", array[i]);
}


char** createEmptyChArr(int height, int width) {
	width++;	// one extra char for \0
	// build array
	char** array = new char*[height];
	*array = new char[width * height];
	for (int i = 1; i < height; ++i)
		array[i] = array[i - 1] + width;
	// fill with char
	for (int i = 0; i < height; ++i)
		for (int j = 0; j < width-1; ++j)
			array[i][j] = ' ';
	// add \0
	for (int i = 1; i < height; ++i)
		array[i][width-1] = '\0';
	return array;
}
