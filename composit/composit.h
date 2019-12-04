#pragma once

#include <vector>
#include <stdexcept>
#include <iostream>
#include <algorithm>

class Graphic {
    std::vector<Graphic*> m_children;
public:
    Graphic() = default;
    Graphic(std::initializer_list<Graphic*> children) : m_children(children) {

    }

    virtual void Draw() {
        std::for_each(m_children.begin(), m_children.end(), [](auto g) {
            g->Draw();
        });
    }

    virtual void Add(Graphic* child) {
        if (child != nullptr)
            m_children.push_back(child);
    }
    virtual void Remove(int i) {
        try {
            m_children.erase(m_children.begin() + i);
        } catch (std::out_of_range) {
            std::cout<<"Child for that index does not exist\n";
        }
    }
    virtual Graphic* GetChild(int i) {
        try {
            return m_children.at(i);
        } catch (std::out_of_range) {
            return nullptr;
        }
    }

    virtual ~Graphic() = 0;
};

Graphic::~Graphic() {}

class Drawable : public Graphic {
private:
    using Graphic::Add;
    using Graphic::Remove;
    using Graphic::GetChild;
public:
    virtual ~Drawable() = default;
};

class aLine : public Drawable {
public:
    virtual void Draw() override {
        std::cout<<"Drawing Line\n";
    }
    virtual ~aLine() = default;
};

class aRectangle : public Drawable {
public:
    virtual void Draw() override {
        std::cout<<"Drawing Rectangle\n";
    }
    virtual ~aRectangle() = default;
};

class aText : public Drawable {
public:
    virtual void Draw() override {
        std::cout<<"Drawing Text\n";
    }
    virtual ~aText() = default;
};

class aPicture : public Graphic {
public:
    aPicture(std::initializer_list<Graphic*> children) : Graphic(children) {}
    virtual ~aPicture() = default;
};