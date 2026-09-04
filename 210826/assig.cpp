#include <iostream>
using namespace std;
class LibraryBook {
private:
    string title;
    string author;
    bool issued;
public:
    LibraryBook(string t, string a) {
        title = t;
        author = a;
        issued = false;
    }
    void issueBook() {
        if (!issued) {
            issued = true;
            cout << title << " has been issued.\n";
        } else {
            cout << title << " is already issued.\n";
        }
    }
    void returnBook() {
        if (issued) {
            issued = false;
            cout << title << " has been returned.\n";
        } else {
            cout << title << " was not issued.\n";
        }
    }
    void displayBook() {
        cout << "\n--- Book Details ---\n";
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Status: " << (issued ? "Issued" : "Available") << endl;
    }
};
class Patient {
private:
    string name;
    int age;
    float consultationFee;

public:
    Patient(string n, int a, float fee) {
        name = n;
        age = a;
        consultationFee = fee;
    }
    float calculateConsultationCharges() {
        return consultationFee;
    }
    void displayPatientInfo() {
        cout << "\n--- Patient Information ---\n";
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Consultation Charges: Rs. "
             << calculateConsultationCharges() << endl;
    }
};
class MobileRecharge {
private:
    string mobileNumber;
    string accountHolder;
    float balance;
public:
    MobileRecharge(string number, string holder, float initialBalance) {
        mobileNumber = number;
        accountHolder = holder;
        balance = initialBalance;
    }
    void recharge(float amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Recharge successful: Rs. " << amount << endl;
        }
    }
    void deductBalance(float amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Amount deducted: Rs. " << amount << endl;
        } else {
            cout << "Insufficient balance.\n";
        }
    }
    void displayAccountDetails() {
        cout << "\n--- Mobile Account Details ---\n";
        cout << "Account Holder: " << accountHolder << endl;
        cout << "Mobile Number: " << mobileNumber << endl;
        cout << "Available Balance: Rs. " << balance << endl;
    }
};
int main() {
    LibraryBook book("The Alchemist", "Paulo Coelho");
    book.displayBook();
    book.issueBook();
    book.returnBook();
    book.displayBook();

    Patient patient("Rahul Sharma", 25, 500);
    patient.displayPatientInfo();

    MobileRecharge mobile("9876543210", "Rahul Sharma", 100);
    mobile.recharge(200);
    mobile.deductBalance(150);
    mobile.displayAccountDetails();
    return 0;
}