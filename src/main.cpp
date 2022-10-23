#include <iostream>
#include "Menu/MenuItem.h"
#include "Menu/MyMenu.h"
#include "BinTree/BinTree.h"
#include <string>
#include <any>
#include <fstream>
#include <cstring>

#define LOAD_TREE auto *bt = any_cast<BinTree *>(param);

using namespace KVA;

void loadDictSmall(any &param) {
    LOAD_TREE
    fstream file;
    string s;
    file.open("itog.txt");
    while (getline(file, s)) {
        bt->insert(s);
    }
    file.close();
}
void loadDictBig(any &param) {
    LOAD_TREE
    fstream file;
    string s;
    file.open("big-r.txt");
    while (getline(file, s)) {
        bt->insert(s);
    }
    file.close();
}
void addToTree(any &param) {
    LOAD_TREE
    std::cout << "Пожалуйста, введите новое слово  --> ";
    std::string _data;
    std::cin >> _data;
    bt->insert(_data);
    std::cout << "Слово успешно добавлено!\n";
}
void InitData(string file_name, BinTree *bt) {
    fstream file;
    string s;
    file.open(file_name);
    while (getline(file, s)) {
        bt->insert(s);
    }
    file.close();
}
void SaveData(string file_name, BinTree *bt) {
    ofstream file;
    string s;
    file.open(file_name, std::ios::out);
    s = bt->clearTree(s);
    file << s;
    file.close();
}
void printTree(any &param) {
    LOAD_TREE
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
    LOAD_TREE
    std::cout << "Пожалуйста, введите слово для удаления  --> ";
    std::string _data;
    std::cin >> _data;
    //нужно допилить!
    bt->deleteEl(_data);
    std::cout << "Слово успешно удалено!\n";
}

void clearTree(any &param) {
    LOAD_TREE
    bt->clearTree("");
    cout << "Очистка словаря завершена.\n";
}

void getCountWord(any &param) {
    LOAD_TREE
    if (bt->getCountElement() != 0) {
        cout << "Количество слов в словаре: " << bt->getCountElement() << " слов.\n";
    } else {
        cout << "Словарь пуст";
    }
}

void checkWord(any &param) {
    LOAD_TREE
    std::cout << "Пожалуйста, введите слово для проверки  --> ";
    std::string _data;
    std::cin >> _data;
    bt->findElement(_data);
}

void ext(any& param) {
    LOAD_TREE
    cout << "Выполняется сохранение данных в выходной файл";
    SaveData("data2.txt", bt);
    exit(0);
}

string MyException::file_name = "logs.txt";
const int ITEMS_MENU = 9;

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
    InitData(load_data_file, bt);
    MenuItem items[ITEMS_MENU]{
            MenuItem{"Добавить слово в словарь", addToTree},
            MenuItem{"Распечатать словарь", printTree},
            MenuItem{"Удалить слово из словаря", deleteEl},
            MenuItem{"Очистить словарь", clearTree},
            MenuItem{"Загрузить в словарь существительные (51.000+ слов)", loadDictSmall},
            MenuItem{"Загрузить в словарь 1.500.000+ русских слов", loadDictBig},
            MenuItem{"Получить количество слов в словаре", getCountWord},
            MenuItem{"Проверить правописание слова", checkWord},
            MenuItem{"Выход из программы", ext}
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
