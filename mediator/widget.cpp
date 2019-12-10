#include "widget.h"

#include "mediator.h"

void Widget::changed() {
    m_director->widgetChanged(this);
}