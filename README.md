<img src="https://github.com/rstdfisg/soft-body/blob/main/demo.gif" width=50% height=50%>

## Required

- CMAKE
- [MinGW](https://www.sfml-dev.org/download/sfml/2.5.1/)
- [SFML 2.5.1](https://www.sfml-dev.org/download/sfml/2.5.1/)

*Note: The SFML version and the compiler should both be downloaded from the official SFML website, ensuring compatibility between the SFML version and the compiler version.*


## Build (windows)

```bash
# bash 

mkdir build/
cd build
cmake .. -G "MinGW Makefiles" -D CMAKE_BUILD_TYPE=Release
# cmake .. -G "MinGW Makefiles" -D CMAKE_BUILD_TYPE=Debug

cmake --build .
```


The default location of SFML header files is `C:/SFML-2.5.1/include/`, but this could be changed by your environment settings.
```cmake
set(SFML_HEADER_DIR "C:/SFML-2.5.1/include/")
```
