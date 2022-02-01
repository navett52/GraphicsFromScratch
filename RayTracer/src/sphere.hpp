#pragma once

#include "vec3.hpp"
#include "color.hpp"

class Sphere
{
public:
    Vec3 origin;
    double radius;
    Color color;
    int spec; // Specular exponent

    Sphere(Vec3 origin, double radius, Color color, int spec)
        :origin(origin), radius(radius), color(color), spec(spec) {};
};
