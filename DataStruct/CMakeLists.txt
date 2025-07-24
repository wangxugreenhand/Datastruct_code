cmake_minimum_required(VERSION 3.24)
project(DataStruct)

set(CMAKE_CXX_STANDARD 17)

add_executable(SeqStack SeqStack.h SeqStack.cpp)
add_executable(LinkStack LinkStack.h LinkStack.cpp)
add_executable(SeqQueue SeqQueue.h SeqQueue.cpp)
add_executable(LinkQueue LinkQueue.h LinkQueue.cpp)
add_executable(PQueue PQueue.h PQueue.cpp)
add_executable(Genlist Genlist.h Genlist.cpp)
add_executable(Tree Tree.h Tree.cpp Tree.h)
add_executable(Heap  Heap.h Heap.cpp)
add_executable(UFset  UFset.h UFset.cpp)