#pragma once

#include "subject.h"

class Observer {
public: 
    virtual void Update() = 0;
};

class ConcreteObserver : public Observer {
    ConcreteSubject* subject;
private:
    ConcreteSubject::State observerState;
public:
    ConcreteObserver(ConcreteSubject* cs) : subject(cs) {}
    virtual void Update() override;
};
