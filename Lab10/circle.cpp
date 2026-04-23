#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

typedef struct _point {
    double xPosition;
    double yPosition;
} point;





class Circle {
    private:
    point center;
    double radius;
    public:
    Circle(point pt, double radius) {
        this->center = pt;
        this->radius = radius;
    }
    double area() {
        return M_PI *powl(radius, 2);
    }
    double distanceFromCenter(point pt) {
        double dist = sqrtf(powl(pt.xPosition-center.xPosition, 2) + powl(pt.yPosition-center.yPosition, 2) );
        return dist;
    }
    int contains(point pt) {
        
        if (distanceFromCenter(pt) < radius) {
            return 1;
        } else {
            return 0;
        }
    }
};









int main()
{
    point center , check;
    double radius;
    cout << "Center of Circle: ";
    cin >> center.xPosition >> center.yPosition;
    cout << "Radius of Circle: ";
    cin >> radius;
    Circle circle(center, radius);
    cout << "Point to Check: ";
    cin >> check.xPosition >> check.yPosition;
    cout << "Area of Circle is " << circle.area() << endl;
    cout << "Distance from Center to Point (" << check.xPosition << ", " << check.yPosition<<") is " << circle.distanceFromCenter(check) << endl;
    if (circle.contains(check)) {
        cout << "This circle contains this point." << endl;
    } else {
        cout << "This point is not in this circle." << endl;
    }

}