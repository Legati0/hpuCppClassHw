#include <iostream>
#include "vector.h"


Vector::Vector(double x, double y, double z) : x(x), y(y), z(z) {}

Vector::~Vector() {}

Vector Vector::operator+(const Vector& vec) const {
	return Vector(this->x + vec.x, this->y + vec.y, this->z + vec.z);
}

Vector Vector::operator-(const Vector& vec) const {
	return Vector(this->x - vec.x, this->y - vec.y, this->z - vec.z);
}

const Vector& Vector::operator+=(const Vector& vec) {
	this->x += vec.x;
	this->y += vec.y;
	this->z += vec.z;
	return *this;
}

Vector Vector::operator*(double a) const {
	return Vector(this->x * a, this->y * a, this->z * a);
}

double Vector::operator*(const Vector& vec) const {
	return this->x * vec.x + this->y * vec.y + this->z * vec.z;
}

std::ostream& operator<<(std::ostream& out, const Vector& vec) {
	out << "(" << vec.x << ", " << vec.y << ", " << vec.z << ")";
    return out;
}
