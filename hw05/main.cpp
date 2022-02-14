#include <cstdio>
#include "chArray.h"
#include "cannon.h"


int main() {
	// create arr
	const int height = 40;
	const int width = 150;
	double angle = 0.0;
	char** array = createEmptyChArr(height, width);

	printf("Input value for firing angle, best between 0 and 90\n");
	scanf("%lf", &angle);
	// no input validation, because i'm lazy

	range(angle, array, height, width, 25);
	printChArr(array, height);

	delete [] *array;
	delete [] array;

	return 0;
}
