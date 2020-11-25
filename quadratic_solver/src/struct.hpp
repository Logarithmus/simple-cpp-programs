#ifndef QUADRATIC_SOLVER_STRUCT_H
#define QUADRATIC_SOLVER_STRUCT_H

struct Coeff {
  double a, b, c;
};

struct Solution {
  double D, x1, x2;
  unsigned char root_count;
};

#endif // QUADRATIC_SOLVER_STRUCT_H
