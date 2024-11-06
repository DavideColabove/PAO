#include <iostream>

class Point{
    private: 
        double _x, _y, _z;
    public:
        Point(double x=0.0, double y=0.0, double z=0.0);
        double getX() const;
        double getY() const;
        double getZ() const;

        void negate();
        double norm() const;
};

Point operator+(const Point& p1, const Point& p2);

std::&ostream Point operator<<(std::ostream& os, const Point& p);