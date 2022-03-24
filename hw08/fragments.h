#ifndef FRAGMENTS_H
#define FRAGMENTS_H

#include "planet.h"
#include "vector.h"
#include "satellite.h"


void randCoords(double* x, double* y, double* z);

class Fragments {
private:
	Planet& center;
	int num;
	Satellite** sats;
public:
	Fragments(Planet& planet, Vector& oPos, Vector& oVel, double explSpeed, int fragments);
	virtual ~Fragments();

	int alive() const;
	double smallestDist(const Satellite& sat) const;
	void update(int dt);

};

#endif