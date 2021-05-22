#include <iostream>
#include <string>
//#include "function.h"
#include <cmath>

#include "11443.h"
using namespace std;
//Partial judge
namespace oj {
Sphere::Sphere(double radius, double pi) {
    this->radius = radius;
    this->pi = pi;
    if (radius <= 0 || pi <= 0) {
        setVolume(0);
    } else {
        setVolume(4.0 / 3.0 * pi * pow(radius, 3));  // V = 4/3*pi*r^3
    }
}
Cone::Cone(double radius, double height, double pi) {
    this->radius = radius;
    this->height = height;
    this->pi = pi;
    if (radius <= 0 || height <= 0 || pi <= 0) {
        setVolume(0);
    } else {
        setVolume(1.0 / 3.0 * pi * radius * radius * height);  // V = 1/3*pi*r^2*h
    }
}
Cuboid::Cuboid(double length, double width, double height) {
    this->length = length;
    this->width = width;
    this->height = height;
    if (length <= 0 || width <= 0 || height <= 0) {
        setVolume(0);
    } else {
        setVolume(length * width * height);
    }
}
Cube::Cube(double length) : Cuboid(length, length, length) {  //Inheritance
    //this -> length = length;
    if (length <= 0) {
        setVolume(0);
    } else {
        setVolume(pow(length, 3));
    }
}
}  // namespace oj
//
namespace oj {
void Shape3D::setVolume(double v) {
    volume = v;
}

double Shape3D::getVolume() {
    return volume;
}
}  // namespace oj

int main(void) {
    using namespace oj;

    string s;
    double a, b, c;
    double totalVolume = 0.0, totalPerimeter = 0.0;

    while (cin >> s) {
        if (s == "Sphere") {
            cin >> a >> b;
            Sphere sphere(a, b);
            totalVolume += sphere.getVolume();
            //cout << "Ball: " << sphere.getVolume() << endl;
        }
        if (s == "Cone") {
            cin >> a >> b >> c;
            Cone cone(a, b, c);
            totalVolume += cone.getVolume();
            //cout << "Cone: " << cone.getVolume() << endl;
        }
        if (s == "Cuboid") {
            cin >> a >> b >> c;
            Cuboid cuboid(a, b, c);
            totalVolume += cuboid.getVolume();
            //cout << "Cuboid: " << cuboid.getVolume() << endl;
        }
        if (s == "Cube") {
            cin >> a;
            Cube cube(a);
            totalVolume += cube.getVolume();
            //cout << "Cube: " << cube.getVolume() << endl;
        }
    }

    cout << totalVolume << endl;

    return 0;
}