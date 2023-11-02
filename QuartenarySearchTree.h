#ifndef QST_H
#define QST_H

#include <iostream>
#include "Object1.h"
#include "Object2.h"

template <typename T>
class Node
{
public:
    T obj;
    Node *children[4]; // Four children for the four ranges

    Node(const T &value) : obj(value)
    {
        for (int i = 0; i < 4; i++)
        {
            children[i] = nullptr;
        }
    }
};

template <typename T>
class QuartenarySearchTree
{

private:
    Node<T> *root;

    Node<T> *insertRecursive(Node<T> *&node, const T &obj);
    Node<T> *removeRecursive(Node<T> *&node, const T &obj);
    void printPreorderRecursive(Node<T> *node);
    void printPostorderRecursive(Node<T> *node);

public:
    QuartenarySearchTree();
    QuartenarySearchTree(const T *initialData, int size);

    void insert(const T &obj);
    void remove(const T &obj);
    void preorder();
    void postorder();
};

template <typename T>
QuartenarySearchTree<T>::QuartenarySearchTree() {}

template <typename T>
QuartenarySearchTree<T>::QuartenarySearchTree(const T *initialData, int size)
{
    root = nullptr;
    for (int i = 0; i < size; i++)
    {
        if (root == nullptr) {
            root = new Node<T>(initialData[i]);
        }
        else {
            insert(initialData[i]);
        }
    }
}


template <typename T>
void QuartenarySearchTree<T>::insert(const T &obj)
{
    insertRecursive(root, obj);
}

template <typename T>
Node<T> *QuartenarySearchTree<T>::insertRecursive(Node<T> *&node, const T &obj)
{
    if (node == nullptr)
    {
        return new Node<T>(obj);
    }

    // Determine which child to insert based on obj ranges
    if (obj < (node->obj / 2))
    {
        node->children[0] = insertRecursive(node->children[0], obj);
    }
    else if (obj < node->obj)
    {
        node->children[1] = insertRecursive(node->children[1], obj);
    }
    else if (obj < (node->obj * 2))
    {
        node->children[2] = insertRecursive(node->children[2], obj);
    }
    else
    {
        node->children[3] = insertRecursive(node->children[3], obj);
    }

    return node;
}

template <typename T>
void QuartenarySearchTree<T>::remove(const T &obj)
{
    removeRecursive(root, obj);
}

template <typename T>
Node<T> *QuartenarySearchTree<T>::removeRecursive(Node<T> *&node, const T &obj)
{
    if (node == nullptr)
    {
        // Key not found, nothing to remove
        return nullptr;
    }

    if (obj < (node->obj / 2))
    {
        node->children[0] = removeRecursive(node->children[0], obj);
    }
    else if (obj < node->obj)
    {
        node->children[1] = removeRecursive(node->children[1], obj);
    }
    else if (obj < (node->obj * 2))
    {
        node->children[2] = removeRecursive(node->children[2], obj);
    }
    else
    {
        node->children[3] = removeRecursive(node->children[3], obj);
    }

    // Node found, remove it
    if (obj == node->obj)
    {
        // Handle removal logic (e.g., freeing memory, rebalancing, etc.)
        // Implement your logic here
        delete node;
        return nullptr;
    }

    return node;
}

// Preorder traversal
template <typename T>

void QuartenarySearchTree<T>::preorder()
{
    printPreorderRecursive(root);
    std::cout << std::endl;
}

template <typename T>
void QuartenarySearchTree<T>::printPreorderRecursive(Node<T> *node)
{
    if (node == nullptr)
    {
        return;
    }

    std::cout << node->obj << " ";
    for (int i = 0; i < 4; i++)
    {
        printPreorderRecursive(node->children[i]);
    }
}

// Postorder traversal
template <typename T>
void QuartenarySearchTree<T>::postorder()
{
    printPostorderRecursive(root);
    std::cout << std::endl;
}

template <typename T>
void QuartenarySearchTree<T>::printPostorderRecursive(Node<T> *node)
{
    if (node == nullptr)
    {
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        printPostorderRecursive(node->children[i]);
    }
    std::cout << node->obj << " ";
}

#endif