#pragma once

#include <string>

class DialogDirector;

class Widget {
    DialogDirector *m_director;
public:
    Widget(DialogDirector *director) : m_director(director) {}
    virtual void changed();
};

class CheckBox : public Widget {
    bool checked = false;
    std::string title = "";
public:
    CheckBox(DialogDirector* director, std::string title, bool checked=false) : Widget(director), title(title), checked(checked) {}
    bool getState() const { return checked; }
    void setState() { checked = !checked; changed(); }
    void setState(bool check) {checked = check; changed(); }
    std::string getTitle() const { return title; }
};
