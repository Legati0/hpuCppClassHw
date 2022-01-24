#include <cstdio>
#include <cmath>
#include "calc.h"

double calcDrag(double v) {
    return 0.5 * CD * A * P * v * v / M;
}
double range(double theta) {
    theta *= M_PI / 180.0;
    double x, y = 0.0;
    double vx = V0 * cos(theta);
    double vy = V0 * sin(theta);
    const double dt = 1;
    do {
        x += vx * dt;
        y += vy * dt;
        const double v = sqrt(vx * vx + vy * vy);
        const double drag = calcDrag(v);
        vx += -drag * vx / v;
        vy += G - drag * vy / v;
    } while(y > 0.0);
    return x;
}
void table(double min, double max, double step) {
    printf("Theta\t|\tRange\n");
    for (auto theta = min; theta <= max; theta += step) {
        printf("-------------------------\n");
        printf("%.1lf\t|\t%.2lf\n", theta, range(theta));
    }
}