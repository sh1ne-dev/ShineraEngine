#include <ostream>

#ifndef VECTORS
#define VECTORS

struct Vec2 {
    float x;
    float y;
    
    Vec2() {}

    Vec2(float xy) : x(xy), y(xy) {}

    Vec2(float x, float y): x(x), y(y) {}

    Vec2 operator+(const Vec2& other) {
        return Vec2(x + other.x, y + other.y);
    }

    Vec2 operator-(const Vec2& other) {
        return Vec2(x - other.x, y - other.y);
    }

    Vec2 operator/(const Vec2& other) {
        return Vec2(x / other.x, y / other.y);
    }

    Vec2 operator*(const Vec2& other) {
        return Vec2(x * other.x, y * other.y);
    }

    friend std::ostream& operator<<(std::ostream& os, const Vec2& vec) {
        os << "X: " << vec.x << ", Y: " << vec.y;
        return os;
    }
};

struct Vec3 {
    float x;
    float y;
    float z;
    
    Vec3() {}

    Vec3(float xyz) : x(xyz), y(xyz), z(xyz) {}

    Vec3(float x, float y, float z): x(x), y(y), z(z) {}

    Vec3 operator+(const Vec3& other) {
        return Vec3(x + other.x, y + other.y, z + other.z);
    }

    Vec3 operator-(const Vec3& other) {
        return Vec3(x - other.x, y - other.y, z - other.z);
    }

    Vec3 operator/(const Vec3& other) {
        return Vec3(x / other.x, y / other.y, z / other.z);
    }

    Vec3 operator*(const Vec3& other) {
        return Vec3(x * other.x, y * other.y, z * other.z);
    }

    friend std::ostream& operator<<(std::ostream& os, const Vec3& vec) {
        os << "X: " << vec.x << ", Y: " << vec.y << ", Z: " << vec.z;
        return os;
    }
};

struct Vec4 {
    float x;
    float y;
    float z;
    float w;
    
    Vec4() {}

    Vec4(float xyzw) : x(xyzw), y(xyzw), z(xyzw), w(xyzw) {}

    Vec4(float x, float y, float z, float w): x(x), y(y), z(z), w(w) {}

    Vec4 operator+(const Vec4& other) {
        return Vec4(x + other.x, y + other.y, z + other.z, w + other.w);
    }

    Vec4 operator-(const Vec4& other) {
        return Vec4(x - other.x, y - other.y, z - other.z, w - other.w);
    }

    Vec4 operator/(const Vec4& other) {
        return Vec4(x / other.x, y / other.y, z / other.z, w / other.w);
    }

    Vec4 operator*(const Vec4& other) {
        return Vec4(x * other.x, y * other.y, z * other.z, w * other.w);
    }

    friend std::ostream& operator<<(std::ostream& os, const Vec4& vec) {
        os << "X: " << vec.x << ", Y: " << vec.y << ", Z: " << vec.z << ", W: " << vec.w;
        return os;
    }
};

#endif