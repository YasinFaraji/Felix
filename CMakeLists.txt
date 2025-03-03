cmake_minimum_required(VERSION 3.10)
project(FelixRepairSystem)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SRC_FILES
    src/main.cpp
    src/felix.cpp
    src/shared_memory.cpp
)

include_directories(include)

add_executable(felix_repair ${SRC_FILES})

find_package(Threads REQUIRED)
target_link_libraries(felix_repair pthread)
