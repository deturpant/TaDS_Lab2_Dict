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
        if (t) {
            print(t->right, n + 2);
            for (int i = 0; i < n; i++) {
                std::cout << "-";
            }
            std::cout << t->data;
            print(t->left, n + 2);
        } else {
            std::cout << std::endl;
        }

    }

    Node *Node::deleteNode(Node *_root, std::string _data) {
        if (_root == nullptr) {
            return nullptr;
        }
        if (_data == _root->data) {
            if (_root->left == nullptr && _root->right == nullptr) {
                delete _root;
                return nullptr;
            }
            if (_root->left == nullptr && _root->right != nullptr) {
                Node *tmp = _root->right;
                delete _root;
                return tmp;
            }
            _root->data = GetMinimum(_root->right)->data;
            _root->right = deleteNode(_root->right, _root->data);
            return _root;
        }
        if (_data < _root->data) {
            _root->left = deleteNode(_root->left, _data);
            return _root;
        }
        if (_data > _root->data) {
            _root->right = deleteNode(_root->right, _data);
            return _root;
        }
        return _root;
    }

    Node *Node::GetMinimum(Node *_root) {
        if (!_root->left) {
            return _root;
        }
        return GetMinimum(_root->left);
    }

    Node *Node::GetMaximum(Node *_root) {
        if (!_root->right) {
            return _root;
        }
        return GetMaximum(_root->right);
    }
} // KVA