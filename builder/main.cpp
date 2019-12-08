#include "builder.h"

#include <iostream>

int main() {
    auto in = "A<b>l</b>a ma <i>k</i>o<u>t</u>a";
    auto conv = UpperCaseLeaveTag();
    auto reader = HTMLReader(conv);

    auto out = reader.convertInput(in);
    std::cout<<out<<std::endl;
}