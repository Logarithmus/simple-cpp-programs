#include "solver.h"

#include <cmath>

unsigned char resolve_equation_type(const Coeff &coeff) {
  const double EPSILON = 1e-14;
  unsigned char equation_type = 0b000;

  if (std::abs(coeff.a) > EPSILON)
    equation_type |= 0b100;
  if (std::abs(coeff.b) > EPSILON)
    equation_type |= 0b010;
  if (std::abs(coeff.c) > EPSILON)
    equation_type |= 0b001;

  return equation_type;
}

double discriminant(const Coeff &coeff) {
  return coeff.b * coeff.b - 4 * coeff.a * coeff.c;
}

Solution solve_ordinary_quadratic(const Coeff &coeff) {
  const double EPSILON = 1e-14;

  const double D = discriminant(coeff);
  if (std::abs(D) < EPSILON) {
    return {D, -coeff.b / (2 * coeff.a), -coeff.b / (2 * coeff.a), 1};
  } else if (D > 0) {
    return {D, (-coeff.b + std::sqrt(D)) / (2 * coeff.a),
	    (-coeff.b - std::sqrt(D)) / (2 * coeff.a), 2};
  }
  return {D, 0, 0, 0};
}

Solution solve_quadratic(const Coeff &coeff) {
  auto equation_type = resolve_equation_type(coeff);

  switch (equation_type) {
  case 0b000:
  case 0b001:
  case 0b010:
    return {0, 0, 0, 0};
  case 0b011:
    return {0, -coeff.c / coeff.b, 0, 1};
  case 0b100:
    return {0, 0, 0, 0};
  case 0b101: {
    const auto x = std::sqrt(-coeff.c / coeff.a);
    return {0, x, -x, 2};
  }
  case 0b110:
    return {0, 0, -coeff.b / coeff.a, 2};
  case 0b111:
    return solve_ordinary_quadratic(coeff);
  default:
    return {0, 0, 0, 0};
  }
}
