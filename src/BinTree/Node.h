//
// Created by deturpant on 22.10.22.
//

#ifndef TADS_LAB2_NODE_H
#define TADS_LAB2_NODE_H

#include <string>
#include <vector>
#include <set>
namespace KVA {

    class Node {
    public:
        std::string data = "";
        Node *left = nullptr;
        Node *right = nullptr;
        int checkWords(std::string data1, std::string data2);
        Node *insertNode(Node *_root, std::string _data);
        void print(Node *t, int n);

        Node *deleteNode(Node *_root, std::string _data);

        Node *GetMinimum(Node *_root);
        Node *DirectBypass(Node *_root, std::string _data1);
        Node *GetMaximum(Node *_root);
        Node *findElement(const KVA::Node *main_root, Node *_root, std::string _data, std::string out);
    };

} // KVA

#endif //TADS_LAB2_NODE_H
