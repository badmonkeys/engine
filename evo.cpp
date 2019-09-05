#include <iostream>

#include <evo.h>

int main() {
  Evo::Logger l("myLogger");
  l.info("Press [ENTER] to exit...");
  std::cin.get();
}
