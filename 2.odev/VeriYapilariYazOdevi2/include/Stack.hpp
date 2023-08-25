#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>

struct StackNode
{
    int data;        // Node'un sakladığı data
    StackNode *next; // Sonraki node'a işaret eden bir pointer
};

// Stack sınıfı, StackNode'lardan oluşur ve en üstteki node'u takip eder.
class Stack
{
private:
    StackNode *top; // Stack'in en üstteki node'u

public:
    Stack(); // Yapıcı, en üstteki node'u NULL yapar.

    bool isEmpty();      // Stack boş mu kontrol eder.
    void push(int data); // Yeni bir node ekler.
    int pop();           // En üstteki node'u çıkarır.
    int peek();          // En üstteki node'un datasını döndürür.
    void printStack();   // Stack'in mevcut durumunu çıktı olarak verir.

    ~Stack(); // Yıkıcı, tüm node'ları siler.
};

#endif // STACK_HPP
