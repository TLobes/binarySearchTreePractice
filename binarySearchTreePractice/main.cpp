//
//  main.cpp
//  binarySearchTreePractice
//
//  Created by Tim Lobes on 1/14/15.
//  Copyright (c) 2015 Tim Lobes. All rights reserved.
//

#include <iostream>
#include "binarySearchTree.h"

int main (int argc, char* argv[])
{
    
    int treeKeys[16] = {50, 76, 21, 4, 32, 64, 15, 52, 14, 100, 83, 2, 3, 70, 87, 80};
    BST myTree;
    
    std::cout << "Printing the tree in order\n" << "Before Adding numbers\n";
    
    myTree.PrintInOrder();
    
    for (int i = 0; i < 16; i++) {
        myTree.AddLeaf(treeKeys[i]);
    }
    
    std::cout << "Printing the tree in order\n" << "After Adding numbers\n";
    
    myTree.PrintInOrder();
    
    std::cout << std::endl;
    
    for (int i = 0; i < (sizeof(treeKeys) / sizeof(int)); i++)
    {
        myTree.PrintChildren(treeKeys[i]);
        std::cout << std::endl;
    }
    
    return 0;
}
