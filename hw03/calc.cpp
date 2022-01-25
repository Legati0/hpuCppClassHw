#include <cstdio>
#include <cmath>
#include <algorithm>
#include "calc.h"

double calcDrag(double v) {
    return 0.5 * CD * A * P * v * v / M;
}
double range(double theta, double* maxHeight) {
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
        *maxHeight = std::max(*maxHeight, y);
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
void table(double min, double max, double step) {
    printf("Theta (°)\t| Range (m)\t| Max Height (m)\n");
    for (auto theta = min; theta <= max; theta += step) {
        double maxHeight = 0.0;
        double x = range(theta, &maxHeight);
        printf("-------------------------------------------------\n");
        printf("%.1lf\t\t|\t%.2lf\t|\t%.2lf\n", theta, x, maxHeight);
    }
}