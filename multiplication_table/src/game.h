#ifndef MULTABLE_GAME_H
#define MULTABLE_GAME_H

bool ask_mult_result(unsigned a, unsigned b, unsigned ask_times);
void print_mult_table(unsigned a);
bool handle_game_end(bool is_correct, unsigned trials_count);

#endif // MULTABLE_GAME_H
