#ifndef MULTABLE_UTIL_H
#define MULTABLE_UTIL_H

#include <cstdlib>

inline void clear_screen() {
#ifdef WINDOWS
  std::system("cls");
#else
  // Assume POSIX
  std::system("clear");
#endif
}

#endif // MULTABLE_UTIL_H
