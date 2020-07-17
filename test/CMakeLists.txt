project(arcpp)

file(GLOB_RECURSE sources "*.cpp")

add_executable(arcpp_test ${sources})
add_dependencies(arcpp_test arcpp)
target_include_directories(arcpp_test PUBLIC
	"${CMAKE_SOURCE_DIR}/lib/catch2"
	"${CMAKE_SOURCE_DIR}/include"
)
target_link_libraries(arcpp_test arcpp)