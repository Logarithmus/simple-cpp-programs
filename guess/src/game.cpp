#include "game.hpp"

#include <cstdio>
#include <cstdlib>
#include <ctime>

int generate_rand_from_interval(Interval interval) {
  int len = interval.end - interval.start + 1;
  return interval.start + (rand() % len);
}

int read_attempt(Interval interval) {
  printf("Input number from the interval [%i; %i]: ", interval.start,
	 interval.end);
  fflush(stdout);
  int attempt = 0;
  scanf("%i", &attempt);
  return attempt;
}

Interval reduce_interval(Interval interval, int number, int attempt) {
  if (attempt > number) {
    return {interval.start, std::min(attempt, interval.end)};
  } else {
    return {std::max(attempt, interval.start), interval.end};
  }
}

void play_game(Interval interval) {
  int number = generate_rand_from_interval(interval);

  int attempt = read_attempt(interval);
  unsigned attempts_count = 0;
  while (attempt != number) {
    interval = reduce_interval(interval, number, attempt);
    attempt = read_attempt(interval);
    ++attempts_count;
  }

  printf("It took you %i attempt(s) to guess!\n", attempts_count);
}
