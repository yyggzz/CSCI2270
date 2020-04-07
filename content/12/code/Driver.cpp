#include <iostream>
#include "HashTable.hpp"

using namespace std;

int main()
{
    HashTable H(39);
    H.loadData("Data.csv", 21);
    H.display();
    H.search(121);
    H.remove(121);
    H.search(121);
    H.display();
    return 0;
}