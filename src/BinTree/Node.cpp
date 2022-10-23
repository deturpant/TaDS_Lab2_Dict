//
// Created by deturpant on 22.10.22.
//

#include "Node.h"
#include <iostream>
#include <vector>

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
    Node *Node::findElement(KVA::Node *_root, std::string _data, std::string out, std::vector<std::string> list) {
        if (_root!=nullptr && checkWords(_data, _root->data) <= 3 && checkWords(_data, _root->data) > 0) {
            list.push_back(_root->data);
        }
        if (_root == nullptr) {
            if (out=="") {
                std::cout << "Слово отсуствует в словаре!\n";
            }
            if (list.size()>0) {
                std::cout << "Обнаружены похожие слова:\n";
                for (auto s : list) {
                    std::cout << s << std::endl;
                }
                std::cout << std::endl;
            }
            return nullptr;
        }
        if (_data == _root->data) {
            out = "Слово обнаружено в словаре. Правописание выполнено верно: ";
            std::cout << out << _data << "\n";
            return _root;
        }
        if (_data < _root->data) {
            _root->left = findElement(_root->left, _data, out, list);
            return _root;
        }
        if (_data > _root->data) {
            _root->right = findElement(_root->right, _data, out, list);
            return _root;
        }
        return _root;

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

    int Node::checkWords(std::string data1, std::string data2) {
        const char* cs1 = data1.c_str();
        const char* cs2 = data2.c_str();
        if (data1.length()!= data2.length()) {
            return -1;
        }
        int counter{};
        for (int i = 0; i<data2.length(); i++) {
            if (data1[i] == data2[i]) {
                counter++;
            }
        }

        return (data1.length() - counter);
    }
    /*int Node::length(const char* string_ptr){
        int count = 0;
        constchar *p = string_ptr;
        while (*p != 0)
        {
            if ((*p & 0x80) == 0 || (*p & 0xc0) == 0xc0)
                count++;
            p++;
        }
        return count;
    }*/
} // KVA