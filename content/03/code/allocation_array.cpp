#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    int i = 0;
    int NUM = argc == 2 ? atoi(argv[1]) : 10; // ternary assignment

    int *A = new int[NUM]; // allocate memory for array on heap

    for(int i = 0; i < NUM; i++) {
        A[i] = i * 3;
    }

    for(i = 0; i < NUM; i++) {
        cout << A[i] << " ";
    }

    delete [] A;// free entire array's memory on heap

    return 0;
}