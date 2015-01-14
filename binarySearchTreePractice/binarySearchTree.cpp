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

int BST::ReturnRootKey() {
    if(root != NULL)
    {
        return root->key;
    }
    else
    {
        return -1;
    }
}

void BST::PrintChildren(int key) {
    node* Ptr = ReturnNode(key);
    if (Ptr != NULL)
    {
        std::cout << "Parent Node = " << Ptr->key << std::endl;
        
        Ptr->left == NULL ?
        std::cout << "Left Child = NULL\n" :
        std::cout << "Left Child = " << Ptr->left->key << std::endl;
        
        Ptr->right == NULL ?
        std::cout << "Right Child = NULL\n" :
        std::cout << "Right Child = " << Ptr->right->key << std::endl;
    }
    else
    {
        std::cout << key << " is not in the tree.\n";
    }
}

int BST::FindSmallest() {
    return FindSmallestPrivate(root);
}

int BST::FindSmallestPrivate(node* Ptr) {
    if (root == NULL)
    {
        std::cout << "Tree is empty!\n";
        return -1;
    }
    else
    {
        if(Ptr->left != NULL)
        {
            return FindSmallestPrivate(Ptr->left); // Traverse left
        }
        else
        {
            return Ptr->key; //Found the smallest
        }
    }
}

void BST::RemoveNode(int key) {
    RemoveNodePrivate(key, root);
}

void BST::RemoveNodePrivate(int key, node *parent) {
    if (root != NULL)
    {
        if (root->key == key)
        {
            RemoveRootMatch();
        }
        else
        {
            if (key < parent->key && parent->left != NULL)
            {
                parent->left->key == key ?
                RemoveMatch(parent, parent->left, true) :
                RemoveNodePrivate(key, parent->left);
            }
            else if (key < parent->key && parent->right != NULL)
            {
                parent->right->key == key ?
                RemoveMatch(parent, parent->right, false) :
                RemoveNodePrivate(key, parent->right);
            }
            else
            {
                std::cout << "The key " << key << " was not found in the tree\n";
            }
        }
    }
    else
    {
        std::cout << "Tree is empty!\n";
    }
}

void BST::RemoveRootMatch() {
    if (root != NULL)
    {
        node* delPtr = root;
        int rootKey = root->key;
        int smallestInRightSubtree;
        
        // Where root has no children
        if(root->left == NULL && root->right == NULL)
        {
            root = NULL;
            delete delPtr;
        }
        
        // One child
        else if (root->left == NULL && root->right != NULL)
        {
            root = root->right;
            delPtr->right = NULL;
            delete delPtr;
            std::cout << "The root node with key " << rootKey << " was deleted. " <<
            "The new root contains key " << root->key << std::endl;
        }
        else if (root->left != NULL && root->right == NULL)
        {
            root = root->left;
            delPtr->left = NULL;
            delete delPtr;
            std::cout << "The root node with key " << rootKey << " was deleted. " <<
            "The new root contains key " << root->key << std::endl;
        }
        
        // Two children
        else
        {
            smallestInRightSubtree = FindSmallestPrivate(root->right);
            RemoveNodePrivate(smallestInRightSubtree, root); // Delete smallest in right
            root->key = smallestInRightSubtree;
            std::cout << "The root key contianing key " << rootKey <<
            " was replaced with key " << root->key << std::endl;
        }
    }
    else
    {
        std::cout << "No root. Tree is empty!\n";
    }
}

void BST::RemoveMatch(node* parent, node* match, bool isLeft) {
    if(root != NULL)
    {
        node* delPtr;
        int matchKey = match->key;
        int smallestInRightSubtree;
        
        // No children
        if (match->left == NULL && match->right == NULL)
        {
            delPtr = match;
            isLeft == true ? parent->left = NULL : parent->right = NULL;
            delete delPtr;
            std::cout << "The node containing key " << matchKey << " was removed\n";
        }
        
        // One child
        else if (match->left == NULL && match->right != NULL)
        {
            isLeft == true ? parent->left = match->right : parent->right = match->right;
            match->right = NULL;
            delPtr = match;
            delete delPtr;
            std::cout << "The node containing key " << matchKey << " was removed\n";
        }
        else if (match->left != NULL && match->right == NULL)
        {
            isLeft == true ? parent->left = match->left : parent->right = match->left;
            match->left = NULL;
            delPtr = match;
            delete delPtr;
            std::cout << "The node containing key " << matchKey << " was removed\n";
        }
        
        // Two children
        else
        {
            smallestInRightSubtree = FindSmallestPrivate(match->right);
            RemoveNodePrivate(smallestInRightSubtree, match);
            match->key = smallestInRightSubtree;
        }
    }
    else
    {
        std::cout << "Can not remove match. Tree is emtpy!\n";
    }
}