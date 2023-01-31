#include <iostream>

#include "curves.h"

int main() {
    TCircle circ(1);
    point3D point = circ.coordinate(45);
    std::cout << "x: " << point.x << "\ty: " << point.y << "\tz:" << point.z << "\n";
    return 0;
}