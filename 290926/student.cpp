#include <iostream>
#include <string>
using namespace std;
class Student {
private:
    int rollNo;
    string name;
    float marks;
public:
    Student() : rollNo(0), name(""), marks(0.0) {}
    friend istream& operator>>(istream& input, Student& s) {
        cout << "Enter Roll Number: ";
        input >> s.rollNo;
        cout << "Enter Name: ";
        input >> ws; 
        getline(input, s.name);
        cout << "Enter Marks: ";
        input >> s.marks;
        return input;
    }
    friend ostream& operator<<(ostream& output, const Student& s) {
        output << "\n--- Student Details ---" << endl;
        output << "Roll Number : " << s.rollNo << endl;
        output << "Name        : " << s.name << endl;
        output << "Marks       : " << s.marks << endl;
        return output;
    }
};
int main() {
    Student s1;
    cout << "Enter Student Information:\n";
    cin >> s1;
    cout << s1;

    return 0;
}