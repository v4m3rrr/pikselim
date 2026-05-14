cmake_minimum_required(VERSION 3.28)

project(
  pikselim
  VERSION 0.1.0
  LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# clang pthread fix
set(CMAKE_THREAD_LIBS_INIT "-lpthread")
set(CMAKE_HAVE_THREADS_LIBRARY 1)
set(CMAKE_USE_PTHREADS_INIT 1)
set(THREADS_PREFER_PTHREAD_FLAG OFF)

# Ensure linux system is present
if(NOT CMAKE_SYSTEM_NAME STREQUAL "Linux")
  message(FATAL_ERROR "The engine only supports linux systems")
endif()
message(STATUS "Recognized linux system")

# If build type not specified and there is not entry in cache default to Debug
if(NOT CMAKE_BUILD_TYPE)
  message(FATAL_ERROR 
    "Build type not specified. Please use presets from CMakePresets.json")
endif()
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")

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

# Enable docs
# --------------------------------------------------
option(BUILD_DOC "Build documentation" ON)

if(BUILD_DOC)
find_package(Doxygen COMPONENTS doxygen dot)
  if(DOXYGEN_FOUND)
    set(DOXYGEN_USE_MDFILE_AS_MAINPAGE "${CMAKE_CURRENT_SOURCE_DIR}/README.md")
    set(DOXYGEN_EXTRACT_ALL YES)
    set(DOXYGEN_FILE_PATTERNS *.cc *.cxx *.cpp *.c *.hh *.hxx *.hpp *.h)
    set(DOXYGEN_SOURCE_BROWSER YES)
    doxygen_add_docs(
      engine-docs
      ${CMAKE_CURRENT_SOURCE_DIR}/engine/src
      ${CMAKE_CURRENT_SOURCE_DIR}/engine/include
      ${CMAKE_CURRENT_SOURCE_DIR}/README.md
      ALL
      COMMENT "Building documentation")
  else()
    message(WARNING 
      "Doxygen executable was not found. Documention will not be built")
  endif()
endif()


add_subdirectory(engine)
add_subdirectory(sandbox)
