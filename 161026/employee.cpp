#include <iostream>
using namespace std;
class Employee {
protected:
    float salary;
public:
    Employee(float s) {
        salary = s;
    }
    virtual void calculateBonus() {
        cout << "Employee Bonus = " << salary * 0.05 << endl;
    }
};
class Manager : public Employee {
public:
    Manager(float s) : Employee(s) {}
    void calculateBonus() override {
        cout << "Manager Bonus = " << salary * 0.20 << endl;
    }
};
class Developer : public Employee {
public:
    Developer(float s) : Employee(s) {}
    void calculateBonus() override {
        cout << "Developer Bonus = " << salary * 0.10 << endl;
    }
};

int main() {
    Manager m(50000);
    Developer d(40000);
    Employee *e;
    e = &m;
    e->calculateBonus();
    e = &d;
    e->calculateBonus();
    return 0;
}