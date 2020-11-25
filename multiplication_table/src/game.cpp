#include "game.h"

#include "util.h"
#include <cstdio>

bool ask_mult_result(unsigned a, unsigned b, unsigned ask_times) {
  unsigned result = 0;
  for (unsigned i = 0; i < ask_times; ++i) {
    printf("How much is %u x %u?\n", a, b);
    scanf("%u", &result);
    getchar(); // get rid of newline left in stdin
    if (result == a * b) {
      break;
    } else {
      printf("Incorrect! Press ENTER to try again.\n");
      getchar();
      clear_screen();
    }
  }
  return result == a * b;
}

void print_mult_table(unsigned a) {
  printf("It's time to refresh your knowledge: \n\n");
  for (unsigned b = 1; b <= 10; ++b) {
    printf("%u x %u = %u\n", a, b, a * b);
  }
  printf("Press ENTER whenever you are ready\n");
  getchar();
  clear_screen();
}

bool handle_game_end(bool is_correct, unsigned trials_count) {
  if (is_correct) {
    if (trials_count == 1) {
      printf("Good! Your answer is correct\n");
    } else {
      printf("This time the answer is correct\n");
    }
    printf("Press ENTER to play again\n");
    getchar();
    clear_screen();
    return true;
  } else {
    printf("You're either very tired, or very stupid.\n"
	   "Anyway, take a break. See ya again!\n");
    return false;
  }
}
