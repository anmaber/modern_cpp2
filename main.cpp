#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include "Shape.hpp"
#include "Rectangle.hpp"
#include "Square.hpp"
#include "Circle.hpp"
#include <memory>

using namespace std;

using Collection=vector<shared_ptr<Shape>>;
/*

auto sortByArea= [](shared_ptr<Shape> first, shared_ptr<Shape> second)
{
    if(first == nullptr || second == nullptr)
    {
        return false;
    }
    return (first->getArea() < second->getArea());
};

*/


/*
auto perimeterBiggerThan20 = [](shared_ptr<Shape> s)
{
    if(s)
    {
        return (s->getPerimeter() > 20);
    }
    return false;
};
*/

auto areaLessThan10=[](shared_ptr<Shape> s)
{
    if(s)
    {
        return (s->getArea() < 10);
    }
    return false;
};

void printCollectionElements(const Collection& collection)
{
    for(auto const & v: collection)
    {
        if(v != nullptr)
        v->print();
        /*if(*it != nullptr)
        {
            (*it)->print();
        }*/
    }
}

void printAreas(const Collection& collection)
{
    for(auto const & v: collection)
    {
        if(v != nullptr)
        cout<<v->getArea()<<std::endl;
        /*
        if(*it != nullptr)
        {
            cout << (*it)->getArea() << std::endl;
        }*/
    }
}

void findFirstShapeMatchingPredicate(const Collection& collection,
                                     //bool (*predicate)(shared_ptr<Shape> s),
                                     std::function<bool(shared_ptr<Shape>)> predicate,
                                     std::string info)
{
    auto iter = std::find_if(collection.begin(), collection.end(), predicate);
    if(*iter != nullptr)
    {
        cout << "First shape matching predicate: " << info << endl;
        (*iter)->print();
    }
    else
    {
        cout << "There is no shape matching predicate " << info << endl;
    }
}

int main()
{
    cout << "Circle alignment: "<< alignof(class Circle)<<endl<<endl;

    auto shape = make_shared<Circle>(5.0);
    Collection shapes{make_shared<Circle>(2.0),make_shared<Circle>(3.0), nullptr,
                      make_shared<Circle>(4.0),make_shared<Rectangle>(10.0, 5.0),
                      make_shared<Square>(3.0),make_shared<Circle>(4.0)};
   /* shapes.push_back(new Circle(2.0));
    shapes.push_back(new Circle(3.0));
    shapes.push_back(nullptr);
    shapes.push_back(new Circle(4.0));
    shapes.push_back(new Rectangle(10.0, 5.0));
    shapes.push_back(new Square(3.0));
    shapes.push_back(new Circle(4.0));
*/
    shapes.push_back(move(shape));
    printCollectionElements(shapes);

    cout << "Areas before sort: " << std::endl;
    printAreas(shapes);

    std::sort(shapes.begin(), shapes.end(), [](shared_ptr<Shape> first, shared_ptr<Shape> second)
    {
        if(first == nullptr || second == nullptr)
        {
            return false;
        }
        return (first->getArea() < second->getArea());
    });

    cout << "Areas after sort: " << std::endl;
    printAreas(shapes);

    auto circle =make_shared<Circle>(2.0);
    shapes.push_back(std::move(circle));
    auto square = make_shared<Square>(4.0);
    shapes.push_back(square);

    findFirstShapeMatchingPredicate(shapes, [x=20](shared_ptr<Shape> s)
    {
        if(s)
        {
            return (s->getPerimeter() > x);
        }
        return false;
    }
    , "perimeter bigger than 20");
    findFirstShapeMatchingPredicate(shapes,areaLessThan10, "area less than 10");

    return 0;
}

