#include "observer.h"

#include <iostream>

void ConcreteObserver::Update() {
    observerState = subject->GetState();
    std::cout<<"Got state: " << (observerState== ConcreteSubject::State::ACTIVE ? "ACTIVE" : "INACTIVE")<<std::endl; 
}