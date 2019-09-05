project(evoengine)

set(evoengine_SOURCES
  src/logger.cpp
)

add_library(evoengine
  SHARED
  ${evoengine_SOURCES}
)

target_include_directories(evoengine
  PUBLIC include
  PRIVATE src
)
