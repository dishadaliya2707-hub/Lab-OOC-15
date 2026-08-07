#include <iostream>
using namespace std;

int main()
{
    int *arr;
    int size;

    cout << "Enter the size of the integer array: ";
    cin >> size;

    cout << "Creating an array of size: " << size << "...\n";

    arr = new int[size];

    cout << "Enter the array elements:\n";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }

    cout << "The sum of the array is: " << sum << endl;
    cout << "Dynamic allocation of memory for array arr is successful." << endl;

    delete[] arr;   

    return 0;
}