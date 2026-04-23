#ifndef VECTORS_H
#define VECTORS_H
#include <stdio.h>
#include<math.h>
 typedef struct  vector3
 {
     double X;
    double Y;
    double Z;

    
    } Vector3;   
 
    double vec3 ( Vector3 v , double x, double y, double z)
    {
        v.X = x;
        v.Y = y;
        v.Z = z;

        return x, y, z;

     
    }

    Vector3 printVector(Vector3 v)
    {
        printf("Vector: (%.2f, %.2f, %.2f)\n", v.X, v.Y, v.Z);
        return v;
    }
   

    Vector3 Add(Vector3 v1, Vector3 v2)
    { Vector3 result;
        result.X = v1.X + v2.X;
        result.Y = v1.Y + v2.Y;
        result.Z = v1.Z + v2.Z;
       return result;
    
     
    }

        Vector3 AddT(Vector3 v1, Vector3 v2, Vector3 v3)
    { Vector3 result;
        result.X = v1.X + v2.X + v3.X;
        result.Y = v1.Y + v2.Y + v3.Y;
        result.Z = v1.Z + v2.Z + v3.Z;
       return result;
    
     
    }
    
    Vector3 Subtract(Vector3 v1, Vector3 v2)
    { Vector3 result;
        result.X = v1.X - v2.X;
        result.Y = v1.Y - v2.Y;
        result.Z = v1.Z - v2.Z;
        return result;
      
    }   

     Vector3 Scale(Vector3 v, double scalar)
    { Vector3 result;
        result.X = v.X * scalar;
        result.Y = v.Y * scalar;
        result.Z = v.Z * scalar;
      return result;
    }

    void Lenght(Vector3 v)
    {
        double length = sqrt(v.X * v.X + v.Y * v.Y + v.Z * v.Z);
        printf("Length: %.2f\n", length);
        return;
    }

    void Normalize(Vector3 v)
    {
        double length = sqrt(v.X * v.X + v.Y * v.Y + v.Z * v.Z);
        if (length > 0) {
            
            v.X /= length;
            v.Y /= length;
            v.Z /= length;
        }
         
    }
    Vector3 Descale (Vector3 v, double scalar)
    { Vector3 result;
        result.X = v.X / scalar;
        result.Y = v.Y / scalar;
        result.Z = v.Z / scalar;
      return result;
    }

   Vector3 UnitVector(Vector3 v)
    {
        double Magnitude = sqrt(v.X * v.X + v.Y * v.Y + v.Z * v.Z);
        Vector3 result;
        if (Magnitude > 0) {
            result.X = v.X / Magnitude;
            result.Y = v.Y / Magnitude;
            result.Z = v.Z / Magnitude;
        }
        return result;
    }
    Vector3 dotproduct(Vector3 v1, Vector3 v2)
    {
        Vector3 result;
        result.X = v1.X * v2.X;
        result.Y = v1.Y * v2.Y;
        result.Z = v1.Z * v2.Z;
        return result;
    }
    Vector3 SubtractInteger(Vector3 v1, double v2)
    { Vector3 result;
        result.X = (int)v1.X - v2;
        result.Y = (int)v1.Y - v2;
        result.Z = (int)v1.Z - v2;
        return result;
      
    }
    Vector3 MultiplyVector(Vector3 v1, Vector3 v2)
    { Vector3 result;
        result.X = v1.X * v2.X;
        result.Y = v1.Y * v2.Y;
        result.Z = v1.Z * v2.Z;
        return result;
      
    }
Vector3 UpScale(Vector3 v1, double scale){
Vector3 result;

result.X = v1.X *scale;
result.Y = v1.Y *scale;
result.Z = v1.Z *scale;

return result;
   }
    #endif