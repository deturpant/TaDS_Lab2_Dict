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
        std::string clearTree(std::string out);
        void findElement(std::string _data);

        int getCountElement() const;

    private:
        Node *root;
        bool empty = true;
        std::string DestroyNode(Node *node, std::string out);
        int countElement{};
    };

} // KVA

#endif //TADS_LAB2_BINTREE_H
