#ifndef QUADRATIC_SOLVER_IO_H
#define QUADRATIC_SOLVER_IO_H

#include "struct.h"

Coeff read_coeff();
void print_solution(const Coeff &coeff, const Solution &sol,
		    unsigned char equation_type);

#endif // QUADRATIC_SOLVER_IO_H
