add_executable(sandbox
  src/main.cc)

target_link_libraries(sandbox PRIVATE pikselim::engine)

target_compile_options(sandbox PRIVATE
  -Wall -Wpedantic -Wextra)

enable_sanitizers(sandbox)
enable_ipo(sandbox)
