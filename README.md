## Required

- MinGW
- CMAKE
- SFML 2.5.1

## Build (windows)

```bash
# bash 

mkdir build/
cd build
cmake .. -G "MinGW Makefiles" -D CMAKE_BUILD_TYPE=Release
# cmake .. -G "MinGW Makefiles" -D CMAKE_BUILD_TYPE=Debug

cmake --build .
```
