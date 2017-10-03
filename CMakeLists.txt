cmake_minimum_required(VERSION 3.7)
project(numbersToBraille)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES UnitTests/main.c UnitTests/cellsFactory.c braille.c)
add_executable(numbersToBraille ${SOURCE_FILES})