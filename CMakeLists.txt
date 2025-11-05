cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 20)

project(CplusplusProject CXX)

# gather common cpp files used by all modules
file(GLOB_RECURSE COMMON_SOURCES
    DataStructures/*.cpp
    HelperFunctions/*.cpp
)

# change this number, auto builds more modules
set(NUM_MODULES 3)

foreach(i RANGE 1 ${NUM_MODULES})
    set(MODULE_NAME "Module${i}")
    set(MAIN_CPP "${MODULE_NAME}/main.cpp")

    # only add target if the folder actually exists
    if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/${MAIN_CPP}")
        add_executable(${MODULE_NAME} ${MAIN_CPP} ${COMMON_SOURCES})
        target_include_directories(${MODULE_NAME} PRIVATE DataStructures HelperFunctions)
    endif()
endforeach()
