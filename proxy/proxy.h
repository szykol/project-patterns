#pragma once
#include <any>

#include <iostream>

class Cacheable {
public:
    virtual bool operator==(const Cacheable&) const = 0;
    virtual std::any compute() = 0;
};

class QuadraticEquation : public Cacheable {
private:
    int a,b,c;
public:
    QuadraticEquation(int a, int b, int c) : a(a), b(b), c(c) {}
    virtual bool operator==(const Cacheable& cacheable) const override {
        auto qe = dynamic_cast<const QuadraticEquation*>(&cacheable);
        if (qe == nullptr) return false;
        return a == qe->a && b == qe->b && c == qe->c;
    }
    virtual std::any compute() {
        return a + b + c;
    }
};

class Proxy {
private:
    Cacheable* m_cacheable = nullptr;
    std::any m_cachedVal;
public:
    std::any getValue(Cacheable* cacheable) {
        if (m_cacheable != nullptr && *cacheable == *m_cacheable) {
            std::cout<<"Returning cached value\n";
            return m_cachedVal;
        } else {
            std::cout<<"Calculating cached value\n";
            m_cacheable = cacheable;
            return (m_cachedVal = cacheable->compute());
        }
    }
};