#ifndef FILEPARSER_HPP
#define FILEPARSER_HPP

#include "LinkedList.hpp"

// FileParser sınıfı bir dosyadan veri okuyarak bağlantılı liste oluşturur.
class FileParser
{
public:
    // Dosyadan satırları okur ve her satırı iki farklı bağlantılı listeye dağıtır
    static void parseFile(LinkedList **&up_list, LinkedList **&down_list, int &size);
};

#endif
