cmake_minimum_required(VERSION 3.21.2)

project(my_cmake)

find_library(YAMLCPP_LIB NAMES yaml-cpp REQUIRED)
add_subdirectory(cipeek)


add_library(ciutils SHARED src/ciutils.cc)

target_compile_options(ciutils PRIVATE -Wall -Werror -Wextra -pedantic)

set_target_properties(ciutils  PROPERTIES CXX_STANDARD 20 CXX_EXTENSIONS OFF)

target_include_directories(ciutils PUBLIC include)
target_link_libraries(ciutils PRIVATE ${YAMLCPP_LIB})