#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>


class Vector {

private:
	double x, y, z; 

public:
	Vector(double x, double y, double z);
	virtual ~Vector();

	Vector operator+(const Vector& vec) const;
	Vector operator-(const Vector& vec) const;
	const Vector& operator+=(const Vector& vec);
	Vector operator*(double a) const;
	double operator*(const Vector& vec) const;
	friend std::ostream& operator<<(std::ostream& out, const Vector& vec); 

};

#endif
