#include <iostream>

using namespace std;

namespace disha
{
    int add_sub();
    int mul_div();
}

int main()
{
    int choice;
    int a,b;
    cout << "\n1.Add\n2.Subtract\n3.Multiply\n4.Divide\n5.Modulus\n";
    cout << "Enter choice: ";
    cin >> choice;

    switch(choice) {
        case 1: cout << "Result = " << a + b; break;
        case 2: cout << "Result = " << a - b; break;
        case 3: cout << "Result = " << a * b; break;
        case 4: cout << "Result = " << (float)a / b; break;
        case 5: cout << "Result = " << a % b; break;
        default: cout << "Invalid choice";
    }
    return 0;
}