#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
int main()
{
    ifstream fin("sample.txt");
    if (!fin)
    {
        cout << "File not found!" << endl;
        return 1;
    }
    string line, word;
    int lines = 0, words = 0, characters = 0;
    while (getline(fin, line))
    {
        lines++;
        characters += line.length();
        stringstream ss(line);
        while (ss >> word)
        {
            words++;
        }
    }
    fin.close();
    cout << "Number of lines: " << lines << endl;
    cout << "Number of words: " << words << endl;
    cout << "Number of characters: " << characters << endl;
    return 0;
}