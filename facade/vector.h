#pragma once

template<typename T>
class vector3 {
public:
    T x,y,z;
    vector3(T x, T y, T z) : x(x), y(y), z(z) {}
    inline vector3 operator+(const vector3& other) {
        return {x + other.x, y + other.y, z + other.z};
    }
    ~vector3() {}
};

using vector3i = vector3<int>;
using vector3f = vector3<float>;
using vector3u = vector3<unsigned>;
using vector3d = vector3<double>;

template<typename T>
class vector2 {
public:
    T x, y;
    vector2(T x, T y) : x(x), y(y) {}
    inline vector2 operator+(const vector2& other) {
        auto v1 = vector3<T>(x, y, 0);
        auto v2 = vector3<T>(other.x, other.y, 0);

        auto res = v1 + v2;
        return {res.x, res.y};
    }
};

using vector2i = vector2<int>;
using vector2f = vector2<float>;
using vector2u = vector2<unsigned>;
using vector2d = vector2<double>;