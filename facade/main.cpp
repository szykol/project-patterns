#include "vector.h"

#include <cassert>

int main() {
    auto v1 = vector3i(3, 4, 5);
    auto v2 = vector3i(5, 4, 3);

    auto sum = v1 + v2;
    assert(sum.x == sum.y and sum.y == sum.z and sum.z == 8);

    auto v3 = vector2i(1, 2);
    auto v4 = vector2i(3, 2);

    auto sum2 = v3 + v4;
    assert(sum2.x == sum2.y and sum2.y == 4);
}