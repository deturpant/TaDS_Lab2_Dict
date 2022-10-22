cmake_minimum_required(VERSION 3.23)
project(TaDS_Lab2)

set(CMAKE_CXX_STANDARD 17)

add_executable(TaDS_Lab2 src/main.cpp src/Menu/MenuItem.h src/Menu/MenuItem.cpp src/BinTree/BinTree.cpp src/BinTree/BinTree.h src/BinTree/Node.cpp src/BinTree/Node.h src/Menu/MyMenu.cpp src/Menu/MyMenu.h src/Exceptions/MyException.h src/Exceptions/MyException.cpp)
