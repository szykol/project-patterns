#pragma once 

#include <iostream>

class Figure {
public:
    virtual void repr() = 0;
};

class Line : public Figure {
public:
    virtual void repr() override { std::cout<<"Line\n"; }
};

class Punkt : public Figure {
public:
    virtual void repr() override { std::cout<<"Point\n"; }
};

class BadCircle {
public:
    void bad_repr() { std::cout<<"Bad Repr\n";}
};

class Circle : private BadCircle, public Figure {
public:
    virtual void repr() override { bad_repr(); }
};