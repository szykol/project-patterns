#include "subject.h"
#include "observer.h"

#include <algorithm>

void Subject::Attach(Observer* observer) {
    m_observers.push_back(observer);
}

void Subject::Detach(Observer* observer) {
    auto pos = std::find_if(m_observers.begin(), m_observers.end(), [&observer](auto &o) {
        return o == observer;
    });
    if (pos != m_observers.end()) {
        m_observers.erase(pos);
    }
}

void Subject::Notify() {
    std::for_each(m_observers.begin(), m_observers.end(), [=](auto &o) {
        o->Update();
    });
}