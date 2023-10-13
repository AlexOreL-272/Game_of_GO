#ifndef UTIL_H
#define UTIL_H

#include <iostream>
#include <cstdlib>

void _assertNotNull(void *obj, std::ostream out = std::cerr) {
  if (obj == NULL) {
    out << "Объект " << obj << " является пустым." << std::endl;

    exit(700);
  }
}

#endif // UTIL_H
