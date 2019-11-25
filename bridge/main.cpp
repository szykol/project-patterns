#include "bridge.h"

#include <vector>
#include <algorithm>

int main() {
    auto b1 = BibliotekaV2();
    auto b2 = BibliotekaV1();

    std::vector<Figura*> figury = {
        new Okrag(b1),
        new Okrag(b2),
        new Linia(b1),
        new Linia(b2)
    };

    std::for_each(figury.begin(), figury.end(), [](auto f) {
        f->rysuj();
    });
}