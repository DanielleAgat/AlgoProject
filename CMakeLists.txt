cmake_minimum_required(VERSION 3.17)
project(AlgoProject)

set(CMAKE_CXX_STANDARD 14)

add_executable(AlgoProject main.cpp Constants.h AdjMatrix.cpp AdjMatrix.h AdjList.cpp AdjList.h MinHeap.cpp MinHeap.h List.cpp List.h PriorityQueueHeap.h PriorityQueueArray.cpp PriorityQueueArray.h BfsHelper.h)