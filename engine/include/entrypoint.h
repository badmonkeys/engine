#include <iostream>

// We take control of program entry to ensure proper initialization
int main() {
  Evo::Logger l("myLogger");

  auto app = Evo::createApplication();

  l.info("Press [ENTER] to exit...");
  std::cin.get();

  delete app;
}
