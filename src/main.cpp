#include <iostream>
#include "Menu/Menu.h"
#include "BinTree/BinTree.h"
#include <string>
int main() {
    KVA::BinTree* bt = new KVA::BinTree();
    bt->insert("10");
    bt->insert("5");
    bt->insert("7");
    bt->insert("2");
    bt->insert("1");
    bt->insert("6");
    bt->insert("-20");
    bt->print(10);
    bt->deleteEl("5");
    bt->print(10);
    bt->clearTree();
    bt->print(10);
    return 0;
}
