#ifndef AVERAGECALCULATOR_HPP
#define AVERAGECALCULATOR_HPP

#include "LinkedList.hpp"

// AverageCalculator sınıfı, bağlantılı listeler üzerinde ortalama hesaplama işlemlerini gerçekleştirir.
class AverageCalculator
{
public:
    // Hem yukarı hem de aşağı bağlantılı listelerdeki belirli bir pozisyondaki ortalama değerlerin toplamını hesaplar ve ekrana yazar
    static void calculateAndPrintAverage(LinkedList **up_list, LinkedList **down_list, int size);

private:
    // Belirli bir pozisyondaki düğümlerin ortalama değerini hesaplar
    static double calculateAverageForNodePosition(LinkedList **list, int size, int position);
};

#endif