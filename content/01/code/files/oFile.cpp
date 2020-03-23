#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ofstream oFile("filename.txt", ios :: trunc);
    
    oFile << "Inserted this text into filename.txt";

    oFile.close();
}