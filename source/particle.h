
#pragma once

#include "LinAlgebraLib/vector.h"

class Particle
{
public:
    float potential(Vector3 other)
    {
        
    }
private:
    float mass;
    Vector3 position;
    Vector3 prev_position;
};