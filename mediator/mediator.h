#pragma once

#include <string>
#include <memory>
#include <iostream>

#include "widget.h"

class Mediator {
public:
    virtual void showDialog() const = 0;
    virtual void createWidgets() = 0;
    virtual void widgetChanged(Widget *w) = 0;
};

class DialogDirector : public Mediator {
    std::unique_ptr<CheckBox> m_exercises;
    std::unique_ptr<CheckBox> m_exam;
    std::unique_ptr<CheckBox> m_passed;
public:
    enum class TYPE {EXERCISES, EXAM, PASSED};
    virtual void showDialog() const override;
    virtual void createWidgets();
    virtual void widgetChanged(Widget *w);
    void handleInput(TYPE type);
};

