/**
 * @file LinkedList
 * @description BST'lerden oluşan tek yönlü liste yapısını tanımlar.
 * @course 1A
 * @assignment 2. Ödev
 * @date 28 Temmuz 2023
 * @author "Sena Nur Erdem" - sena.erdem1@ogr.sakarya.edu.tr
 */

#include "LinkedList.hpp"

LinkedList::LinkedList()
{
    head = NULL;
}

// LinkedList'e yeni bir Node ekler.
void LinkedList::push(const BST &tree)
{
    // Yeni bir Node oluşturur ve tree'yi atar.
    Node *node = new Node(tree);
    node->next = head;
    head = node;
}
void LinkedList::printAllTrees()
{
    Node *temp = head;
    int count = 1; // Ağaç sayacı

    while (temp != NULL)
    {
        std::cout << "Tree " << count << ":\n";
        temp->tree.postorder();
        std::cout << "\n";
        temp = temp->next;
        count++;
    }
}

// LinkedList'deki en yüksek tree'yi döndürür.
BST *LinkedList::maxTree()
{
    // LinkedList boşsa NULL döndürür.
    if (head == NULL)
    {
        return nullptr;
    }

    // Listenin başından başlar ve en yüksek tree'yi bulur.
    Node *temp = head;
    BST *maxTree = &temp->tree;

    // Tüm listeyi dolaşır ve en yüksek tree'yi bulur.
    while (temp != NULL)
    {
        if (temp->tree.height() > maxTree->height())
        {
            maxTree = &temp->tree;
        }
        else if (temp->tree.height() == maxTree->height())
        {
            if (temp->tree.sumValues() > maxTree->sumValues())
            {
                maxTree = &temp->tree;
            }
            else if (temp->tree.sumValues() == maxTree->sumValues())
            {
                maxTree = &temp->tree;
            }
            // Toplamlar eşit olduğunda bir şey yapmıyoruz. İlk olan ağacı korumak istiyoruz.
        }
        temp = temp->next;
    }
    // En yüksek tree'yi döndürür.
    return maxTree;
}

// LinkedList'deki tüm node'ları siler.
void LinkedList::clear()
{
    Node *temp;

    // Tüm node'ları siler.
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        delete temp;
    }
}
