#ifndef PLANET_H
#define PLANET_H

#include "vector.h"
#include <cmath>


class Planet {

private:
	static constexpr double grav = (6.67408 * std::pow(10, -11));
	double mass;
	double radius;
public:
	Planet(double m, double r);
	virtual ~Planet();

	bool gravAcc(const Vector& satPos, Vector& ret) const;

};

#endif