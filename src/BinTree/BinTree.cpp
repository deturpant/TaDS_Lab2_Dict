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
            countElement--;
        }
    }

    void BinTree::insert(std::string _data) {
        root = insertNode(root, _data);
        empty = false;
        countElement++;
    }


    void BinTree::print(int n) {
        if (!empty) {
            Node::print(root, n);
        }
    }

    void BinTree::deleteEl(std::string _data) {
        root = deleteNode(root, _data);
        if (!root) empty = true;
        countElement--;

    }

    void BinTree::clearTree() {
        DestroyNode(root);
        root = nullptr;
        empty = true;
        countElement = 0;
    }

    int BinTree::getCountElement() const {
        return countElement;
    }

    void BinTree::findElement(std::string _data) {
        Node* tmp;
        std::string out;
        Node::findElement(root, _data, out);
    }
} // KVA