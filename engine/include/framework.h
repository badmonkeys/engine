#pragma once

namespace Evo {
  class Framework {
    public:
      static std::shared_ptr<Framework> get() {
        static std::shared_ptr<Framework> _instance;
        return _instance;
      }

     bool load(Evo::Application*) {}
     bool exec() {}
     bool shutdown() {}


    private:
      Framework();
      ~Framework();
      Framework(const Framework&) = delete;
      void operator=(const Framework&) = delete;

  };
}
