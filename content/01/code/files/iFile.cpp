#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    char str[10];

    ifstream iFile("filename.txt");
    iFile >> str;

    cout << str << "\n";

    cin.get();

    iFile.close();
}