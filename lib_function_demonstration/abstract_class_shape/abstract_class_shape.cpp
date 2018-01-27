#include <iostream>

using namespace std;

class Shape
{
    friend double total_area(Shape *[2], int);
    public:
        virtual double area(void) = 0;
        virtual ~Shape(void){}

};
class Triangle:public Shape
{
    private:
        double a;
        double h;
    public:
        Triangle(double x, double y):a(x),h(y){}
        virtual ~Triangle(void){}
        virtual double area(void){return 0.5 * a * h;}
};
class Rectangle:public Shape
{
    private:
        double a;
        double b;
    public:
        Rectangle(double x, double y):a(x),b(y){}
        virtual ~Rectangle(void){}
        virtual double area(void){return a * b;}
};

int main()
{
    cout << "The use of polymorphism" << endl;

    Triangle t(2.4, 2);
    Rectangle r(1.3, 2);

    cout << t.area() << endl;
    cout << r.area() << endl;

    Shape *shape[2] = {&t, &r};
    cout << total_area(shape,2) << endl;

    return 0;
}
double total_area(Shape *shape[2], int n)
{
    double totalarea = 0;
    int index;
    for(index = 0; index < n; index++)
    {
        totalarea += shape[index]->area();//same order makes different effect
    }
    return totalarea;
}
