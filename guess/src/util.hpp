#ifndef GUESS_UTIL_HPP
#define GUESS_UTIL_HPP

#include <cstdlib>

inline void clear_screen() {
#ifdef WINDOWS
  std::system("cls");
#else
  // Assume POSIX
  std::system("clear");
#endif
}

#endif // GUESS_UTIL_HPP
