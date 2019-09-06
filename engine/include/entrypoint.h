#include <memory>
#include <iostream>

#include "framework.h"

// We take control of program entry to ensure proper initialization
int main() {
  std::shared_ptr<Evo::Framework> framework = Evo::Framework::get();
  auto app = Evo::createApplication();

  framework->load(app);

  framework->exec();

  framework->shutdown();

  delete app;

  return 0;
}
