#include <iostream>
#include "Menu/MenuItem.h"
#include "Menu/MyMenu.h"
#include "BinTree/BinTree.h"
#include <string>
#include <vector>
#include <any>
#include <limits>

using namespace KVA;


void printTree(BinTree* bt) {

    bt->print(10);
}
void clearCIN() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.clear();
}
void startMenu(BinTree* bt) {
    while (true) {
        std::cout << "Меню приложения\n"
                     "1. Добавить новое слово в словарь\n"
                     "2. Проверить слово на предмет нахождения в словаре\n"
                     "3. Начать проверку правописания\n"
                     "4. Удалить слово из словаря\n"
                     "5. Очистить словарь.\n"
                     "0. Выход.\n--> ";
        int num{};
        std::cin >> num;
        switch(num) {
            case 1: {
                std::cout << "Пожалуйста, введите новое слово  --> ";
                std::string _data;
                std::cin >> _data;
                bt->insert(_data);
                std::cout << "Слово успешно добавлено!\n";
                break;
            }
            case 2:
                //pass
                bt->print(10);
                break;
            case 3:
                //pass
                break;
            case 4: {
                std::cout << "Пожалуйста, введите слово для удаления  --> ";
                std::string _data;
                std::cin >> _data;
                //нужно допилить!
                bt->deleteEl(_data);
                break;
            }
            case 5: {
                bt->clearTree();
                std::cout << "Дерево очищено!\n";
                break;
            }

            case 0:
                //допилить выгрузку в файл
                exit(0);
                break;
            default:
                break;


        }
    }
}
void func1(any& param) {
    cout << "hello world";
    auto * bt = any_cast<BinTree*>(param);
    bt->print(10);
}
void func2(any& param) {}
int main(int argc, char *argv[]) {
    BinTree* bt = new BinTree();
    MenuItem items[2] {
        MenuItem{"Add", func1},
        MenuItem{"Delete", func2}
    };
    MyMenu menu("Main menu", items, 2);
    any param = bt;
    bt->insert("1");
    while (true) {
        menu.runCommand(param);
    }



    /*
    std::string load_data_file = "data1.txt";
    std::string write_data_file = "data2.txt";
    std::string log_data_file = "logs.txt";
    if (argc >=3) {
        load_data_file = argv[1];
        write_data_file = argv[2];
        log_data_file = argv[3];
    }
    BinTree* bt = new KVA::BinTree();
    startMenu(bt);
*/
    return 0;
}
