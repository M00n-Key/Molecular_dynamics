
#include "vector.h"

Vector3::Vector3()
{
    this->x = 0.f;
    this->y = 0.f;
    this->z = 0.f;
}

Vector3::Vector3(float x, float y, float z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

Vector3::Vector3(Vector3& copy)
{
    this->x = copy.x;
    this->y = copy.y;
    this->z = copy.z;
}

Vector3& Vector3::operator=(const Vector3& assigned)
{
    this->x = assigned.x;
    this->y = assigned.y;

    return *this;
}

Vector3& Vector3::operator+=(const Vector3& assigned)
{
    return *this = *this + assigned;
}

Vector3 operator+(const Vector3& left, const Vector3& right)
{
    return Vector3(left.x + right.x, left.y + right.y, left.z + right.z);
}

Vector3 operator-(const Vector3& left, const Vector3& right)
{
    return Vector3(left.x - right.x, left.y - right.y, left.z - right.z);
}

Vector3 operator*(const float multiple, const Vector3& vec)
{
    return Vector3(multiple * vec.x, multiple * vec.y, multiple * vec.z);
}

Vector3 operator-(const Vector3& vec)
{
    return (-1) * vec;
}

float Vector3::magnitude()
{
    return sqrtf(this->x * this->x + this->y * this->y + this->z * this->z);
}

Vector3 Vector3::normalize()
{
    return (1 / this->magnitude()) * (*this);
}

float Vector3::dot(const Vector3& left, const Vector3& right)
{
    return left.x * right.x + left.y * right.y + left.z * right.z;
}

Vector3 Vector3::cross(const Vector3& left, const Vector3& right)
{
    return Vector3(
        left.y * right.z - left.z * right.y,
        left.z * right.x - left.x * right.z,
        left.x * right.y - left.y * right.x
    );
}

std::string Vector3::to_string()
{
    return "{ x: " + std::to_string(this->x) + ", y: " + std::to_string(this->y) + ", z: " + std::to_string(this->z) + " }";
}