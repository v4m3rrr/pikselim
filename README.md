# pikselim

_**pikselim**_ is a lightweight graphics engine based on its predecessor [_piksel_](https://github.com/v4m3rrr/piksel) (_im_ stands for _improved_) and is created specifically for basic 3D rendering. 

It is not intended for production use.

## Build

In order to build this repo you need to follow those steps:

### Build Requirements

- C++ compiler with C++20 support or higher (Clang preferred)
- CMake (version 3.10 or newer)
- Git
- vcpkg
- OpenGL drivers supporting at least OpenGL 4.6

### How to build it

```bash
git clone https://github.com/v4m3rrr/pikselim
cd pikselim
cmake --preset release
cmake --build --preset release
```

For more presets see CMakePresets.json file.

## License

Copyright (c) 2026  
Author: v4m3rrr

This project is licensed under the MIT License.  
See the `LICENSE` file for full details.

## Third-party dependencies

This project uses the following third-party libraries:
- GLFW (zlib/libpng license)
- GLAD (MIT license)
- GLM (The Happy Bunny license)
- spdlog (MIT license)
- fmt (MIT license)
- Khronos Group OpenGL specifications (Apache 2.0 license)

See THIRD\_PARTY\_LICENSES.txt for full license texts.
