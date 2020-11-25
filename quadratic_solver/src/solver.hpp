#ifndef QUADRATIC_SOLVER_SOLVER_H
#define QUADRATIC_SOLVER_SOLVER_H

#include "struct.hpp"

unsigned char resolve_equation_type(const Coeff &coeff);
double discriminant(const Coeff &coeff);
Solution solve_ordinary_quadratic(const Coeff &coeff);
Solution solve_quadratic(const Coeff &coeff);

#endif // QUADRATIC_SOLVER_SOLVER_H
