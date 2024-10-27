//
//  vec3d.h
//  vectorcal
//
//  Created by Berkay Sarmasoğlu on 10.10.2024.
//
#include <cmath>

class Vector3D{
public:
    double i, j, k;
    
    Vector3D(double x, double y, double z){
        this->i = x;
        this->j = y;
        this->k = z;
    }
    
    double magnitude(){
        return sqrt(pow(this->i, 2) + pow(this->j, 2) + pow(this->k, 2));

    }
    
    Vector3D operator+(Vector3D vec){
        return Vector3D(this->i + vec.i, this->j + vec.j, this->k + vec.k);
    }
    
    Vector3D operator-(){
        return Vector3D(this->i * -1, this->j * -1, this->k * -1);
    }
    
    Vector3D operator-(Vector3D vec){
        return Vector3D(this->i - vec.i, this->j - vec.j, this->k - vec.k);
    }
    
    Vector3D operator*(Vector3D vec){
        Vector3D x(0,0,0);
        // [i,j,k]
        // [3,4,12]
        // [2,2,1]
        x.i = this->j * vec.k - this->k * vec.j;
        x.j = -(this->i * vec.k - this->k * vec.i);
        x.k = this->i * vec.j - this->j * vec.i;
        return x;
    }
    
    Vector3D vector_product(Vector3D vec){
        return *this * vec;
    }
    
    double scalar_product(Vector3D vec){
        return (this->i * vec.i + this->j * vec.j + this->k * vec.k);
    }
    
    double angle_between(Vector3D vec){
        // a- * b- = a * b * cosx
        double cosx =this->scalar_product(vec) / (this->magnitude() * vec.magnitude());
        return acos(cosx) * 180 / M_PI;
    }
};
