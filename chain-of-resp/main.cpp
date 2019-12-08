#include "chain.h"

int main() {
    auto ap = anApplication(nullptr);

    auto svdlg = aSaveDialog(&ap);
    auto aprdlg = aPrintDialog(&ap);

    auto aprbtn = aPrintButton(&aprdlg);
    auto anokButton = anOKButton(&aprdlg);

    aprbtn.HandleHelp();
}