cmake_minimum_required(VERSION 3.27)
project(datastructure_master)

set(CMAKE_CXX_STANDARD 14)

include_directories(DataStructure-master/Graph/cpp)

add_executable(datastructure_master
        DataStructure-master/Graph/C/AdjacencyListGraph.c
        DataStructure-master/Graph/C/AdjacencyMatrixGraph.c
        DataStructure-master/Graph/C/Dijkstra.c
        DataStructure-master/Graph/C/Floyd.c
        DataStructure-master/Graph/C/Kruskal.c
        DataStructure-master/Graph/C/Prim.c
        DataStructure-master/Graph/C/TopLogicalSort.c
        DataStructure-master/Graph/cpp/CycleDetection.h
        DataStructure-master/Graph/cpp/DenseGraph.h
        DataStructure-master/Graph/cpp/GraphReader.h
        DataStructure-master/Graph/cpp/main.cc
        DataStructure-master/Graph/cpp/PathSearcher.h
        DataStructure-master/Graph/cpp/ShortestPathSearcher.h
        DataStructure-master/Graph/cpp/SparseGraph.h
        DataStructure-master/LinearList/DoubleLinkList.c
        DataStructure-master/LinearList/LoopDoubleLinkList.c
        DataStructure-master/LinearList/LoopSingleLinkList.c
        DataStructure-master/LinearList/SingleLinkList.c
        DataStructure-master/Queue/CircularQueue.c
        DataStructure-master/Queue/Queue.c
        DataStructure-master/Search/BinarySearch.c
        DataStructure-master/Search/SequenceSearch.c
        DataStructure-master/Stack/Stack.c
        DataStructure-master/String/ForceMatch.c
        DataStructure-master/String/KMPMatch.c
        DataStructure-master/Tree/AVLBinaryTree.c
        DataStructure-master/Tree/BinarySearchTree.c
        DataStructure-master/Tree/BinaryTree.c
        DataStructure-master/Tree/BinaryTreeLevelTraverse.c
        DataStructure-master/Tree/BinaryTreeNonRecursivePost.c
        DataStructure-master/Tree/BinaryTreeNonRecursivePreAndIn.c
        DataStructure-master/Tree/BTree.c
        DataStructure-master/Tree/HuffmanTree.c
        DataStructure-master/Tree/InThreadBinaryTree.c
        DataStructure-master/Tree/PostThreadBinaryTree.c
        DataStructure-master/Tree/PreThreadBinaryTree.c
        "数据结构/作业01 线性表/3029-相加.c"
        "数据结构/作业01 线性表/3029-相加.c"
        "数据结构/作业01 线性表/3029-相加.c")
