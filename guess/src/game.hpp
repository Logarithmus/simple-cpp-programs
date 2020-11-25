#ifndef GUESS_GAME_HPP
#define GUESS_GAME_HPP

#include <algorithm>
#include <cstdio>
#include <cstdlib>

struct Interval {
  int start, end;
};

int generate_rand_from_interval(Interval interval);
int read_attempt(Interval interval);
Interval reduce_interval(Interval interval, int number, int attempt);
void play_game(Interval interval);

#endif // GUESS_GAME_HPP
