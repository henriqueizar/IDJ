#ifndef VEC2_H
#define VEC2_H



class Vec2 {
    public:
        float x,y;
        Vec2(float x,float y);
        Vec2();

        Vec2 operator+(const Vec2& other) const;
        Vec2 operator-(const Vec2& other) const;
        
};

        Vec2 operator*(const Vec2& v, float scalar);  // v * 2.0f
        Vec2 operator*(float scalar, const Vec2& v); 

#endif
