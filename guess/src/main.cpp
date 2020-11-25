#include "game.hpp"
#include "util.hpp"
#include <cstdio>
#include <cstdlib>
#include <ctime>

int main() {
  Interval interval;
  do {
    printf("Interval start: ");
	fflush(stdout);
    scanf("%i", &interval.start);
    printf("Interval end: ");
	fflush(stdout);
    scanf("%i", &interval.end);
    clear_screen();
  } while (interval.start >= interval.end);

  srand(static_cast<unsigned>(time(nullptr)));
  play_game(interval);

  return 0;
}
