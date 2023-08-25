/**
 * @file main
 * @description main metot içeren sınıf
 * @course 1A
 * @assignment 1. Ödev
 * @date 18 Temmuz 2023
 * @author "Sena Nur Erdem" sena.erdem1@ogr.sakarya.edu.tr
 */

#include "LinkedList.hpp"
#include "AverageCalculator.hpp"
#include "FileParser.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

// Bu fonksiyon, kullanıcıdan geçerli bir index alır ve bunu döndürür.
int getValidIndex(const std::string &prompt, int size)
{
    int index;
    std::cout << prompt;
    std::cin >> index;

    while (std::cin.fail() || index < 0 || index >= size)
    {
        std::cin.clear(); // Eğer giriş hatalıysa
        while (std::cin.get() != '\n')
            ; // boşluk bulana kadar bir sonraki karakteri oku ve yoksay.

        std::cout << "Geçersiz indeks! Lütfen 0 ile " << size - 1 << " arasında bir sayı girin: ";
        std::cin >> index;
    }

    return index;
}

int main()
{
    // Bağlı listeler için bellekte yer ayrılır
    LinkedList **up_list = nullptr;
    LinkedList **down_list = nullptr;
    int size = 0;

    // Dosyadan verileri çeker ve bağlı listelere ekler.
    FileParser::parseFile(up_list, down_list, size);

    // std::cout << "Before swapping:" << std::endl;
    // for (int i = 0; i < size; i++)
    // {
    //     std::cout << "Upward list " << i << ": ";
    //     up_list[i]->printList();
    //     std::cout << "Downward list " << i << ": ";
    //     down_list[i]->printList();
    // }

    // Kullanıcıdan iki adet geçerli index alır.
    int A = getValidIndex("Konum A: ", size);
    int B = getValidIndex("Konum B: ", size);
    std::cout << std::endl;

    // A indexindeki up_list ile B indexindeki down_list'i yer değiştirir.
    std::swap(up_list[A], down_list[B]);

    // std::cout << "After swapping:" << std::endl;
    // for (int i = 0; i < size; i++)
    // {
    //     std::cout << "Upward list " << i << ": ";
    //     up_list[i]->printList();
    //     std::cout << "Downward list " << i << ": ";
    //     down_list[i]->printList();
    // }

    // Ortalamaları hesaplar ve ekrana basar.
    AverageCalculator::calculateAndPrintAverage(up_list, down_list, size);

    // Alınan belleği iade eder
    for (int i = 0; i < size; i++)
    {
        delete up_list[i];
        delete down_list[i];
    }
    delete[] up_list;
    delete[] down_list;

    return 0;
}
