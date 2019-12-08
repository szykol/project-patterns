#include "proxy.h"

#include <cassert>
#include <any>
#include <iostream>

int main() {
    auto qe = QuadraticEquation(1, 2, 3);
    auto qe2 = QuadraticEquation(2, 3, 5);
    auto qe3 = QuadraticEquation(2, 3, 5);
    auto proxy = Proxy();

    auto val = proxy.getValue(&qe);
    auto val2 = proxy.getValue(&qe);
    auto val3 = proxy.getValue(&qe2);
    auto val4 = proxy.getValue(&qe3);

    std::cout<<"Val: "<<std::any_cast<int>(val)<<std::endl;
    std::cout<<"Val2: "<<std::any_cast<int>(val2)<<std::endl;
    std::cout<<"Val3: "<<std::any_cast<int>(val3)<<std::endl;
    std::cout<<"Val4: "<<std::any_cast<int>(val4)<<std::endl;
}