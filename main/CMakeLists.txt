cmake_minimum_required(VERSION 3.10)
project(MyProject)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the include directory
include_directories(${PROJECT_SOURCE_DIR}/inc)

# Specify the source files
set(SOURCES
    src/bitWriter.cpp
    src/fileData.cpp
    src/main.cpp
    src/unzipify.cpp
    src/zipify.cpp
)

# Add the Boost library
find_package(Boost REQUIRED COMPONENTS serialization)
if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    add_definitions(-DBOOST_ALL_NO_LIB) # To avoid auto-linking on some platforms
endif()

# Set the build types
set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Available build types" FORCE)

# Add the executable
add_executable(MyExecutable ${SOURCES})

# Link against Boost libraries
target_link_libraries(MyExecutable ${Boost_LIBRARIES})

# Custom targets for Debug and Release builds
add_custom_target(debug
    COMMAND ${CMAKE_COMMAND} -DCMAKE_BUILD_TYPE=Debug ${CMAKE_SOURCE_DIR}
    COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --config Debug
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)

add_custom_target(release
    COMMAND ${CMAKE_COMMAND} -DCMAKE_BUILD_TYPE=Release ${CMAKE_SOURCE_DIR}
    COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --config Release
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)
