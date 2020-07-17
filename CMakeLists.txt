cmake_minimum_required(VERSION 3.13)
project(arcpp)

include(FindLibArchive)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE sources "src/*.cpp")

option(BUILD_TESTS "Build the library tests")
if(BUILD_TESTS)
	add_subdirectory("test")
	enable_testing()
endif()

add_library(arcpp ${sources})
target_include_directories(arcpp PUBLIC
	"include/"
)
target_compile_options(arcpp PUBLIC -Wall)
target_link_libraries(arcpp
	LibArchive::LibArchive
)

add_test(NAME AllTests COMMAND arcpp_test)