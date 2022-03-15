#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>

class Vector {

private:
	double x, y, z; 

public:
	Vector(double x, double y, double z);
	virtual ~Vector();

	Vector operator+(Vector& vec);
	Vector operator-(Vector& vec);
	Vector& operator+=(Vector& vec);
	Vector operator*(double a);
	double operator*(Vector& vec);
	friend std::ostream& operator<< (std::ostream& out, const Vector& vec); 

};

#endif
