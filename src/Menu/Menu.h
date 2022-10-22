#pragma once
#include <iostream>
#include <string>
#include <any>
#include <vector>

namespace KVA {

    class Menu {
        public:
            using func = void(*)(std::vector<std::any>);
            Menu(std::string lable, func function);
            Menu(std::string lable, std::vector<Menu> menus);
            Menu(const Menu& menu);

            void run(std::vector<std::any> params);
            void printMenu();
            std::string getLable();

            template<typename T>
            static T input() {
                T num = 0;
                bool flag = true;
                while (flag) {
                    if (std::cin >> num) {
                        flag = false;
                    } else {
                        std::cin.clear();
                        while (std::cin.get() != '\n');
                    }
                }

                return num;
            }

        private:

            std::string lable{};
            std::vector<Menu> menus{};
            func function = nullptr;
    };
}