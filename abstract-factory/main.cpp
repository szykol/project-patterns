#include "abstract-factory.h"

int main() {
    ApNadzorujaca(Konfiguracja::Type::HIGH).doSomething();
    ApNadzorujaca(Konfiguracja::Type::LOW).doSomething();
}