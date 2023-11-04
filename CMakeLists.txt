cmake_minimum_required(VERSION 3.20 FATAL_ERROR)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(parlay_issues)

# Generate compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "")

add_executable(nogrow_upsert src/nogrow_upsert.cpp)
add_executable(nogrow_corrupt src/nogrow_corrupt.cpp)
add_executable(grow_upsert src/grow_upsert.cpp)

target_include_directories(nogrow_upsert SYSTEM PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/parlayhash/include)
target_include_directories(nogrow_corrupt SYSTEM PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/parlayhash/include)
target_include_directories(grow_upsert SYSTEM PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/parlayhash/include)
