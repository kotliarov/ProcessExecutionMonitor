cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 11)
find_package(Boost COMPONENTS)
message(status "** Boost Include: ${Boost_INCLUDE_DIR}")

include_directories(${Boost_INCLUDE_DIRS} include)
