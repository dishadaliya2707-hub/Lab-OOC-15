#include <iostream>
#include <exception>
using namespace std;
class InvalidAgeException : public exception
{
public:
    const char* what() const noexcept override
    {
        return "Invalid age! Age must be 18 or above.";
    }
};
class Person
{
private:
    int age;
public:
    void acceptAge()
    {
        cout << "Enter age: ";
        cin >> age;

        if (age < 18)
        {
            throw InvalidAgeException();
        }
        cout << "Age is valid." << endl;
    }
};

int main()
{
    Person p;
    try
    {
        p.acceptAge();
    }
    catch (const InvalidAgeException& e)
    {
        cout << e.what() << endl;
    }
    return 0;
}