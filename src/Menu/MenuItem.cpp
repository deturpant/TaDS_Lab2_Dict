#include "MenuItem.h"
#include <any>

namespace KVA {

    MenuItem::MenuItem(string _name, MenuItem::func_type _func) {
        name = _name;
        func = _func;
    }

    void MenuItem::run(any &param) {
            return func(param);
    }

    void MenuItem::print() {
        cout << name;
    }
}