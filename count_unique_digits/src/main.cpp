#include <cmath>
#include <cstdio>
#include <type_traits>

template <typename T> unsigned count_unique_digits(T number) {
  static_assert(std::is_integral<T>::value,
		"Integer type required in function count_unique_digits()");
  if constexpr (std::is_signed<T>::value) {
    number = std::abs(number);
  }

  T initial_number = number, number_digit = 0;
  unsigned unique_digits_count = 0, digit_count = 0;
  for (T digit = 0; digit <= 9; ++digit) {
    digit_count = 0;
    do {
      number_digit = number % 10;
      digit_count += (number_digit == digit);
      number /= 10;
    } while (number > 0);
    unique_digits_count += (digit_count > 0);
    number = initial_number;
  }

  return unique_digits_count;
}

int main() {
  printf("Input number: ");
  fflush(stdout);
  int number = 0;
  scanf("%i", &number);
  printf("Unique digits count: %u\n", count_unique_digits(number));
  return 0;
}
