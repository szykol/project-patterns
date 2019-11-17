#include "figury.h"

#include <vector>
#include <algorithm>

int main() {
    std::vector<Figure*> figures = {new Line(), new Punkt(), new Circle()};
    
    std::for_each(figures.begin(), figures.end(), [](Figure* f) {
        f->repr();
        delete f;
    });
}