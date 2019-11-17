#include <iostream>
#include "singleton.h"

#include <cassert>

int main() {
    Singleton one;
    Singleton two;

    auto first = one.getInstance();
    auto second = two.getInstance();

    assert(first == second);
}