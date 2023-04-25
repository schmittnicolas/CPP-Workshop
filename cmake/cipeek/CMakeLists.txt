add_executable(cipeek src/cipeek.cc)

target_compile_options(cipeek PRIVATE -Wall -Wextra -Werror -pedantic)
set_target_properties(cipeek PROPERTIES CXX_STANDARD 20 CXX_EXTENSIONS OFF)

add_dependencies(cipeek ciutils)
target_link_libraries(cipeek PRIVATE ciutils)