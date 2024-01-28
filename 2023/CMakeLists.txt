cmake_minimum_required(VERSION 3.20)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_COMPILER "g++")

project(AOC)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR}/build/debug)

# Define the range of problem numbers
set(DAYS_START 1)
set(DAYS_END 25)

# Generate the list of problem numbers within the range
math(EXPR DAY_END "${DAYS_END} + 1") # To include DAY_END itself
foreach(DAY RANGE ${DAYS_START} ${DAYS_END})
    if(${DAY} LESS 10)
        set(DAY_ZERO "0${DAY}")
    else()
        set(DAY_ZERO "${DAY}")
    endif()
    
    set(DAY_DIR "${CMAKE_SOURCE_DIR}/day${DAY_ZERO}")
    foreach(PART RANGE 1 2)
        file(GLOB DAY_SOURCES "${DAY_DIR}/d${DAY_ZERO}p${PART}.cpp")

        if(DAY_SOURCES)
            set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${DAY_DIR})
        set(TARGET_NAME "d${DAY_ZERO}p${PART}")
            
            add_executable(${TARGET_NAME} ${DAY_SOURCES})
        endif()
    endforeach()
endforeach()
