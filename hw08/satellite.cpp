#include "satellite.h"
#include "planet.h"
#include <iostream>


bool Satellite::update(int dt) {
	Vector acc;
	if (!center.gravAcc(pos, acc)) {
		std::cout << "ded" << std::endl;
		return false;
	}
	pos = pos + vel * dt;
	vel = vel + acc * dt;
	return true;
}

const Vector& Satellite::getPos() const {
	return pos;
}

std::ostream& operator<<(std::ostream& out, const Satellite& s) {
	out << "Pos: " << s.pos << ", Vel: " << s.vel;
    return out;
}
