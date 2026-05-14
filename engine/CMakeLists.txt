add_library(pikselim STATIC)

target_sources(pikselim PRIVATE
  src/core/app.cc)

add_library(pikselim::pikselim ALIAS pikselim)

target_include_directories(pikselim PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_compile_options(pikselim PRIVATE
  -Wall -Wextra -Wpedantic
)

enable_ipo(pikselim)

find_package(glfw3 CONFIG REQUIRED)
target_link_libraries(pikselim PRIVATE glfw)

find_package(glad CONFIG REQUIRED)
target_link_libraries(pikselim PRIVATE glad::glad)

find_package(glm CONFIG REQUIRED)
target_link_libraries(pikselim PRIVATE glm::glm)

find_package(spdlog CONFIG REQUIRED)
target_link_libraries(pikselim PRIVATE spdlog::spdlog)
