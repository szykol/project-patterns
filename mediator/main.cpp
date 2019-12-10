#include "mediator.h"

int main() {
    auto d = DialogDirector();

    d.createWidgets();
    d.showDialog();
    d.handleInput(DialogDirector::TYPE::PASSED);
    d.showDialog();
    d.handleInput(DialogDirector::TYPE::EXAM);
    d.showDialog();
    d.handleInput(DialogDirector::TYPE::PASSED);
    d.showDialog();
}