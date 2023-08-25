/**
 * @file LinkedList
 * @description Bu sınıf bir bağlı liste veri yapısını temsil eder ve bu liste üzerinde düğüm ekleme, listenin eleman sayısını döndürme, belirli bir konumdaki düğümü alabilme gibi işlemleri gerçekleştirebilir.
 * @course 1A
 * @assignment 1. Ödev
 * @date 18 Temmuz 2023
 * @author "Sena Nur Erdem" sena.erdem1@ogr.sakarya.edu.tr
 */

#include "LinkedList.hpp"

#include <iostream>

// Yapıcı metod. Yeni bir LinkedList oluşturulduğunda başlangıçta hiç düğümü yoktur ve düğüm sayısı 0'dır.
LinkedList::LinkedList() : head(nullptr), count(0) {}

// Yıkıcı metod. LinkedList silindiğinde, tüm düğümler bellekten silinir.
LinkedList::~LinkedList()
{
    Node *current = head;
    while (current)
    {
        Node *temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;
}

// Yeni bir düğüm oluşturur ve bu düğümü listeye ekler.
void LinkedList::addNode(int data)
{
    Node *new_node = new Node;
    new_node->data = data;
    new_node->next = nullptr;
    count++;

    if (head == nullptr)
    {
        head = new_node;
    }
    else
    {
        Node *last = head;
        while (last->next)
        {
            last = last->next;
        }
        last->next = new_node;
    }
}

// Listeyi ekrana basar. Her düğümde, düğümün verisini ve bir boşluk yazdırır.
void LinkedList::printList()
{
    Node *current = head;
    while (current)
    {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

// Listede bulunan düğüm sayısını döndürür.
int LinkedList::getNodeCount()
{
    return count;
}

// Listede bulunan tüm düğümlerin veri değerlerinin ortalamasını döndürür.
double LinkedList::getAverage()
{
    if (count == 0)
        return 0;

    double sum = 0;
    Node *current = head;
    while (current)
    {
        sum += current->data;
        current = current->next;
    }

    return sum / count;
}

// Belirli bir indeksteki düğümün veri değerini döndürür.
int LinkedList::getNodeValue(int nodeIndex)
{
    Node *current = head;
    int index = 0;

    while (current)
    {
        if (index == nodeIndex)
            return current->data;

        current = current->next;
        ++index;
    }

    return 0;
}

// Belirli bir indeksteki düğümü döndürür.
Node *LinkedList::getNodeAt(int index)
{
    Node *temp = head;

    int count = 0;
    while (temp != nullptr)
    {
        if (count == index)
            return temp;
        count++;
        temp = temp->next;
    }

    return nullptr;
}