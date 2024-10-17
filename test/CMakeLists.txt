# cmake version
cmake_minimum_required(VERSION 3.5)

# project name
project(test)

# add the test.cpp file
add_executable(test test.cpp)

# import the static myPhysicsLibrary
add_library(myPhysicsLibraryStatic STATIC IMPORTED)
set_target_properties(myPhysicsLibraryStatic PROPERTIES IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/../package/lib/libsomeBasicPackage.a)

# import the static electronInElectromagneticFieldLibrary
add_library(electronInElectromagneticFieldLibraryStatic STATIC IMPORTED)
set_target_properties(electronInElectromagneticFieldLibraryStatic PROPERTIES IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/../electronInElectromagneticField/lib/libelectronInElectromagneticField.a)

# link the libraries
target_link_libraries(test electronInElectromagneticFieldLibraryStatic myPhysicsLibraryStatic)

# link the gsl library
target_link_libraries(test gsl gslcblas)

# Optimization flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2")
