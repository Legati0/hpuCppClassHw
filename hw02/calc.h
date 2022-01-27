#ifndef CALC_H
#define CALC_H

// set "vars" of cannon & g
#define V0 250.0
#define M 30.0
#define CD 0.45
#define A 0.03
#define P 1.2
#define G 9.81

// delta t
#define DT 1.0

double calcDrag(double v);
double range(double theta);
void table(double min=0.0, double max=90.0, double step=5.0);

#endif  // CALC_H