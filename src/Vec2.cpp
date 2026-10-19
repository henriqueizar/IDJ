#include "Vec2.h"

//inicializacao com valores dados:
Vec2::Vec2(float x, float y) : x(x), y(y) {}

Vec2::Vec2() : x(0), y(0) {}

Vec2 Vec2::operator+(const Vec2& other) const {
    return Vec2(x+other.x,y+other.y);
}

Vec2 Vec2::operator-(const Vec2& other) const {
    return Vec2(x-other.x,y-other.y);
}

Vec2 operator*(const Vec2& v, float scalar){
    return Vec2(v.x*scalar,v.y*scalar);
}

Vec2 operator*(float scalar, const Vec2& v){
    return v*scalar;
}