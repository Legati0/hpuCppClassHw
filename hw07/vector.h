#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>

class Vector {
public:
	// should be private, but i' too lazy to write get methods
	double x, y, z; 
	
	Vector(double x, double y, double z);
	virtual~ Vector();

	Vector operator+(Vector& vec);
	Vector operator-(Vector& vec);
	Vector& operator+=(Vector& vec);
	Vector operator*(double a);
	double operator*(Vector& vec);
	friend std::ostream& operator<< (std::ostream& out, const Vector& vec); 
};

#endif