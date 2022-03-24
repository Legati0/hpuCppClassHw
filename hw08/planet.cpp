#include "planet.h"
#include <cmath>


Planet::Planet(double m, double r) :
	mass(m), radius(r) {}

Planet::~Planet() {}

bool Planet::gravAcc(const Vector& satPos, Vector& ret) const {
	if (satPos * satPos < radius * radius)
		return false;

	ret = satPos * (-(grav*mass) / std::pow(satPos*satPos, 1.5));
	return true;
}
