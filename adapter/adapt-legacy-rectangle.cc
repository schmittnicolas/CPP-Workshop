#include "adapt-legacy-rectangle.hh"

#include <iostream>

AdaptLegacyRectangle::AdaptLegacyRectangle(LegacyRectangle& rect)
    : rect_(rect)
{}

AdaptLegacyRectangle::~AdaptLegacyRectangle()
{}

void AdaptLegacyRectangle::print() const
{
    std::cout << "x: " << rect_.x1_get() << " y: " << rect_.y1_get() << "\n";
    int height = rect_.y2_get() - rect_.y1_get();
    if (height < 0)
        height = -height;
    int width = rect_.x2_get() - rect_.x1_get();
    if (width < 0)
        width = -width;
    std::cout << "height: " << height << "\n";
    std::cout << "width: " << width << "\n";
}

unsigned AdaptLegacyRectangle::area() const
{
    return rect_.compute_area();
}
