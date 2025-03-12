cmake_minimum_required(VERSION 3.19)
project(v8-hello-world)

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_compile_definitions(V8_COMPRESS_POINTERS DEBUG)

add_executable(v8_api v8_api.cc)
target_include_directories(v8_api PRIVATE
        /Users/adam/opensource/v8
        /Users/adam/opensource/v8/v8/include
        )
target_link_libraries(v8_api PRIVATE
        /Users/adam/opensource/v8/v8/out.gn/x64.static.debug.noinline/obj/libv8_monolith.a
        )
