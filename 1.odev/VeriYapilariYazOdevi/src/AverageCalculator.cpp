/**
 * @file AverageCalculator
 * @description  Ortalamaları hesaplayan ve yazdıran sınıf
 * @course 1A
 * @assignment 1. Ödev
 * @date 18 Temmuz 2023
 * @author "Sena Nur Erdem"  sena.erdem1@ogr.sakarya.edu.tr
 */

#include "AverageCalculator.hpp"
#include "LinkedList.hpp"

#include <iostream>
#include <cmath>

// Belirli bir pozisyondaki düğümlerin ortalama değerini hesaplar
double AverageCalculator::calculateAverageForNodePosition(LinkedList **list, int size, int position)
{
    double sum = 0;
    int count = 0;

    // Her bir listenin belirli pozisyonundaki düğümü alır ve toplama ekler.
    for (int i = 0; i < size; ++i)
    {
        Node *node = list[i]->getNodeAt(position);
        if (node)
        {
            sum += node->data;
            ++count;
        }
    }
    // Eğer belirli bir pozisyonda düğüm varsa ortalama değeri döndür, yoksa 0 döndür
    return (count > 0) ? sum / count : 0;
}

// Hem yukarı hem de aşağı bağlantılı listelerdeki belirli bir pozisyondaki ortalama değerlerin toplamını hesaplar ve ekrana yazar
void AverageCalculator::calculateAndPrintAverage(LinkedList **up_list, LinkedList **down_list, int size)
{
    double up_average_sum = 0;
    double down_average_sum = 0;
    int max_length = 0;

    // En uzun listeyi bulmak için tüm listeleri kontrol et
    for (int i = 0; i < size; ++i)
    {
        int up_length = up_list[i]->getNodeCount();
        int down_length = down_list[i]->getNodeCount();
        if (up_length > max_length)
            max_length = up_length;
        if (down_length > max_length)
            max_length = down_length;
    }

    // Her bir pozisyondaki düğümlerin ortalamasını hesaplar ve toplama ekler.
    for (int i = 0; i < max_length; ++i)
    {
        up_average_sum += calculateAverageForNodePosition(up_list, size, i);
        down_average_sum += calculateAverageForNodePosition(down_list, size, i);
    }
    // Ortalama değerlerin toplamını ekrana yaz
    std::cout << "Ust: " << up_average_sum << std::endl;
    std::cout << "Alt: " << down_average_sum << std::endl;
}