//
//  binarySearchTree.cpp
//  binarySearchTreePractice
//
//  Created by Tim Lobes on 1/14/15.
//  Copyright (c) 2015 Tim Lobes. All rights reserved.
//

#include <iostream>
#include "binarySearchTree.h"


BST::BST() {
    root = nullptr;
}

BST::node* BST::CreateLeaf(int key) {
    node* n = new node;
    n->key = key;
    n->left = nullptr;
    n->right = nullptr;
    
    return n;
}

void BST::AddLeaf(int key) {
    AddLeafPrivate(key, root);
}

void BST::AddLeafPrivate(int key, node* Ptr) {
    
    if(root == NULL)
    {
        root = CreateLeaf(key);
    }
    // Go left (less than)
    else if (key < Ptr->key)
    {
        if(Ptr->left != NULL)
        {
            AddLeafPrivate(key, Ptr->left);
        }
        else
        {
            Ptr->left = CreateLeaf(key);
        }
    }
    // Go right (greater than)
    else if (key > Ptr->key)
    {
        if(Ptr->right != NULL)
        {
            AddLeafPrivate(key, Ptr->right);
        }
        else
        {
            Ptr->right = CreateLeaf(key);
        }
    }
    else
    {
        std::cout << "The key " << key << " has already been added\n";
    }
}

void BST::PrintInOrder() {
    PrintInOrderPrivate(root);
}

void BST::PrintInOrderPrivate(node* Ptr) {
    if(root != NULL)
    {
        if (Ptr->left != NULL)
        {
            PrintInOrderPrivate(Ptr->left);
        }
        
        std::cout << Ptr->key << " ";
        
        if (Ptr->right != NULL)
        {
            PrintInOrderPrivate(Ptr->right);
        }
    }
    else{
        std::cout << "Empty Tree!\n";
    }
}

BST::node* BST::ReturnNode(int key)
{
    return ReturnNodePrivate(key, root);
}

BST::node* BST::ReturnNodePrivate(int key, node* Ptr) {
    if(Ptr != NULL)
    {
        if (Ptr->key == key)
        {
            return Ptr;
        }
        else
        {
            if (key < Ptr->key)
            {
                return ReturnNodePrivate(key, Ptr->left); // Traverse left
            }
            else
            {
                return ReturnNodePrivate(key, Ptr->right); // Traverse right
            }
        }
    }
    else
    {
        return NULL;
    }
}
