#include <cmath>
#include <iostream>
#include "vector.h"
#include "planet.h"
#include "satellite.h"
#include "fragments.h"


#define EARTH_M (5.972 * pow(10, 24))
#define EARTH_R (6.378 * pow(10, 6))

int main() {
	Planet earth(EARTH_M, EARTH_R);
	
	Vector issPos(400000.0 + EARTH_R, 0.0, 0.0);
	Vector issVel(0.0, 7660.0, 0.0);
	Satellite iss(earth, issPos, issVel);

	Vector fragPos(-(400000.0 + EARTH_R), 0.0, 0.0);
	Vector fragVel(0.0, 7660.0, 0.0);
	Fragments frags(earth, fragPos, fragVel, 1000.0, 100);

	auto dt = 1.0;

	auto i = 0;
	while (true){
		iss.update(dt);
		frags.update(dt);
		const auto dist = frags.smallestDist(iss);
		if (dist < 1000) {
			std::cout << dist << "\t!!"<< std::endl;
			dt = 0.001;
		} else {
			std::cout << dist << std::endl;
			dt = 1.0;
		}
		if (i % 100 == 0)
			std::cout << "fragments still alive: " << frags.alive() << std::endl;
	}

	return 0;
}
