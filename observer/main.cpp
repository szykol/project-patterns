#include "observer.h"

#include <iostream>

int main() {
    auto cs = ConcreteSubject();
    auto obs = ConcreteObserver(&cs);
    cs.Attach(&obs);
    cs.SetState(ConcreteSubject::State::ACTIVE);
    auto obs2 = ConcreteObserver(&cs);
    cs.Attach(&obs2);
    cs.SetState(ConcreteSubject::State::INACTIVE);
    cs.Detach(&obs);
    cs.SetState(ConcreteSubject::State::ACTIVE);
}