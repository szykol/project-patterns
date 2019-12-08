#include "visitor.h"

#include <vector>

int main() {
    std::vector<Zwierze*> zwierzeta = {
        new Ptak(100, 300, true), new Gad(50, true),
        new Ssak(10, false), new Ssak(20, true), new Ptak(200, 400, false),
        new Ryba(50, false) 
    };

    auto vis = OficjalneCeny();
    vis.visitZwierzeta(zwierzeta);
}