#include "io.hpp"
#include "solver.hpp"
#include <cmath>
#include <cstdio>

int main() {
  printf("Quadratic equation solver (for real numbers)\n"
	 "ax^2 + bx + c = 0\n");

  Coeff coeff = read_coeff();
  const auto equation_type = resolve_equation_type(coeff);
  const Solution sol = solve_quadratic(coeff);
  print_solution(coeff, sol, equation_type);
  solve_ordinary_quadratic(coeff);
  return 0;
}
