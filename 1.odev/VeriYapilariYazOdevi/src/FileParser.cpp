/**
 * @file FileParser
 * @description Dosyadan okuma ve bağlantılı listeleri oluşturma işlemlerini gerçekleştiren sınıf
 * @course 1A
 * @assignment 1. Ödev
 * @date 18 Temmuz 2023
 * @author "Sena Nur Erdem" sena.erdem1@ogr.sakarya.edu.tr
 */

#include "FileParser.hpp"

#include <fstream>
#include <string>
#include <sstream>

// Dosyadan satırları okur ve her satırı iki farklı bağlantılı listeye dağıtır
void FileParser::parseFile(LinkedList **&up_list, LinkedList **&down_list, int &size)
{
    std::ifstream file("Sayilar.txt"); // Dosya açılır
    std::string line;
    int count = 0;

    // Dosyadaki satır sayısını sayar.
    while (std::getline(file, line))
    {
        count++;
    }

    // Bağlantılı liste dizileri için bellekte yer ayırır.
    up_list = new LinkedList *[count];
    down_list = new LinkedList *[count];
    size = count; // Boyut satır sayısı kadar olur

    // Dosya işaretçisini başa döndürür.
    file.clear();
    file.seekg(0, std::ios::beg);

    count = 0;

    // Dosyadan veri okuyarak bağlantılı listeleri oluşturur.
    while (std::getline(file, line))
    {
        std::istringstream iss(line);
        int number;
        up_list[count] = new LinkedList();
        down_list[count] = new LinkedList();

        // Her sayıyı okur ve onlar basamağını up_list'e, birler basamağını down_list'e ekler
        while (iss >> number)
        {
            up_list[count]->addNode(number / 10);
            down_list[count]->addNode(number % 10);
        }
        count++;
    }
}
