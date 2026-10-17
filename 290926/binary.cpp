#include <iostream>
using namespace std;
class Distance {
public:
    int feet, inch;
    Distance() {
        this->feet = 0;
        this->inch = 0;
    }
    Distance(int f, int i) {
        this->feet = f;
        this->inch = i;
    }
    void operator+(Distance& d2) {
       // Distance d3;
        thid->feet = this->feet + d2.feet;
        this->inch = this->inch + d2.inch;
        cout<<"This is: "<<this->feet<<endl;
        cout<<"d2 is: "<<d2.feet<<endl;
        return d3;
    }
};
int main() {
    Distance d1(8, 9);
    Distance d2(10, 2);
    Distance d3;
    d1 + d2;
    cout << "\nTotal Feet & Inches: " << d3.feet << "'" << d3.inch << endl;
    return 0;
}