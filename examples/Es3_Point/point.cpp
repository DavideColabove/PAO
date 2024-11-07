#include <cmath>
#include <iostream>
#include "point.h"

Point::Point (int x, int y, int z) {
    _x = x;
    _y = y;
    _z = z;
}

void Point::negate() {
    _x = _x*(-1);
    _y = _y*(-1);
    _z = _z*(-1);
}

double Point::getX() const{
    return _x;
}

double Point::getY() const{
    return _y;
}

double Point::getZ() const{
    return _z;
}

double Point::norm() const{
    return sqrt(_x*_x + _y*_y + _z*_z); 
}

Point operator+(const Point& p1, const Point& p2){
    return Point(p1.getX() + p2.getX(), p1.getY() + p2.getY(), p1.getZ() + p2.getZ());
}

std::&ostream operator<<(std::ostream& os, const Point& p){
    return os << "(" << p.getX() << "," << p.getY() << "," << p.getZ() << ")";
}

int main() {
    point p1(1,2,3);
    point p2(4,5,6);
    point p3 = p1 + p2;
    cout << p3 << endl;
}