# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.


cmake_minimum_required(VERSION 3.5)

# change this project name to your project.
project(cxx17-lib CXX)

message( "\n${PROJECT_NAME} Lib")
message( "-----------------------------")
message(STATUS "${PROJECT_NAME} LIB DIR:${CMAKE_CURRENT_SOURCE_DIR}")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})
set(ABSL_PROPAGATE_CXX_STD ON)


# If you want to add dependency lib
# please change LIB_MAIN to anoother unique name for the dependency lib
# on the dependency lib CMakeLists.txt.
# on each CMAKE declare unique variable
# Eg: LIB_DAC on dependency lib

option(LIB_MAIN_BUILD_DOC "Build documentation" ON)
option(LIB_MAIN_SANITIZE_ADDRESS "SANITIZE ADDRESS" ON)
option(LIB_MAIN_USE_CATCH ON)
option(LIB_MAIN_USE_LIB ON)
option(LIB_MAIN_USE_TEST ON)

# Changes this value to turn off or turn on feature
set(LIB_MAIN_BUILD_DOC OFF)
set(LIB_MAIN_SANITIZE_ADDRESS ON)
set(LIB_MAIN_USE_CATCH ON)
set(LIB_MAIN_USE_LIB OFF)
set(LIB_MAIN_USE_TEST ON)

if(LIB_MAIN_SANITIZE_ADDRESS)
    set(SANITIZE_ADDRESS ON)
endif(LIB_MAIN_SANITIZE_ADDRESS)

# Doxygen setting
if(LIB_MAIN_BUILD_DOC)
    if(NOT DOXYGEN_FOUND)
        find_package(Doxygen)
    endif()

    if (DOXYGEN_FOUND)
        # set input and output files
        set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in)
        set(DOXYGEN_OUT ${CMAKE_CURRENT_SOURCE_DIR}/generated/docs-cached/Doxyfile)

        # request to configure the file
        configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
        message("Doxygen build started")

         # note the option ALL which allows to build the docs together with the application
        add_custom_target( doc_nvmcommon ALL
            COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/generated/docs-cached/
            COMMENT "Generating API documentation with Doxygen"
            VERBATIM )
    else (DOXYGEN_FOUND)
        message("Doxygen need to be installed to generate the doxygen documentation")
    endif (DOXYGEN_FOUND)
endif(LIB_MAIN_BUILD_DOC)

# Add subdirectory to be configure and build using CMAKE
add_subdirectory(deps/abseil-lts.20230802.1 build-abseil)

# example if you have deps lib name daclib
#add_subdirectory(deps/daclib build-daclib)

# Catch2 for unit test
 if(LIB_MAIN_USE_CATCH)
    message(STATUS  "CATCH2::ADD_LIB.")
    find_package(Catch2 3 REQUIRED)
endif()


#  make ourself sanitize and sane well.
if(NOT Sanitizers_FOUND)
 find_package(Sanitizers)
endif()

# automatic list all headers, sources and assembly files
# Header files must be inside /inc/*.h
# Source files must be inside /src/*.cc
# Assembly files must be inside /src/*.s
file(GLOB_RECURSE SOURCES_TRAXROUTE CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/inc/*.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.s
)

# add our project as static lib
add_library(${PROJECT_NAME} ${SOURCES_TRAXROUTE} )

# linking our lib to abseil
target_link_libraries(${PROJECT_NAME} 
    absl::base 
    absl::flat_hash_map 
    absl::algorithm
    absl::numeric
    absl::random_random
    absl::synchronization 
    absl::strings
    absl::time
    absl::utility)

# tell the compiler if we want compile for C++ 17
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)

# Include header location
target_include_directories(${PROJECT_NAME}
    PUBLIC
        inc/
)

# Create an executable files
add_executable(${PROJECT_NAME}-app main.cc)

target_link_libraries(${PROJECT_NAME}-app PRIVATE  ${PROJECT_NAME} )
target_include_directories("${PROJECT_NAME}-app"
    PUBLIC
        inc/
)

# Comment this when you build for release
if(Sanitizers_FOUND)
    add_sanitizers("${PROJECT_NAME}-app")
    message(STATUS "${PROJECT_NAME}-app_LIB::ASAN:ON.")
endif()

# Build the test
if(LIB_MAIN_USE_TEST)
    message(STATUS "TEST::ADD_UNIT_TEST.")
    add_subdirectory(tests/cxx17 build-cxx17-test)
endif()       

message(STATUS "${PROJECT_NAME} Configuration Done!\n")
set(traxroute_FOUND  ON)