#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    ofstream fout("records.txt", ios::app);
    string record;
    if (!fout)
    {
        cout << "File cannot be opened!" << endl;
        return 1;
    }
    cout << "Enter records (-1 to stop):" << endl;
    while (true)
    {
        getline(cin, record);
        if (record == "-1")
            break;

        fout << record << endl;
    }
    fout.close();
    ifstream fin("records.txt");
    if (!fin)
    {
        cout << "File cannot be opened for reading!" << endl;
        return 1;
    }
    cout << "\nAll Records:" << endl;
    while (getline(fin, record))
    {
        cout << record << endl;
    }
    fin.close();
    return 0;
}