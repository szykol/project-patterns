#include "list.h"
#include "listiter.h"
#include <iostream>

int main() {
    List<int> l({0, 1, 0, 3, 5});

    auto it = l.getNotZero();

    auto it2 = l.getNotZero();
    while(!it2.IsDone()) {
        std::cout<<it2.CurrentItem()<<std::endl;
        it2.Next();
    }
}