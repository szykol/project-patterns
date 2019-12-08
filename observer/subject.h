#pragma once

#include <vector>

class Observer;

class Subject
{
private:
    std::vector<Observer*> m_observers;
public:
    Subject() = default;
    void Attach(Observer* observer);
    void Detach(Observer* observer);
    void Notify();
    ~Subject() = default;
};

class ConcreteSubject : public Subject {
public:
    enum class State {ACTIVE, INACTIVE};
private:
    State subjectState = State::INACTIVE;
public:
    virtual State GetState() const { return subjectState; }
    virtual void SetState(State st) { subjectState = st; Notify(); }
};