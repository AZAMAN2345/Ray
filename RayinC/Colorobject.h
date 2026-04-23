#ifndef Colorobject_H
#define Colorobject_H
#include<stdio.h>
#include "Vectors.h"    
#include "Colors.h"
#include "Ray.h"
#include"Sphere.h"

Color colorRAycast(Ray ray, Color color)
{
   ray.color = color;
Vector3 unitvector = UnitVector(ray.direction);
auto a = 0.5 * (unitvector.Y + 1.0);
 
return color;


}
 Color Colorsphere(Sphere sphere, Ray ray)
 {
     if (HitSphere(sphere, sphere.center, sphere.Origin, sphere.radius, sphere.color, ray)) {
         return sphere.color;
     }
     Vector3 unit_direction = UnitVector(ray.direction);
     auto t = 0.5 * (unit_direction.Y + 1.0);
     Vector3 white = {1.0, 1.0, 1.0};
     Vector3 blue = {0.5, 0.7, 1.0};
     Vector3 blended_color = Add(Scale(white, (1.0 - t)), Scale(blue, t));
     Color result;
     result.color = blended_color;
     return result;
 }

#endif