# Quaternary Search Tree (QST) Implementation

This is a C++ implementation of a Quaternary Search Tree (QST) data structure, where each node can have up to 4 children. The QST is designed to insert and remove elements based on a specified key range and provides functions to print the tree in both preorder and postorder traversal orders.

## Introduction

A Quaternary Search Tree is a tree-like data structure that is a variation of a binary search tree. In a QST, each node has up to 4 children, and elements are inserted and removed based on a specified key range.

This implementation provides the following functionalities:
1. Insert elements with specific keys into the QST.
2. Remove elements from the QST based on their keys.
3. Print the QST in both preorder and postorder traversal orders.
4. A menu-based system to control the operations.

## Implementation Details

The Quaternary Search Tree is implemented as a templated class, allowing you to use it with various data types.
Each node in the tree has a key and up to 4 children nodes.
The key range is divided into four parts, and elements are inserted and removed based on their keys in these ranges.
Elements within the range [0, k/2) are inserted as the leftmost child.
Elements within the range [k/2, k) are inserted as the second child.
Elements within the range (k, 2k) are inserted as the third child.
Elements within the range (2k, ∞) are inserted as the rightmost child.

