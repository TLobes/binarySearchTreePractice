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
    node* CreateLeaf(int key);
    void AddLeafPrivate(int key, node* Ptr);
    void PrintInOrderPrivate(node* Ptr);
    node* ReturnNodePrivate(int key, node* Ptr);
    node* ReturnNode(int key);
    

public:
    
    BST();
    void AddLeaf(int key);
    void PrintInOrder(); // In-order traversal
};

#endif /* defined(__binarySearchTreePractice__binarySearchTree__) */
