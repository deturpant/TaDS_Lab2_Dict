//
// Created by deturpant on 22.10.22.
//
#pragma once

#include <iostream>
#include <string>
#include <any>
#include "../Exceptions/MyException.h"

using namespace std;
namespace KVA {

    class MenuItem {
    public:
        using func_type = void (*)(any &param);

        MenuItem(string _name, func_type _func);

        void run(any &param);

        void print();


    private:
        std::string name{};
        func_type func;
    };
}