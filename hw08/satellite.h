#ifndef SATELLITE_H
#define SATELLITE_H

#include "planet.h"
#include "vector.h"


class Satellite {

private:
	Planet& center;
	Vector pos;
	Vector vel;
public:
	Satellite(Planet& c, Vector p, Vector v) : center(c), pos(p), vel(v) {};
	virtual ~Satellite() {};

	bool update(int dt);
	const Vector& getPos() const;

	friend std::ostream& operator<<(std::ostream& out, const Satellite& s); 

};

#endif