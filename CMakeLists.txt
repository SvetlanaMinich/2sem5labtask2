cmake_minimum_required(VERSION 3.23)
project(deque)

set(CMAKE_CXX_STANDARD 20)

add_executable(deque main.cpp DequeIterator.cpp DequeIterator.h MyDeque.cpp MyDeque.h Node.h)
