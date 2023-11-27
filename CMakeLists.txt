cmake_minimum_required(VERSION 3.27)

project(calculoPropriedadesReologicas)

set(CMAKE_BUILD_TYPE Release)

include_directories(src)

add_subdirectory(src)

set_property(TARGET  calculoPropriedadesReologicas  PROPERTY CXX_STANDARD 23)
