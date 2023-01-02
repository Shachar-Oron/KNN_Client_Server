cmake_minimum_required(VERSION 3.23)
project(ap_ex2_new)

set(CMAKE_CXX_STANDARD 11)

add_executable(ap_ex2_new main.cpp LoadData.cpp LoadData.h DistancesCalcolators.cpp DistancesCalcolators.h Helpers.cpp Helpers.h Knn.cpp Knn.h StructHeader.h StructHeader.cpp Client.h)
