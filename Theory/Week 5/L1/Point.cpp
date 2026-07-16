#include "Point.h"
#include <stdexcept>

point2D::point2D() : x(0), y(0) {}

point2D::point2D(float x, float y) : x(x), y(y) {
    if (x < 0 || y < 0 || x > 1920 || y > 1080) {
        throw std::invalid_argument("Coordinates must be within the screen bounds.");
    }
}