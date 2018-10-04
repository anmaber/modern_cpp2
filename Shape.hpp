#pragma once


enum class Color: unsigned char{
Red,
Green,
Blue
};

class Shape
{
    Color _color = Color::Red;

public:
    Shape()=default;
    Shape(const Shape & other) = default;
    Shape(Color c)
    : _color(c){}

    virtual ~Shape() {}

    virtual double getArea() const = 0;
    virtual double getPerimeter() const = 0;
    virtual void print() const;

};
