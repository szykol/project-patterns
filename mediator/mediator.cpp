#include "mediator.h"

#include "widget.h"

void DialogDirector::showDialog() const {
    std::cout<<m_exercises->getTitle()<<"["<<(m_exercises->getState() ? 'X' : ' ')<<"]\n";
    std::cout<<m_exam->getTitle()<<"["<<(m_exam->getState() ? 'X' : ' ')<<"]\n";
    std::cout<<m_passed->getTitle()<<"["<<(m_passed->getState() ? 'X' : ' ')<<"]\n";
    std::cout<<"-------------------------------------------\n";
}
void DialogDirector::createWidgets() {
    m_exercises = std::make_unique<CheckBox>(this, "Cwiczenia zaliczone");
    m_exam = std::make_unique<CheckBox>(this, "Egzamin zaliczony");
    m_passed = std::make_unique<CheckBox>(this, "Przedmiot zaliczony");
}
void DialogDirector::widgetChanged(Widget *w) {
    if (w == m_passed.get()) {
        auto state = m_passed->getState();
        // this should also set the other one to true
        if (state)
            m_exam->setState(state);
    } else if (w == m_exam.get()) {
        auto state = m_exam->getState();

        if (state)
            m_exercises->setState(state);
        else
            m_passed->setState(state);
    } else if (w == m_exercises.get()) {
        auto state = m_exercises->getState();

        if (!state) {
            m_passed->setState(state);
        }
    }
}
void DialogDirector::handleInput(TYPE type) {
    if (type == TYPE::PASSED) {
        m_passed->setState();
    } else if (type == TYPE::EXERCISES) {
        m_exercises->setState();
    } else if (type == TYPE::EXAM) {
        m_exam->setState();
    }
}