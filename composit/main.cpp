#include "composit.h"

int main() {
    auto r = aPicture({new aLine(), new aRectangle(), new aPicture({new aText(), new aLine(), new aRectangle()}), new aLine()});
    r.Draw();
}