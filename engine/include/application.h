#pragma once

namespace Evo {
  class Application {
    public:
      Application() {}
      virtual ~Application() {}
  };

  // To be defined by the client application
  Evo::Application* createApplication();
}
