#include <cmath>
#include <algorithm>
#include "cannon.h"


double calcDrag(double v) {
    return 0.5 * CD * A * P * v * v / M;
}


double range(double theta, char** arr, int height, int width, int scale) {
    // the smaller dt gets, the closer we get to 0, so just do this
    if (std::fmod(theta, 180.0) == 0.0)
        return 0;
    theta *= M_PI / 180.0;
    double x, y = 0.0;
    double vx = V0 * cos(theta);
    double vy = V0 * sin(theta);
    const double dt = DT;
    do {
        // recalc x,y
        x += vx * dt;
        y += vy * dt;

		// add char to array
		const int xpos = (int) x / scale;
		const int ypos = height - ((int) y / scale); // so we start on the bottom
		if (ypos >= 0 && ypos < height && xpos >= 0 && xpos < width)
			arr[ypos][xpos] = '*';

        // recalc const vars
        const double v = sqrt(vx * vx + vy * vy);
        const double drag = calcDrag(v);
        const double ax = -drag * vx / v;
        const double ay = -G - drag * vy / v;
        // recalc vx, vy
        vx += ax * dt;
        vy += ay * dt;
    } while(y > 0.0);
    return x;
}
