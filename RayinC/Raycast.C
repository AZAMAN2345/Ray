#include <stdio.h>
#include "Vectors.h"
#include "Colors.h"
#include "Ray.h"
#include "Colorobject.h"
int main() {
    int ImageWidth = 256;
    int ImageHeight = 256;
FILE *f = fopen("image.ppm", "w");
 if(f == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

     fprintf(f, "P3\n%d %d\n255\n", ImageWidth, ImageHeight);

     writeColor(f,  256, 256 );

    return 0;
    
}
