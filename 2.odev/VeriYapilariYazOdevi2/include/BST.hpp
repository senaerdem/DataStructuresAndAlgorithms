#ifndef BST_HPP
#define BST_HPP

#include <iostream>

// TreeNode, BST'nin öğelerini içerir.
struct TreeNode
{
    int data; // TreeNode içerisindeki veri
    TreeNode *left;
    TreeNode *right;
};

class BST
{
private:
    TreeNode *root;

    TreeNode *insert(TreeNode *node, int data); // Veri ekler
    void postorder(TreeNode *node);             // Postorder düzende çıktı alır
    int height(TreeNode *node);                 // Tree'nin yüksekliğini alır
    int sumValues(TreeNode *node);              // Tüm değerlerin toplamını alır
    void clearTree(TreeNode *node);             // Tree'yi temizler
    TreeNode *copyHelper(TreeNode *node);       // Tree'nin bir kopyasını oluşturur

public:
    BST();
    BST(const BST &other);
    void insert(int data); // Yeni veri ekler
    void postorder();      // Postorder düzende çıktı alır
    int height();          // Tree'nin yüksekliğini döndürür
    int sumValues();       // Tüm değerlerin toplamını döndürür

    ~BST();
};

#endif // BST_HPP
