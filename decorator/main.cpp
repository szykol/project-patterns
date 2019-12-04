#include "decorator.h"

int main() {
    Konfiguracja().getConfiguration(Konfiguracja::Type::FIRST);
    Konfiguracja().getConfiguration(Konfiguracja::Type::SECOND);
}