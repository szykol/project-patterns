#include "state.h"

int main() {
    auto f = File();
    f.Open();
    f.Read();
    f.Write();
    f.Close();
    f.Close();
    f.Read();
    f.Write();
}