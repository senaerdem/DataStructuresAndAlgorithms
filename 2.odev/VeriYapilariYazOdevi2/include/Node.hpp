#ifndef NODE_HPP
#define NODE_HPP

#include "BST.hpp"

struct Node
{
    BST tree;
    Node *next;

    Node(const BST &tree);
};

#endif // NODE_HPP
