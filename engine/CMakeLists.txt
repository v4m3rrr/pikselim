add_library(engine STATIC)

target_sources(engine PRIVATE
  src/core/app.cc)

add_library(pikselim::engine ALIAS engine)

target_include_directories(engine PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_compile_options(engine PRIVATE
  -Wall -Wextra -Wpedantic
)

enable_ipo(engine)



