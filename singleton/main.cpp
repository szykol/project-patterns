#include <iostream>
#include "singleton.h"

#include <cassert>

int main() {
    auto first = Singleton::getInstance();
    auto second = Singleton::getInstance();

    assert(first == second);
}