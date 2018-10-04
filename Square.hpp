#pragma once

#include "Rectangle.hpp"

class Square : public Rectangle
{
public:
    Square(double x);
    Square(const Square & other)= default;
    Square(Square && other)noexcept = default ;
    Square& operator =(Square && other)noexcept = default;

    double getArea() const noexcept override;
    double getPerimeter() const noexcept override;
    void print() const override;

private:
    double getY() = delete; // should not have Y dimension
    Square() = delete;
};
