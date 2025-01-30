cmake_minimum_required(VERSION 3.29)

project(quasi-one-dimensional LANGUAGES CXX)

# Стандарт C++
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)


# Исполняемый файл с указанием исходных файлов
add_executable(SolutionSLAU src/main.cpp
				src/DenseMatrix.cpp
				src/Band5Matrix.cpp 
				src/SLAUSolver.cpp
				src/LeastResidualMethod.cpp
				src/ConsoleApplication.cpp)
