#ifndef COLORS_H
#define COLORS_H

#include <stdio.h>
#include "Vectors.h"
#include "Camera.h"
typedef struct color
{
    Vector3 color;
} Color;

#include "Ray.h"
#include "Colorobject.h"
#include "Sphere.h"

// Constants
const double width      = 16.0;
const double height     = 9.0;
const double fov        = 120.0;
const double scalevalue = 2.0;

void writeColor(FILE* f, float ImageWidth, float ImageHeight)
{
    double focalLength   = 1.0;
    double aspect_ratio  = width / height;
    ImageHeight          = (float)(ImageWidth / aspect_ratio);  // derive height from width

    double Viewport_height = 2.0;
    double Viewport_width  = Viewport_height * (width / height);

    // Camera init
    Vector3 Camera_position  = {0.0, 0.0, 0.0};
    Vector3 CameraCenter     = {0.0, 0.0, 0.0};
    Camera camera;
    camera = Camera_init(camera, height, width, fov, Camera_position, CameraCenter);

    // Ray setup
    Vector3 RayDirection = {0.0, 0.0, 0.0};
    Vector3 RayPosition  = {0.0, 0.0, 0.0};
    Ray ray;
    ray = Ray_init(ray, RayPosition, RayDirection);

    Color raycolor = {{1.0, 1.0, 0.0}}; 

    Vector3 vu = {Viewport_width,  0.0, 0.0};
    Vector3 vv = {0.0, Viewport_height, 0.0};

    Vector3 pixeldeltau = Descale(vu, ImageWidth);
    Vector3 pixeldeltav = Descale(vv, ImageHeight);

    Vector3 vec3       = {0.0, 0.0, focalLength};
    Vector3 leftVector = Subtract(CameraCenter, vec3);
    leftVector         = Subtract(leftVector, vv);
    leftVector         = Subtract(leftVector, vu);

    Vector3 pixloc = Add(pixeldeltau, pixeldeltav);
    pixloc         = UpScale(pixloc, 0.5);
    pixloc         = Add(leftVector, pixloc);

    for (size_t j = 0; j < (size_t)ImageHeight; j++)
    {
        for (size_t i = 0; i < (size_t)ImageWidth; i++)
        {
            Vector3 pixelcenter = AddT(pixloc,
                                       Scale(pixeldeltau, (float)i),
                                       Scale(pixeldeltav, (float)j));

            Vector3 raydirection = Subtract(pixelcenter, camera.Camera_position);
            ray = Ray_init(ray, camera.Camera_position, raydirection);

            Color result = colorRAycast(ray, raycolor);

            int ir = (int)(255.999 * result.color.X);
            int ig = (int)(255.999 * result.color.Y);
            int ib = (int)(255.999 * result.color.Z);

            fprintf(f, "%d %d %d\n", ir, ig, ib);
        }
    }
}
#endif
