#include "template_method.h"

#include <iostream>

int main() {
    ZapytanieOracle orac;
    ZapytanieSQLServer sqlserv;

    auto db = "bazabazabazabaza";
    auto q = "SELECT * FROM answers WHERE the_answer_to_life_universe_and_everything=42";
    orac.wykonajZapytanie(db, q);
    sqlserv.wykonajZapytanie(db, q);
}