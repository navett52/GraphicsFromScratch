#pragma once

#include <math.h>
#include <vector>
#include <typeinfo>
#include <string>
#include <bits/stdc++.h>

#include "../math/vec3.hpp"
#include "../object/sphere.hpp"
#include "../object/light.hpp"
#include "canvas.hpp"

class Camera
{
public:
    Vec3 position = Vec3(0, 0, 0);
    Vec3 direction = Vec3(0, 0, 1);
    double max_d = DBL_MAX;

    Camera() = default;
    Camera(Vec3 position, Vec3 direction, double maxRenderDistance)
        : position(position), direction(direction), max_d(maxRenderDistance) {};

    Uint32 traceRay(double stepMin, Canvas* canvas, std::vector<Sphere> spheres, std::vector<Light*> lights);
    void closestIntersection(double stepMin, std::vector<Sphere> spheres, double* closestStep, Sphere** closestSphere);
    double* intersectRaySphere(Sphere* sphere);
    double computeLighting(Vec3 point, Vec3 normal, Vec3 view, int spec, std::vector<Light*> lights);
};
