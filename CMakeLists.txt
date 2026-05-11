cmake_minimum_required(VERSION 3.10)

project(
  pikselim
  VERSION 0.1.0
  LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Ensure linux system is present
if(NOT CMAKE_SYSTEM_NAME STREQUAL "Linux")
  message(FATAL_ERROR "The engine only supports linux systems")
endif()
message(STATUS "Reconginsed linux system")

# Enable LTO/IPO support
# --------------------------------------------------
include(CheckIPOSupported)
check_ipo_supported(RESULT is_ipo_supported OUTPUT ipo_error)

if(is_ipo_supported)
  message(STATUS "IPO is supported")
else()
  message(WARNING "IPO is not supported. Error: ${ipo_error}")
endif()

function(enable_ipo target)
  if(is_ipo_supported)
    set_target_properties(${target} PROPERTIES 
      INTERPROCEDURAL_OPTIMIZATION_RELEASE TRUE
      INTERPROCEDURAL_OPTIMIZATION_RELWITHDEBINFO TRUE)
  endif()
endfunction()
# --------------------------------------------------

# If build type not specified and there is not entry in cache default to Debug
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type")
endif()
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")

# Enable sanitizers
# --------------------------------------------------
option(ENABLE_SANITIZERS "Enables ASan/UBSan/LSan" OFF)

function(enable_sanitizers target)
  if(ENABLE_SANITIZERS)
    target_compile_options(${target} PRIVATE 
      -fsanitize=address,undefined
      -fno-omit-frame-pointer)
    target_link_options(${target} PRIVATE
      -fsanitize=address,undefined)
  endif()
endfunction()
# --------------------------------------------------

add_subdirectory(engine)
add_subdirectory(sandbox)
