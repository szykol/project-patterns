#pragma once

#include <iostream>

class Handler {
private:
    Handler* m_parent;
public:
    Handler(Handler* parent) : m_parent(parent) {}
    
    virtual void HandleHelp() {
        std::cout<<"nie potrafie obsluzyc zadania i przekazuje dalen\n";
        if (m_parent != nullptr) {
            m_parent->HandleHelp();
        }
    }

    virtual void ShowHelp() {}
    virtual ~Handler() = 0;
};

Handler::~Handler() {}

class aPrintButton : public Handler {
public:
    aPrintButton(Handler* parent) : Handler(parent) {}
    virtual void HandleHelp() {
        std::cout<<"Print Button | Odebralem zadanie wyswietlneia pomocy\n";
        Handler::HandleHelp();
    }
};

class anOKButton : public Handler {
public:
    anOKButton(Handler* parent) : Handler(parent) {}
    virtual void HandleHelp() {
        std::cout<<"Ok Button | Odebralem zadanie wyswietlneia pomocy\n";
        Handler::HandleHelp();
    }
};

class aPrintDialog : public Handler {
public:
    aPrintDialog(Handler* parent) : Handler(parent) {}
    virtual void HandleHelp() {
        std::cout<<"aPrintDialog | Odebralem zadanie wyswietlneia pomocy\n";
        Handler::HandleHelp();
    }
};

class aSaveDialog : public Handler {
public:
    aSaveDialog(Handler* parent) : Handler(parent) {}
    virtual void HandleHelp() {
        std::cout<<"aSaveDialog | Odebralem zadanie wyswietlneia pomocy\n";
        Handler::HandleHelp();
    }
};

class anApplication : public Handler {
public:
    anApplication(Handler* parent) : Handler(parent) {}
    virtual void HandleHelp() {
        std::cout<<"anApplication | Odebralem zadanie wyswietlneia pomocy\n";
        ShowHelp();
    }
    virtual void ShowHelp() override {
        std::cout<<"Potrafie obsluzyc zadanie wyswietlam pomoc\n";
    }
};