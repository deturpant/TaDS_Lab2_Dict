//
// Created by deturpant on 22.10.22.
//
#include <string>

#ifndef TADS_LAB2_BINTREE_H
#define TADS_LAB2_BINTREE_H

#include "Node.h"

namespace KVA {
    class BinTree : Node {
    public:
        BinTree();

        ~BinTree();

        void insert(std::string _data);

        void print(int n);

        void deleteEl(std::string _data);

    private:
        Node *root;

        void DestroyNode(Node *node);
    };

} // KVA

#endif //TADS_LAB2_BINTREE_H
