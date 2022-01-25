#include <cstdio>
#include <cmath>
#include "calc.h"

double calcDrag(double v) {
    return 0.5 * CD * A * P * v * v / M;
}
double range(double theta) {
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
    printf("Theta (°)\t|\tRange (m)\n");
    for (auto theta = min; theta <= max; theta += step) {
        printf("----------------------------------\n");
        printf("%.1lf\t\t|\t%.2lf\n", theta, range(theta));
    }
}