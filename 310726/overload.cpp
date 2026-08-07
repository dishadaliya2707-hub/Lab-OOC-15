#include <iostream>
using namespace std;

// Function Prototypes
int area(int);
int area(int, int);
float area(float);

int main()
{
    cout << "Calling the area() function for computing the area of a square "
         << "(side = 5) - " << area(5) << endl;

    cout << "Calling the area() function for computing the area of a rectangle "
         << "(length = 5, breadth = 10) - " << area(5, 10) << endl;

    cout << "Calling the area() function for computing the area of a circle "
         << "(radius = 5.5) - " << area(5.5f) << endl;

    return 0;
}

// Area of square
int area(int side)
{
    return side * side;
}

// Area of rectangle
int area(int length, int breadth)
{
    return length * breadth;
}

// Area of circle
float area(float radius)
{
    return 3.14f * radius * radius;
}