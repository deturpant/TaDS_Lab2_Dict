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
        DestroyNode(root, "");
    }

    std::string BinTree::DestroyNode(Node *node, std::string out) {
        if (node) {
            out += node->data + "\n";
            out = DestroyNode(node->left, out);
            out = DestroyNode(node->right, out);
            delete node;
            countElement--;
        }
        return out;
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

    std::string BinTree::clearTree(std::string out) {
        out = DestroyNode(root, out);
        root = nullptr;
        empty = true;
        countElement = 0;
        return out;
    }

    int BinTree::getCountElement() const {
        return countElement;
    }

    void BinTree::findElement(std::string _data) {
        std::string out;
        Node::findElement(root, root, _data, out);
    }
} // KVA