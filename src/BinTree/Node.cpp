//
// Created by deturpant on 22.10.22.
//

#include "Node.h"
#include <iostream>
namespace KVA {
    Node *Node::insertNode(Node *_root, std::string _data) {
        if (_root == nullptr) {
            _root = new Node;
            _root->data = _data;
            _root->left = nullptr;
            _root->right = nullptr;
        } else if (_data < _root->data) {
            _root->left = insertNode(_root->left, _data);
        } else if (_data > _root->data) {
            _root->right = insertNode(_root->right, _data);
        }
        return _root;
    }

    void Node::print(Node *t, int n) {
        if (t != NULL) {
            int i;
            print(t->right, n + 1);
            for (int i = 0; i < n; i++) {
                std::cout << " ";
            }
            std::cout << t->data;
            print(t->left, n + 1);
        } else {
            std::cout << std::endl;
        }

    }
} // KVA