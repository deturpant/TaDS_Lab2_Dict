//
// Created by deturpant on 22.10.22.
//

#include "Node.h"
#include <iostream>
#include <vector>
#include <codecvt>
#include <locale>
#include <set>
#include <algorithm>
#include "../Exceptions/MyException.h"
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

    Node *Node::findElement(const KVA::Node *main_root, KVA::Node *_root, std::string _data, std::string out) {
        if (_root == nullptr) {
            if (out == "") {
                std::cout << "Слово отсуствует в словаре!\nПоискать похожие слова?\n1) Да\n2) Нет\n==> ";
                int ind{};
                std::cin >> ind;
                switch(ind) {
                    case 1: {
                        Node *tmp = new Node;
                        tmp->data = main_root->data;
                        tmp->right = main_root->right;
                        tmp->left = main_root->left;
                        try {
                            DirectBypass(tmp, _data);
                        }
                        catch (const MyException &ex) {
                            break;
                        }
                    }
                    case 2:
                        break;
                    default:
                        break;
                }

            }
            return nullptr;
        }
        if (_data == _root->data) {
            out = "Слово обнаружено в словаре. Правописание выполнено верно: ";
            std::cout << out << _data << "\n";
            return _root;
        }
        if (_data < _root->data) {
            _root->left = findElement(main_root, _root->left, _data, out);
            return _root;
        }
        if (_data > _root->data) {
            _root->right = findElement(main_root, _root->right, _data, out);
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
        std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
        std::wstring _data1 = converter.from_bytes(data1);
        std::wstring _data2 = converter.from_bytes(data2);
        //std::cout << data1 << " | _data1.size() = " << _data1.size() << " | _data2.size() = " << _data2.size() << std::endl;
        if (_data1.size() != _data2.size()) {
            return -1;
        }
        int counter{};
        //std::cout << "data1 = " << data1 << " | data2 = " << data2 << std::endl;
        for (int i = 0; i < _data1.size(); i++) {
            //std::cout << "_data1[" << i << "] = " << _data1[i] << " | _data2[" << i << "] = " << _data2[i] << std::endl;
            if (_data1[i] == _data2[i]) {
                counter++;
            }
        }

        return _data1.length() - counter;
    }
    Node *Node::DirectBypass(Node *_root, std::string _data1) {
        if (_root == nullptr) return nullptr;
        if (checkWords(_root->data, _data1) <2 && checkWords(_root->data, _data1) > 0) {
            std::cout << "Обнаружено похожее слово: " << _root->data << std::endl;
        }
        DirectBypass(_root->left, _data1);
        DirectBypass(_root->right, _data1);
    }


} // KVA