#include <iostream>
#include "LinkedList.hpp"

using namespace std;

int main()
{
    LinkedList LL;

    // Inserting nodes
    LL.Insert(LL.CreateNode(1, "ABC", 4.0), 0);
    LL.Insert(LL.CreateNode(2, "DEF", 3.9), 0);
    LL.Insert(LL.CreateNode(3, "GHI", 3.8), 1);
    LL.PrintList();

    // Length
    cout << LL.Length() << endl;

    // Tail 
    LL.PrintNode(LL.Tail());

    // Search and Print
    LL.PrintNode(LL.Search(1));
    LL.PrintNode(LL.Search("DEF"));


    return 0;
}