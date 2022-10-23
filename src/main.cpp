#include <iostream>
#include "Menu/MenuItem.h"
#include "Menu/MyMenu.h"
#include "BinTree/BinTree.h"
#include <string>
#include <any>
#include <fstream>

using namespace KVA;

void loadFromFile(any &param) {
    auto *bt = any_cast<BinTree *>(param);
    fstream file;
    string s;
    file.open("../itog.txt"); //работает
    while (getline(file, s)) {
        bt->insert(s);
    }
    file.close();
}

void addToTree(any &param) {
    auto *bt = any_cast<BinTree *>(param);
    std::cout << "Пожалуйста, введите новое слово  --> ";
    std::string _data;
    std::cin >> _data;
    bt->insert(_data);
    std::cout << "Слово успешно добавлено!\n";
}

void printTree(any &param) {
    auto *bt = any_cast<BinTree *>(param);
    if (bt->getCountElement() == 0) cout << "Словарь пуст.\n";
    else if (bt->getCountElement() > 20) {
        cout
                << "Количество слов в словаре превышает 20. Отображение может быть некорректным.\nВы уверены, что хотите распечатать словарь?\n1) Да\n0) Вернуться назад\n==> ";
        int ind{};
        cin >> ind;
        switch (ind) {
            case 1:
                bt->print(10);
            case 0:
                break;
            default:
                break;
        }
    } else {
        bt->print(10);
    }
}

void deleteEl(any &param) {
    auto *bt = any_cast<BinTree *>(param);
    std::cout << "Пожалуйста, введите слово для удаления  --> ";
    std::string _data;
    std::cin >> _data;
    //нужно допилить!
    bt->deleteEl(_data);
    std::cout << "Слово успешно удалено!\n";
}

void clearTree(any &param) {
    auto *bt = any_cast<BinTree *>(param);
    bt->clearTree();
    cout << "Очистка словаря завершена.\n";
}

void getCountWord(any &param) {
    auto *bt = any_cast<BinTree *>(param);
    if (bt->getCountElement() != 0) {
        cout << "Количество слов в словаре: " << bt->getCountElement() << " слов.\n";
    } else {
        cout << "Словарь пуст";
    }
}

void checkWord(any &param) {
    auto *bt = any_cast<BinTree *>(param);
    std::cout << "Пожалуйста, введите слово для проверки  --> ";
    std::string _data;
    std::cin >> _data;
    bt->findElement(_data);
}

string MyException::file_name = "logs.txt";
const int ITEMS_MENU = 7;

int main(int argc, char *argv[]) {
    std::string load_data_file = "data1.txt";
    std::string write_data_file = "data2.txt";
    std::string log_data_file = "logs.txt";
    if (argc >= 3) {
        load_data_file = argv[1];
        write_data_file = argv[2];
        log_data_file = argv[3];
    }
    MyException::setFileName(log_data_file);

    BinTree *bt = new BinTree();
    MenuItem items[ITEMS_MENU]{
            MenuItem{"Добавить слово в словарь", addToTree},
            MenuItem{"Распечатать словарь", printTree},
            MenuItem{"Удалить слово из словаря", deleteEl},
            MenuItem{"Очистить словарь", clearTree},
            MenuItem{"Загрузить в словарь существительные (51301 слово)", loadFromFile},
            MenuItem{"Получить количество слов в словаре", getCountWord},
            MenuItem{"Проверить правописание слова", checkWord}
    };
    MyMenu menu("Словарь слов русского языка", items, ITEMS_MENU);
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
