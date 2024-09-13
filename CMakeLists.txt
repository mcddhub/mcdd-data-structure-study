cmake_minimum_required(VERSION 3.28)
project(mcdd-data-structure-study C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 20)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/.archive)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/.library)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/.runtime)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/.runtime)
set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/.library)

file(GLOB_RECURSE files src/**/*.c src/**/*.cpp src/*.c src/*.cpp)
foreach (file ${files})
    string(REGEX REPLACE ".+/(.+)\\..*" "\\1" exe ${file})
    add_executable(${exe} ${file})
    #    message(\ \ \ \ --\ \[${exe}\]\ will\ be\ compiled\ to\ \'.runtime/${exe}.exe\') # DEBUG 编译信息
endforeach ()