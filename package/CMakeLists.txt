# cmake verison
cmake_minimum_required(VERSION 3.5)

# project name
project(myPhysicsPackage)

# get all subdirectories in the source directory
file(GLOB children RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}/src ${CMAKE_CURRENT_SOURCE_DIR}/src/*)
file(GLOB includes RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}/src ${CMAKE_CURRENT_SOURCE_DIR}/include/*)

# add the include directories
foreach(child ${includes})
    if(IS_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/${child})
        include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/${child})
    endif()
endforeach()

# init the list of all source files
set(all_sources "")

# add the source files
foreach(child ${children})
    if(IS_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/src/${child})
        file(GLOB_RECURSE sources ${CMAKE_CURRENT_SOURCE_DIR}/src/${child}/*.cpp)
        list(APPEND all_sources ${sources})
    endif()
endforeach()

# print the source files
message(STATUS "Source files: ${all_sources}")

# add the static library
add_library(myPhysicsLibraryStatic STATIC ${all_sources})

# add the dynamic library
add_library(myPhysicsLibraryShared SHARED ${all_sources})

# set the output directory
set_target_properties(myPhysicsLibraryStatic PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib OUTPUT_NAME someBasicPackage)
set_target_properties(myPhysicsLibraryShared PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib OUTPUT_NAME someBasicPackage)

# link the gsl library
target_link_libraries(myPhysicsLibraryStatic gsl gslcblas)
target_link_libraries(myPhysicsLibraryShared gsl gslcblas)

# Optimization flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2")
