#ifndef Sphere_H
#define Sphere_H
#include<stdbool.h>
#include<stdio.h>
#include "Vectors.h"
#include "Colors.h"
#include "Ray.h"
typedef struct sphere
{   
    float radius;
    Vector3 center;
    Vector3 Origin;
    Color color;

} Sphere;


bool HitSphere(Sphere sphere, Vector3 center, Vector3 origin, float radius, Color color, Ray ray)
{
    (void)center;
    (void)origin;
    (void)color;
    Vector3 oc = Subtract(sphere.center, ray.origin);
    Vector3 x = dotproduct(ray.direction, ray.direction);
    Vector3 Y = dotproduct(ray.direction, oc);
    Vector3 y = Scale(Y, -2.0);
    Vector3 Z= dotproduct(oc, oc);
    Vector3 z = SubtractInteger(Z, radius * radius);
    Vector3 Ymulti = MultiplyVector(y,y);
    Vector3 Xymulti = MultiplyVector(x, z);
    Vector3 scaledxymulti = Scale(Xymulti, 4.0);
    Vector3 discriminant = Subtract(Ymulti, scaledxymulti);

  return (discriminant.X >= 0 && discriminant.Y >= 0 && discriminant.Z >= 0);

}
#endif
  
