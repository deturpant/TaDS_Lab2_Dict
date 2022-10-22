//
// Created by deturpant on 22.10.22.
//

#ifndef TADS_LAB2_NODE_H
#define TADS_LAB2_NODE_H
#include <string>
namespace KVA {

    class Node {
    public:
        std::string data = "";
        Node *left = nullptr;
        Node *right = nullptr;
        Node* insertNode(Node* _root, std::string _data);
        void print(Node *t, int n);
    };

} // KVA

#endif //TADS_LAB2_NODE_H
