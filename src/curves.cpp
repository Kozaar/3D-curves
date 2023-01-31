#include "curves.h"
#include <cmath>

THelix::THelix(const double &radiusX, const double &radiusY, const double &step) : TCurve(radiusX, radiusY, step) {
}

point3D THelix::coordinate(double t) {
    point3D point;
    t /= 180 / M_PI;
    point.x = cos(t);
    point.y = sin(t);
    point.z = rz_ * t;
    return point;
}

point3D THelix::derivate(double t) {
    point3D point;
    t /= 180 / M_PI;
    point.x = rx_ * cos(t);
    point.y = ry_ * sin(t);
    point.z = rz_ * t;
    return point;
}

TEllipce::TEllipce(const double &radiusX, const double &radiusY) : THelix(radiusX, radiusY, 0){
}

point3D TEllipce::coordinate(double t) {
    return THelix::coordinate(t);
}

point3D TEllipce::derivate(double t) {
    return THelix::derivate(t);
}
TCircle::TCircle(const double &radius) : TEllipce(radius, radius) {
}

point3D TCircle::coordinate(double t) {
    return TEllipce::coordinate(t);
}

point3D TCircle::derivate(double t) {
    return TEllipce::derivate(t);
}
