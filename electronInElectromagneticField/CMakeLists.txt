# cmake version
cmake_minimum_required(VERSION 3.5)

# project name
project(electronInElectromagneticField)

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

# import the static myPhysicsLibrary
add_library(myPhysicsLibraryStatic STATIC IMPORTED)
set_target_properties(myPhysicsLibraryStatic PROPERTIES IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/../package/lib/libsomeBasicPackage.a)

# import the shared myPhysicsLibrary
add_library(myPhysicsLibraryShared SHARED IMPORTED)
set_target_properties(myPhysicsLibraryShared PROPERTIES IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/../package/lib/libsomeBasicPackage.so)

# print the source files
message(STATUS "Source files: ${all_sources}")

# add the static library
add_library(electronInElectromagneticFieldLibraryStatic STATIC ${all_sources})

# add the dynamic library
add_library(electronInElectromagneticFieldLibraryShared SHARED ${all_sources})

# set the output directory
set_target_properties(electronInElectromagneticFieldLibraryStatic PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib OUTPUT_NAME electronInElectromagneticField)
set_target_properties(electronInElectromagneticFieldLibraryShared PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib OUTPUT_NAME electronInElectromagneticField)

# link the libraries
target_link_libraries(electronInElectromagneticFieldLibraryStatic myPhysicsLibraryStatic)
target_link_libraries(electronInElectromagneticFieldLibraryShared myPhysicsLibraryShared)
