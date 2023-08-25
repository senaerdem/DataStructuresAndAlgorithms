/**
 * @file Node
 * @description Tek yönlü liste için düğüm yapısını tanımlar. Her düğüm, bir ikili arama ağacı (BST) ve bir sonraki düğüme işaret eden bir işaretçi içerir.
 * @course 1A
 * @assignment 2. Ödev
 * @date 28 Temmuz 2023
 * @author "Sena Nur Erdem" - sena.erdem1@ogr.sakarya.edu.tr
 */
#include "Node.hpp"

// Yapıcı, bir BST alır ve Node'un tree'sine atar. next pointer'ını NULL yapar.
Node::Node(const BST &tree) : tree(tree), next(NULL) {}
