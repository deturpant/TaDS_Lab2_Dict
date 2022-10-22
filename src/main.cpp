#include <iostream>
#include "Menu/Menu.h"
#include "BinTree/BinTree.h"
#include <string>
int main() {
    KVA::BinTree* bt = new KVA::BinTree();
    std::string data = "1";
    bt->insert(data);
    bt->insert("2");
    bt->insert("3");
    bt->insert("0");
    bt->insert("-1");
    bt->print(10);

    return 0;
}
