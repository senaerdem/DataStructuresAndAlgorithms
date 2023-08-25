/**
 * @file BST
 * @description İkili arama ağacı - Ağacın temel işlevleri (ekleme, postorder sıralama, yükseklik ve değerlerin toplamı alma) için yöntemleri içerir.
 * @course 1A
 * @assignment 2. Ödev
 * @date 28 Temmuz 2023
 * @author "Sena Nur Erdem" - sena.erdem1@ogr.sakarya.edu.tr
 */

#include "BST.hpp"
#include "Utilities.hpp"

BST::BST() : root(NULL) {}
BST::BST(const BST &other)
{
    root = copyHelper(other.root);
}
// BST'den bir kopya oluşturur
TreeNode *BST::copyHelper(TreeNode *node)
{
    if (node == nullptr)
    {
        return nullptr;
    }
    else
    {
        TreeNode *newNode = new TreeNode;
        newNode->data = node->data;
        newNode->left = copyHelper(node->left);
        newNode->right = copyHelper(node->right);
        return newNode;
    }
}
// Veriyi ekler
TreeNode *BST::insert(TreeNode *node, int data)
{
    if (node == NULL)
    {
        node = new TreeNode;
        node->data = data;
        node->left = node->right = NULL;
    }
    else if (data < node->data)
    {
        node->left = insert(node->left, data);
    }
    else if (data > node->data)
    {
        node->right = insert(node->right, data);
    }
    return node;
}
// Postorder düzende çıktı alır.
void BST::postorder(TreeNode *node)
{
    if (node == NULL)
    {
        return;
    }
    postorder(node->left);
    postorder(node->right);

    // Belirli sayılara karşılık gelen özel karakterler kontrolü
    char character = findCharacter(node->data);
    std::cout << character << " ";
}

// Tree'nin yüksekliğini alır
int BST::height(TreeNode *node)
{
    if (node == NULL)
    {
        return 0;
    }
    else
    {
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);
        return std::max(leftHeight, rightHeight) + 1;
    }
}

// Tüm değerlerin toplamını alır
int BST::sumValues(TreeNode *node)
{
    if (node == NULL)
    {
        return 0;
    }
    else
    {
        return node->data + sumValues(node->left) + sumValues(node->right);
    }
}

// Tree'yi temizler
void BST::clearTree(TreeNode *node)
{
    if (node != NULL)
    {
        clearTree(node->left);
        clearTree(node->right);
        delete node;
    }
}

// Public functions
BST::~BST()
{
    if (root != NULL)
    {
        clearTree(root);
    }
}

void BST::insert(int data)
{
    root = insert(root, data);
}

void BST::postorder()
{
    postorder(root);
    std::cout << std::endl;
}

int BST::height()
{
    return height(root);
}

int BST::sumValues()
{
    return sumValues(root);
}
