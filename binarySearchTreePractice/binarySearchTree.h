//
//  binarySearchTree.h
//  binarySearchTreePractice
//
//  Created by Tim Lobes on 1/14/15.
//  Copyright (c) 2015 Tim Lobes. All rights reserved.
//

#ifndef __binarySearchTreePractice__binarySearchTree__
#define __binarySearchTreePractice__binarySearchTree__

class BST
{
private:
    
    struct node
    {
        int key;
        node* left;
        node* right;
    };
    
    node* root;
    void AddLeafPrivate(int key, node* Ptr);
    
    
public:
    
    BST();
    node* CreateLeaf(int key);
    void AddLeaf(int key);
};

#endif /* defined(__binarySearchTreePractice__binarySearchTree__) */
