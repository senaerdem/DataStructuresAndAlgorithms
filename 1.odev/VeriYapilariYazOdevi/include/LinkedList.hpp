#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

// Düğüm yapısının tanımı
struct Node
{
    int data;   // Düğümde saklanacak veri
    Node *next; // Bir sonraki düğüme işaret eden pointer
};

class LinkedList
{
public:
    LinkedList();                    // Yapıcı metod
    ~LinkedList();                   // Yıkıcı metod
    void addNode(int data);          // Bir düğümü listenin sonuna eklemek için metot
    void printList();                // Listenin elemanlarını baştan sona doğru yazdırmak için metot
    int getNodeCount();              // Listenin düğüm sayısını döndürmek için metot
    double getAverage();             // Listenin düğüm verilerinin ortalamasını hesaplamak ve döndürmek için metot
    int count;                       // Listenin düğüm sayısını tutmak için değişken
    int getNodeValue(int nodeIndex); // Belirli bir düğüm indeksindeki değeri döndürmek için metot
    Node *getNodeAt(int index);      // Belirli bir indeksteki düğümün pointer'ını döndürmek için metot

private:
    Node *head; // Listenin başını tutan pointer
};

#endif
