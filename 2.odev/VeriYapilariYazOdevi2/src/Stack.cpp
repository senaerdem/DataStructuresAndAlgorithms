/**
 * @file Stack
 * @description Yığın, tamsayıları saklayan düğümlerden oluşur ve temel yığın işlevlerini (push, pop, peek) sağlar.
 * @course 1A
 * @assignment 2. Ödev
 * @date 28 Temmuz 2023
 * @author "Sena Nur Erdem" - sena.erdem1@ogr.sakarya.edu.tr
 */

#include "Stack.hpp"

// Stack'e yeni bir node ekler.
void Stack::push(int data)
{
    StackNode *temp = new StackNode;
    temp->data = data;
    temp->next = top;
    top = temp;
}

// Stack'den en üstteki node'u çıkarır.
int Stack::pop()
{
    // Stack boşsa hata mesajı döndürür.
    if (isEmpty())
    {
        std::cout << "Stack is empty." << std::endl;
        return -1;
    }
    else
    {
        // En üstteki node'u kaydeder ve en üstteki node'u sonraki node yapar.
        StackNode *temp = top;
        int poppedData = temp->data;
        top = top->next;

        // Kaydedilen node'u siler ve datasını döndürür.
        delete temp;
        return poppedData;
    }
}

// En üstteki node'un datasını döndürür.
int Stack::peek()
{
    // Stack boşsa hata mesajı döndürür.
    if (isEmpty())
    {
        std::cout << "Stack is empty." << std::endl;
        return -1;
    }
    else
    {
        // En üstteki node'un datasını döndürür.
        return top->data;
    }
}

Stack::Stack()
{
    top = nullptr;
}

// Yıkıcı, tüm node'ları siler.
Stack::~Stack()
{
    while (!isEmpty()) // Tüm node'ları gezer, siler.
    {
        pop();
    }
}

// Stack boş mu kontrol eder.
bool Stack::isEmpty()
{
    return top == nullptr;
}

void Stack::printStack()
{
    if (isEmpty())
    {
        std::cout << "Stack is empty." << std::endl;
    }
    else
    {
        StackNode *temp = top;
        std::cout << "Stack: ";
        while (temp != nullptr)
        {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
}
