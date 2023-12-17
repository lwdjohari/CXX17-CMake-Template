cmake_minimum_required(VERSION 3.5)
project(cxx17-lib-test CXX)

# Set the path to the directory containing the Catch2 header files

# Add the Catch2 library
# add_library(Catch2 INTERFACE)
# target_include_directories(Catch2 INTERFACE ${CATCH_INCLUDE_DIR})

# Set the path to the directory containing your test source files
set(TEST_SOURCES

    test_01/HelloWorldTest.cc
    # Add more test files if needed
)

if(NOT Catch2_FOUND)
    message(STATUS "CATCH2::ADD_LIB.")
    find_package(Catch2 3 REQUIRED)
endif()


# Create an executable for the tests
add_executable(${PROJECT_NAME} ${TEST_SOURCES})

# Add Include location
target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/
)

# Link the Catch2 library to the test executable
target_link_libraries(${PROJECT_NAME} PUBLIC Catch2::Catch2WithMain cxx17-lib)

# Set the C++ standard
set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
)