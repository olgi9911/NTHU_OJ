#include <iostream>
#include <string>
//#include "function.h"
#include <cmath>

#include "11422.h"
using namespace std;
///Partial Judge
namespace oj {
Triangle::Triangle(double edge1, double edge2, double edge3) {
    this->edge1 = edge1;
    this->edge2 = edge2;
    this->edge3 = edge3;
    if (edge1 <= 0 || edge2 <= 0 || edge3 <= 0 ||
        edge1 + edge2 <= edge3 || edge1 + edge3 <= edge2 || edge2 + edge3 <= edge1) {
        setArea(0);
        setPerimeter(0);
    } else {
        double s = (edge1 + edge2 + edge3) / 2;
        setArea(sqrt(s * (s - edge1) * (s - edge2) * (s - edge3)));  //Heron's formula
        setPerimeter(s * 2);
    }
}

Rectangle::Rectangle(double width, double height) {
    this->width = width;
    this->height = height;
    if (width <= 0 || height <= 0) {
        setArea(0);
        setPerimeter(0);
    } else {
        setArea(width * height);
        setPerimeter(2 * (width + height));
    }
}

Circle::Circle(double radius, double pi) {
    this->radius = radius;
    this->pi = pi;
    if (radius <= 0 || pi <= 0) {
        setArea(0);
        setPerimeter(0);
    } else {
        setArea(radius * radius * pi);
        setPerimeter(2 * radius * pi);
    }
}
}  // namespace oj
///
namespace oj {
void Shape::setArea(double a) {
    area = a;
}

void Shape::setPerimeter(double p) {
    perimeter = p;
}

double Shape::getArea() {
    return area;
}

double Shape::getPerimeter() {
    return perimeter;
}
}  // namespace oj

int main(void) {
    using namespace oj;

    string s;
    double a, b, c;
    double totalArea = 0.0, totalPerimeter = 0.0;

    while (cin >> s) {
        if (s == "Triangle") {
            cin >> a >> b >> c;
            Triangle T(a, b, c);
            totalArea += T.getArea();
            totalPerimeter += T.getPerimeter();
        }
        if (s == "Rectangle") {
            cin >> a >> b;
            Rectangle R(a, b);
            totalArea += R.getArea();
            totalPerimeter += R.getPerimeter();
        }
        if (s == "Circle") {
            cin >> a >> b;
            Circle C(a, b);
            totalArea += C.getArea();
            totalPerimeter += C.getPerimeter();
        }
    }

    cout << totalArea << endl;
    cout << totalPerimeter << endl;

    return 0;
}