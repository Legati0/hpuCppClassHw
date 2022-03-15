#include "vector.h"
#include <iostream>


int main() {
	// test print
	Vector vec(1.0, 2.0, 3.0);
	std::cout << "(1, 2, 3)?" << std::endl;
	std::cout << vec << std::endl;
	
	// test addition
	std::cout << "(2, 4, 6)?" << std::endl;
	std::cout << vec + vec << std::endl;

	// test subration
	Vector vec2(0.5, 1.5, 1.0);
	std::cout << "(0.5, 0.5, 2)?" << std::endl;
	std::cout << vec - vec2 << std::endl;
	
	// test inplace addition
	vec2 += vec2;
	std::cout << "(1, 3, 2)?" << std::endl;
	std::cout << vec2 << std::endl;

	// test multiplication with double
	std::cout << "(2, 4, 6)?" << std::endl;
	std::cout << vec * 2.0 << std::endl;

	// test mutliplication of 2 vectors
	std::cout << "1+4+9 = 14?" << std::endl;
	std::cout << vec * vec << std::endl;
	
	return 0;
}
