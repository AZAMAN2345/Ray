#ifndef Ray_H
#define Ray_H
#include<stdio.h>
#include "Vectors.h"
#include "Colors.h"
#include "Colorobject.h"

typedef struct ray
{
     
  Vector3 origin;
  Vector3 direction;
Color color;
    double t;
} Ray;


Ray Ray_init(Ray ray, Vector3 origin, Vector3 direction) {
    ray.origin    = origin;
    ray.direction = direction;
    ray.t         = 0.0;

    return ray;
}


Vector3 Ray_at(Ray ray, double t) {
    Vector3 result;
    result.X = ray.origin.X + t * ray.direction.X;
    result.Y = ray.origin.Y + t * ray.direction.Y;
    result.Z = ray.origin.Z + t * ray.direction.Z;
    return result;
}


#endif 