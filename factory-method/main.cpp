#include "factory-method.h"

#include <iostream>

int main() {
    auto db = "bazabazabazabaza";
    auto q = "SELECT * FROM answers WHERE the_answer_to_life_universe_and_everything=42";
    auto b = SzablonZapytania().utworzBD(SQLType::SQLServer);
    
    SzablonZapytania().wykonajZapytanie(db, q, b);
}