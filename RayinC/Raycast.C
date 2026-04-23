#include <stdio.h>
#include "Vectors.h"
#include "Colors.h"
#include "Ray.h"
#include "Colorobject.h"
int main() {
    int ImageWidth = 256;
    int ImageHeight = 256;
   Color raycolor = {1.0, 1.0, 0};
 Vector3 color = {0, 0, 255};
 
 Vector3 Rayposition = {1.0, 1.0, 1.0};
 Vector3 Raydirection = {0.0, 0.0, -1.0};

 Ray ray;
 Vector3 Camera_position = {0.0, 0.0, 0.0};
FILE *f = fopen("image.ppm", "w");
 if(f == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

     fprintf(f, "P3\n%d %d\n255\n", ImageWidth, ImageHeight);

     writeColor(f,  256, 256 );
    
     
   
 fclose(f); 




  
   


    return 0;
    
}