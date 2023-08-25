/**
 * @file main
 * @description main metot içeren sınıf
 * @course 1A
 * @assignment 2. Ödev
 * @date 28 Temmuz 2023
 * @author "Sena Nur Erdem" - sena.erdem1@ogr.sakarya.edu.tr
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <chrono>
#include <thread>
#include <locale>
#include "Stack.hpp"
#include "BST.hpp"
#include "LinkedList.hpp"
#include "Utilities.hpp"

#ifdef _WIN32
#include <windows.h>
void sleep_ms(int milliseconds)
{
    Sleep(milliseconds);
}
#else
void sleep_ms(int milliseconds)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}
#endif

int main()
{
    std::string line;
    std::ifstream file("Sayilar.txt");

    if (!file.is_open())
    {
        std::cout << "Failed to open file" << std::endl;
        return 1;
    }

    while (getline(file, line))
    {
        std::istringstream ss(line);
        int num;
        Stack stack;
        LinkedList list;

        // İlk sayı
        ss >> num;
        stack.push(num);

        // Satırdaki geri kalan sayıları oku
        while (ss >> num)
        {
            if (num % 2 == 0 && num > stack.peek())
            {
                // Yeni bir ağaç oluştur ve stack'deki sayıları ekle
                BST tree;
                while (!stack.isEmpty())
                {
                    tree.insert(stack.pop());
                    // stack.printStack();
                }
                list.push(tree);
                // std::cout << "Yeni BST oluşturuldu ve listeye eklendi.\n";
            }
            stack.push(num);
            // stack.printStack();
        }

        // Stack'deki kalan sayıları işle
        if (!stack.isEmpty())
        {
            BST tree;
            while (!stack.isEmpty())
            {
                tree.insert(stack.pop());
            }
            list.push(tree);
            // std::cout << "Stack'deki kalan sayılardan son BST oluşturuldu ve listeye eklendi.\n";
        }

        // En büyük ağacı belirle
        BST *maxTree = list.maxTree();

        // En büyük ağacı postorder sıralamasında yazdır
        // std::cout << "Bu satır için en büyük ağaç: ";
        // list.printAllTrees();
        maxTree->postorder();
        // std::cout << "\n";

        // 10 milisaniye bekle
        sleep_ms(10);

        // Bir sonraki satır için listeyi temizle
        list.clear();
    }

    file.close();

    return 0;
}
