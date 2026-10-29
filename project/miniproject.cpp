#include <iostream>
#include <string>
using namespace std;
// Base Class
class Vehicle {
protected:
    string brand;
    int vehicleId;
    double dailyRate;
public:
    // 1. Constructor
    Vehicle(string b, int id, double rate) {
        brand = b;
        vehicleId = id;
        dailyRate = rate;
        cout << "[Constructor] Vehicle object created for ID: " << vehicleId << endl;
    }
    // 2. Virtual Destructor
    virtual ~Vehicle() {
        cout << "[Destructor] Vehicle object destroyed for ID: " << vehicleId << endl;
    }
    // Function Overloading 1: Set details with basic info
    void setDetails(string b, double rate) {
        brand = b;
        dailyRate = rate;
    }
    // Function Overloading 2: Set details with ID included (Compile-time Polymorphism)
    void setDetails(string b, int id, double rate) {
        brand = b;
        vehicleId = id;
        dailyRate = rate;
    }
    // Virtual function for Function Overriding (Runtime Polymorphism)
    virtual void displayDetails() {
        cout << "Brand: " << brand << " | Vehicle ID: " << vehicleId << " | Daily Rate: $" << dailyRate << endl;
    }
    // 3. Operator Overloading: Overload '+' operator to combine daily rental rates of two vehicles
    double operator+(const Vehicle& v) {
        return this->dailyRate + v.dailyRate;
    }
};
// Derived Class 1: Car (Demonstrating Inheritance)
class Car : public Vehicle {
private:
    int seatingCapacity;
public:
    // Car Constructor
    Car(string b, int id, double rate, int seats) : Vehicle(b, id, rate) {
        seatingCapacity = seats;
        cout << "[Constructor] Car subclass initialized." << endl;
    }
    // Car Destructor
    ~Car() {
        cout << "[Destructor] Car subclass destroyed." << endl;
    }
    // Function Overriding (Runtime Polymorphism)
    void displayDetails() override {
        cout << "[Car Details] Brand: " << brand 
             << " | ID: " << vehicleId 
             << " | Seats: " << seatingCapacity 
             << " | Rate: $" << dailyRate << "/day" << endl;
    }
};
// Derived Class 2: Bike (Demonstrating Inheritance)
class Bike : public Vehicle {
private:
    bool hasCarrier;
public:
    // Bike Constructor
    Bike(string b, int id, double rate, bool carrier) : Vehicle(b, id, rate) {
        hasCarrier = carrier;
        cout << "[Constructor] Bike subclass initialized." << endl;
    }
    // Bike Destructor
    ~Bike() {
        cout << "[Destructor] Bike subclass destroyed." << endl;
    }
    // Function Overriding (Runtime Polymorphism)
    void displayDetails() override {
        cout << "[Bike Details] Brand: " << brand 
             << " | ID: " << vehicleId 
             << " | Carrier: " << (hasCarrier ? "Yes" : "No") 
             << " | Rate: $" << dailyRate << "/day" << endl;
    }
};

int main() {
    cout << "--- 1. Creating Objects & Demonstrating Constructors ---" << endl;
    // Base class pointer pointing to derived class objects (Enables Polymorphism)
    Vehicle* v1 = new Car("Toyota Corolla", 101, 45.0, 5);
    cout << endl;
    Vehicle* v2 = new Bike("Yamaha R15", 201, 25.0, false);
    cout << endl;
    cout << "--- 2. Demonstrating Polymorphism & Function Overriding ---" << endl;
    v1->displayDetails(); // Calls Car's version
    v2->displayDetails(); // Calls Bike's version
    cout << endl;
    cout << "--- 3. Demonstrating Function Overloading ---" << endl;
    // Using the overloaded setDetails function from Base class
    v1->setDetails("Toyota Camry", 101, 60.0); 
    v1->displayDetails();
    cout << endl;
    cout << "--- 4. Demonstrating Operator Overloading ---" << endl;
    // Using overloaded '+' operator to find total cost of renting both vehicles for a day
    double combinedRate = (*v1) + (*v2);
    cout << "Combined daily rental cost of Car and Bike: $" << combinedRate << endl;
    cout << endl;
    cout << "--- 5. Cleaning up Memory & Demonstrating Destructors ---" << endl;
    delete v1; // Triggers Car destructor then Vehicle destructor
    cout << endl;
    delete v2; // Triggers Bike destructor then Vehicle destructor
    return 0;
}