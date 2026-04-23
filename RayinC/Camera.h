#ifndef Camera_H
#define Camera_H
#include<stdio.h>
#include "Vectors.h"
#include "Ray.h"

typedef struct 
{
     double height;
     double width;
     double fov;
Vector3 Camera_position;



    
} Camera;


Camera Camera_init(Camera camera, double height, double width, double fov, Vector3 Camera_position, Vector3 Camera_center)
{ 
    if(height <= 0 || width <= 0) {
        printf("Error: Height and width must be positive values.\n");
        
    
    }

    camera.height = height;
    camera.width = width;
    camera.fov = fov;
    camera.Camera_position = Camera_position;
    

    

    return camera;
}
#endif