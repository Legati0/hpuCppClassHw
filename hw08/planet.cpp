#include "planet.h"
#include <cmath>


bool Planet::gravAcc(const Vector& satPos, Vector& ret) const {
	if (satPos * satPos < radius * radius)
		return false;

	ret = satPos * (-(grav*mass) / std::pow(satPos*satPos, 1.5));
	return true;
}
