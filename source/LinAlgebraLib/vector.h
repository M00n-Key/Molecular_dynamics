
#pragma once

#include <cmath>
#include <string>

class Vector3
{
    friend Vector3 operator+(const Vector3&, const Vector3&);
    friend Vector3 operator-(const Vector3&, const Vector3&);
    friend Vector3 operator*(const float, const Vector3&);
    friend Vector3 operator-(const Vector3&);
public:
    Vector3();
    Vector3(float, float, float);
    Vector3(Vector3&);
    Vector3 & operator=(const Vector3&);

    float magnitude();
    Vector3 normalize();

    float dot(const Vector3&, const Vector3&);
    Vector3 cross(const Vector3&, const Vector3&);

    std::string to_string();

private:
    float x;
    float y;
    float z;
};