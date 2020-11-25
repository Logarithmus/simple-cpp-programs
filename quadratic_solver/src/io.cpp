#include "io.h"

#include <cmath>
#include <cstdio>

Coeff read_coeff() {
  Coeff coeff;
  printf("Enter coefficients:\n");
  printf("a = ");
  fflush(stdout);
  scanf("%lf", &coeff.a);
  printf("b = ");
  fflush(stdout);
  scanf("%lf", &coeff.b);
  printf("c = ");
  fflush(stdout);
  scanf("%lf", &coeff.c);
  printf("\n");
  return coeff;
}

void print_solution(const Coeff &coeff, const Solution &sol,
		    unsigned char equation_type) {
  switch (equation_type) {
  case 0b000: {
    printf("a = b = c = 0; x can be any number\n");
    break;
  }
  case 0b001: {
    printf("a = b = 0; this equation doesn't contain x\n");
    break;
  }
  case 0b010: {
    printf("a = c = 0; x = 0\n");
    break;
  }
  case 0b011: {
    printf("a = 0, solving linear equation %.2lfx%+.2lf = 0\n", coeff.b,
	   coeff.c);
    printf("x = -(c / b) = -(%.2lf / %.2lf) = %.2lf\n", coeff.c, coeff.b,
	   sol.x1);
    break;
  }
  case 0b100: {
    printf("b = c = 0; x = 0\n");
    break;
  }
  case 0b101: {
    printf("b = 0, solving quadratic equation %.2lfx^2%+.2lf = 0\n", coeff.a,
	   coeff.c);
    if (coeff.c < 0) {
      printf("x1 =  sqrt[-(c / a)] =  sqrt[-(%.2lf / %.2lf)] = %.2lf\n"
	     "x2 = -sqrt[-(c / a)] = -sqrt[-(%.2lf / %.2lf)] = %.2lf\n",
	     coeff.c, coeff.a, sol.x1, coeff.c, coeff.a, sol.x2);
    } else {
      printf("No real solutions, as c > 0\n");
    }
    break;
  }
  case 0b110: {
    printf("c = 0, solving quadratic equation %.2lfx^2 %+.2lfx = 0\n", coeff.a,
	   coeff.b);
    printf("Factor out x: x(%.2lfx%+.2lf) = 0\n", coeff.a, coeff.b);
    const double x = -(coeff.b / coeff.a);
    printf("x1 = 0; x2 = -(b / a) = %.2lf\n", x);
    break;
  }
  case 0b111: {
    printf("Solving quadratic equation %.2lfx^2 %+.2lfx %+.2lf = 0\n\n",
	   coeff.a, coeff.b, coeff.c);
    printf("D = b^2 - 4ac = %.2lf\n", sol.D);
    switch (sol.root_count) {
    case 0:
      printf("D < 0, no real roots\n");
      break;
    case 1:
      printf("D = 0, 1 real root\n\n"
	     "x = -b / (2a) = %.2lf\n",
	     sol.x1);
      break;
    case 2:
      printf("D > 0, 2 real roots\n\n"
	     "x1 = (-b + sqrt(D)) / (2a) = %.2lf\n"
	     "x2 = (-b - sqrt(D)) / (2a) = %.2lf\n",
	     sol.x1, sol.x2);
      break;
    }
    break;
  }
  }
}
