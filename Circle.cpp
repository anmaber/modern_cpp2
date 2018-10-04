#include "Circle.hpp"
#include <math.h>
#include <iostream>

Circle::Circle(double r)
    : Circle(r,Color::Green)
{}

Circle::Circle(double r, Color c)
: r_(r),Shape(c){}
/*
Circle::Circle(const Circle & other)
{
    r_ = other.getRadius();
}

Circle::Circle(Circle &&other):r_(std::move(other.r_)) {}


Circle& Circle::operator=(Circle &&other)
        {
        r_=std::move(other.r_);
        return *this;
        }
*/
double Circle::getArea() const
{
    return M_PI * r_ * r_;
}

double Circle::getPerimeter() const
{
    return 2 * M_PI * r_;
}

double Circle::getRadius() const
{
    return r_;
}

double Circle::getPi() const {return M_PI;}

void Circle::print() const
{
    std::cout << "Circle: radius: " << getRadius() << std::endl
              << "          area: " << getArea() << std::endl
              << "     perimeter: " << getPerimeter() << std::endl;
}
