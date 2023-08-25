#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include "Node.hpp"

class LinkedList
{
private:
    Node *head;

public:
    LinkedList(); // Yapıcı, listeye başı NULL yapar.
    void printAllTrees();

    void push(const BST &tree); // Yeni bir Node ekler.
    BST *maxTree();             // En yüksek tree'yi döndürür.
    void clear();               // Tüm node'ları siler.
};

#endif // LINKEDLIST_HPP
