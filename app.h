#include <evo.h>

class App : public Evo::Application {
  public:
    App();
    ~App();

  private:
    std::unique_ptr<Evo::Logger> logger;
};
