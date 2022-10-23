//
// Created by deturpant on 22.10.22.
//

#ifndef TADS_LAB2_NODE_H
#define TADS_LAB2_NODE_H

#include <string>

namespace KVA {

    class Node {
    public:
        bool state = 0;
        std::string data = "";
        Node *left = nullptr;
        Node *right = nullptr;
        Node *insertNode(Node *_root, std::string _data);

        void print(Node *t, int n);

        Node *deleteNode(Node *_root, std::string _data);

        Node *GetMinimum(Node *_root);

        Node *GetMaximum(Node *_root);
        Node *findElement(Node *_root, std::string _data, std::string out);
    };

} // KVA

#endif //TADS_LAB2_NODE_H
