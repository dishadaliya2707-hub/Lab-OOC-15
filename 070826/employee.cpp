#include <iostream>
#include <string>
using namespace std;

class employee
{
private:
    int id;
    string designation;
    string branch;
    float salary;
    float gsalary;

public:
    void inputDetails()
    {
        cout << "Enter ID: ";
        cin >> id;

        cout << "Enter Designation: ";
        cin >> designation;

         cout << "Enter branch: ";
        cin >> branch;

        cout << "Enter Salary: ";
        cin >> salary;

        gsalary = salary + ((20 / 100) * salary) + ((80/ 100) * salary);
    }

    void displayDetails() const
    {
        cout << "\n----- Employee Details -----\n";
        cout << "Id           : " << id << endl;
        cout << "Designation  : " << designation << endl;
        cout << "Branch  : " << branch << endl;
        cout << "Salary       : " << salary << endl;
        cout << "Gross Salary : " << gsalary << endl;
    }
};

int main()
{
    employee s;

    s.inputDetails();
    s.displayDetails();

    return 0;
}