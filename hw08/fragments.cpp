#include <cmath>
#include <cstdlib>
#include <cfloat>
#include "fragments.h"


void randCoords(double* x, double* y, double* z) {
	*z = 2.0 * ((double) rand() / (double) RAND_MAX) - 1.0;
	auto angle = 2.0 * M_PI * ((double) rand() / (double) RAND_MAX);
	*x = sqrt(1.0 - *z * *z) * cos(angle);
	*y = sqrt(1.0 - *z * *z) * sin(angle);
}


Fragments::Fragments(Planet& planet, Vector& oPos, Vector& oVel, double explSpeed, int fragments) :
		center(planet), num(fragments) {
	sats = new Satellite*[fragments];
	for (auto i = 0; i < num; i++) {
		double x,y,z;
		x=y=z=0;
		randCoords(&x, &y, &z);
		Vector vhat(x, y, z);
		sats[i] = new Satellite(planet, oPos, oVel + vhat*explSpeed);
	}
}

void Fragments::update(int dt) {
	for (auto i = 0; i < num; i++) {
		if (sats[i] == nullptr)
			continue;
		if (!sats[i]->update(dt)) {
			delete sats[i];
			sats[i] = nullptr;
		}
	}
}

int Fragments::alive() const {
	int count = 0;
	for (auto i = 0; i < num; i++)
		if (sats[i] != nullptr)
			count++;
	return count;
}

double Fragments::smallestDist(const Satellite& sat) const {
	auto minDist = DBL_MAX;
	for (auto i = 0; i < num; i++) {
		if (sats[i] == nullptr)
			continue;
		const auto diffV = sat.getPos() - sats[i]->getPos();
		const auto dist = diffV * diffV;
		minDist = std::min(minDist, dist);
	}
	return std::sqrt(minDist);
}

Fragments::~Fragments() {
	for (auto i = 0; i < num; i++) {
		delete sats[i];
		sats[i] = nullptr;
	}
	delete[] sats;
	sats = nullptr;
}
