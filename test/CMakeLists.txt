cmake_minimum_required(VERSION 3.10)
project(BoostGILExample)

# Find Boost
find_package(Boost REQUIRED)

# Find PNG
find_package(PNG REQUIRED)

# Include directories
include_directories(${Boost_INCLUDE_DIRS} ${PNG_INCLUDE_DIRS})

# Add the executable
add_executable(BoostGILExample main.cpp)

# Link libraries
target_link_libraries(BoostGILExample ${PNG_LIBRARIES})
