#include "app.h"

App::App() {
  logger = std::make_unique<Evo::Logger>("App");
  logger->info("App initialized");
}

App::~App() {
  logger->info("App destroyed");
}

Evo::Application* Evo::createApplication() {
  return new App();
}
