#pragma once

#include "Shape.hpp"
#include <algorithm>


 class alignas(2) Circle  final : public Shape
{
public:
    Circle(double r);
    Circle(double r,Color c);
    Circle(const Circle & other)=default;
    Circle& operator = (const Circle &) = default;
    Circle(Circle && other) = default;
    Circle& operator =(Circle && other) = default;

    double getArea() const override;
    double getPerimeter() const override;
    double getRadius() const;
    [[deprecated]]
    double getPi() const;
    void print() const override;

private:
    Circle()=delete; // doesn't allow to call default constructor

    double r_;
};
