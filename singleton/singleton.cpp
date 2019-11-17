#include "singleton.h"

#include <iostream>

Singleton* Singleton::instance = nullptr;

Singleton::Singleton() {
    std::cout<<"Creating an instance of a class\n";
}

Singleton::~Singleton() {

}

Singleton* Singleton::getInstance()
{
    std::cout<<"Getting an instance of a class\n";
    if (Singleton::instance == nullptr) {
        std::cout<<"Creating instance of a classss\n";
        Singleton::instance = new Singleton();
    }

    return Singleton::instance;
}