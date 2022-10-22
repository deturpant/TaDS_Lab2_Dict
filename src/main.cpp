#include <iostream>
#include "Menu/MenuItem.h"
#include "Menu/MyMenu.h"
#include "BinTree/BinTree.h"
#include <string>
#include <any>

using namespace KVA;

void addToTree(any& param) {
    auto * bt = any_cast<BinTree*>(param);
    std::cout << "Пожалуйста, введите новое слово  --> ";
    std::string _data;
    std::cin >> _data;
    bt->insert(_data);
    std::cout << "Слово успешно добавлено!\n";
}
void printTree(any& param) {
    auto * bt = any_cast<BinTree*>(param);
    bt->print(10);
}
void deleteEl(any& param) {
    auto * bt = any_cast<BinTree*>(param);
    std::cout << "Пожалуйста, введите слово для удаления  --> ";
    std::string _data;
    std::cin >> _data;
    //нужно допилить!
    bt->deleteEl(_data);
}
void clearTree(any&param) {
    auto * bt = any_cast<BinTree*>(param);
    bt->clearTree();
    cout << "Очистка дерева завершена.\n";
}

string MyException::file_name = "logs.txt";
const int ITEMS_MENU = 4;

int main(int argc, char *argv[]) {
    std::string load_data_file = "data1.txt";
    std::string write_data_file = "data2.txt";
    std::string log_data_file = "logs.txt";
    if (argc >=3) {
        load_data_file = argv[1];
        write_data_file = argv[2];
        log_data_file = argv[3];
    }
    MyException::setFileName(log_data_file);

    BinTree* bt = new BinTree();
    MenuItem items[ITEMS_MENU] {
        MenuItem{"Добавить слово в словарь", addToTree},
        MenuItem{"Распечатать словарь", printTree},
        MenuItem{"Удалить слово из словаря", deleteEl},
        MenuItem{"Очистить словарь", clearTree}
    };
    MyMenu menu("Main menu", items, ITEMS_MENU);
    any param = bt;
    while (true) {
        try {
            menu.runCommand(param);
        }
        catch (const MyException &ex) {
            cout << "Error: " << ex.getError() << "\n";
        }
    }


    return 0;
}
