//#include <iostream>
#include <cstdio>

double acc(double v) {
	return -9.81 + v * v * 0.5 * 1.0 * 1.0 * 1.2 / 80.0;
}

int main() {
	double y = 1000.0;	// current height
	double v = 0.0;		// current speed
	const double dt = 1.0;	// time difference between recalc
	double t = 0.0;		// seconds passed
	while (y > 0.0) {
		double a = acc(v);	// calc current acc
		y += v * dt;		// recalc y
		v += a * dt;		// recalc v
		t += dt;
	}
	//std::cout << t << std::endl;
	printf("Time to impact: %.3lfs\n", t);
	return 0;
}