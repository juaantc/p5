cmake_minimum_required(VERSION 3.20)

# Definimos el nombre del proyecto
project(p5)

# Estándar C++20 obligatorio
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Habilitar tests
enable_testing()

# Añadir los subdirectorios principales
add_subdirectory(src)
add_subdirectory(tests)
