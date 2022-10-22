//
// Created by deturpant on 22.10.22.
//

#include <iostream>
#include "BinTree.h"

namespace KVA {
    BinTree::BinTree() {
        root = nullptr;
    }

    BinTree::~BinTree() {
        DestroyNode(root);
    }

    void BinTree::DestroyNode(Node *node) {
        if (node) {
            DestroyNode(node->left);
            DestroyNode(node->right);
            delete node;
        }
    }

    void BinTree::insert(std::string _data) {
        root = insertNode(root, _data);
    }


    void BinTree::print(int n) {
        Node::print(root, n);
    }

    void BinTree::deleteEl(std::string _data) {
        root = deleteNode(root, _data);

    }
} // KVA