#include <iostream>
using namespace std;
int main()
{
    int num;
    cout << "Enter a number: ";
    cin >> num;
    try
    {
        if (num < 0)
        {
            throw num;
        }
        cout << "Number is positive or zero." << endl;
    }
    catch (int n)
    {
        cout << "Exception: Negative number entered!" << endl;
    }
    return 0;
}