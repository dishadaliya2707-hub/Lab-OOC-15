#include <iostream>
using namespace std;

class Product
{
private:
    int productId;
    string productName;
    int quantity;
    float price;
    float billAmount;

public:
    void inputDetails()
    {
        cout << "Enter Product ID: ";
        cin >> productId;

        cout << "Enter Product Name: ";
        cin >> productName;

        cout << "Enter Quantity: ";
        cin >> quantity;

        cout << "Enter Price: ";
        cin >> price;

        billAmount = quantity * price;
    }

    void displayDetails()
    {
        cout << "\n----- Product Details -----\n";
        cout << "Product ID   : " << productId << endl;
        cout << "Product Name : " << productName << endl;
        cout << "Quantity     : " << quantity << endl;
        cout << "Price        : " << price << endl;
        cout << "Bill Amount  : " << billAmount << endl;
    }
};

int main()
{
    Product p;

    p.inputDetails();
    p.displayDetails();

    return 0;
}