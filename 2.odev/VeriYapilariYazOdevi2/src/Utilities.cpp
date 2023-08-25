/**
 * @file Utilities
 * @description Yardımcı fonksiyonları barındıran dosya. Özellikle karakterlerin ASCII karşılıklarını bulmak için kullanılır.
 * @course 1A
 * @assignment 2. Ödev
 * @date 28 Temmuz 2023
 * @author "Sena Nur Erdem" - sena.erdem1@ogr.sakarya.edu.tr
 */
#include "Utilities.hpp"

char findCharacter(int number)
{
    if (number >= 0 && number <= 256)
    {
        return static_cast<char>(number);
    }
    else
    {
        return ' '; // Sayı 0-256 aralığında değilse boşluk karakteri döndürür
    }
}
