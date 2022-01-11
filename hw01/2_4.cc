//#include <iostream>
#include <cstdio>

int main() {
	double y = 1000;
	double v = 0;
	double dt = 1;
	double t = 0;
	while (y > 0) {
		double a = -9.81 + v*v*0.5*1*1*1.2/80;
		y += v*dt;
		v += a*dt;
		t += dt;
	}
	//std::cout << t << std::endl;
	printf("Time to impact: %.3fs\n", t);
	return 0;
}