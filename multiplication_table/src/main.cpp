#include "game.h"
#include <cstdio>
#include <cstdlib>
#include <ctime>

int main() {
  const unsigned MAX_TRIALS = 3;
  srand(static_cast<unsigned>(time(nullptr)));

  while (true) {
    unsigned a = rand() % 10 + 1, b = rand() % 10 + 1;

    bool is_correct = ask_mult_result(a, b, MAX_TRIALS);
    unsigned trials_count;
    for (trials_count = 1; !is_correct && (trials_count < MAX_TRIALS);
	 ++trials_count) {
      print_mult_table(a);
      is_correct = ask_mult_result(a, b, MAX_TRIALS);
    }

    if (!handle_game_end(is_correct, trials_count)) {
      return 0;
    }
  }
}
