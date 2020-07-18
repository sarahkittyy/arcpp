# archivepp

![badge](https://github.com/sarahkittyy/arcpp/workflows/build/badge.svg)

A modern C++ interface over `libarchive`.

## Dependencies

* [libarchive](https://github.com/libarchive/libarchive)

## Building

1. Clone the repository: `git clone https://github.com/sarahkittyy/arcpp.git`
2. Enter the directory: `cd arcpp`
3. Update submodules: `git submodule update --init --recursive`
4. Build: `cd build && cmake .. && make`
    * You can enable / disable tests with `-DBUILD_TESTS=ON/OFF`
    
## Incorporating into a CMake project.

```cmake
add_subdirectory(arcpp)

...

target_link_libraries(target arcpp)
target_include_directories(target arcpp/include)
```

## Running the tests

Make sure you have `-DBUILD_TESTS=ON` enabled, and then

```bash
cd build
ctest
```

will run all the tests.

## Examples

### List the contents of an archive.
```cpp
using arcpp::archive;
archive ar;
ar.open("archive.tar");
for(auto iter = ar.files(); !iter.done(); iter.next()) {
    printf("%s\n", iter.get().path_name());
}
```

## Docs

Docs written using `doxygen` - See them at https://sarahkittyy.github.io/arcpp

## Implemented

* Opening and reading archives.
* Iterating over the contents of the archives.
* Reading the contents of each item in the archive.

## TODO

* Editing archives.
* Writing archives to file.
* Archive extraction.