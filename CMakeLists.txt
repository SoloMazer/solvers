cmake_minimum_required(VERSION 3.28)
project(Solvers)

set(CMAKE_CXX_STANDARD 20)

# Following lines will enforce CPP standard, disable compiler extensions, set warning levels to max and treat warnings as errors.
# This is to ensure code compatibility on various devices, usage of acceptable coding practices.
# https://www.learncpp.com/cpp-tutorial/configuring-your-compiler-compiler-extensions/#comment-582925
# https://www.learncpp.com/cpp-tutorial/configuring-your-compiler-warning-and-error-levels/#comment-588846
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
#Comment out next line if its too annoying.
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror -Wall -Weffc++ -Wextra -Wconversion -Wsign-conversion")

add_executable ( Solvers 
   "bisection.cpp"
)

