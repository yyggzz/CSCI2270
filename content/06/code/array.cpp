#include <iostream>

using namespace std;

int* extend_array(int* A, int& array_size, int extend_factor)
{
    int* B = new int[array_size * extend_factor];
    int p, q;
    for(p = 1, q = 0; p < array_size; p += 2, q++) {
        B[q] = A[p];
    }

    for(p = 0; p < array_size; p += 2, q++) {
        B[q] = A[p];
    }

    delete [] A;
    return B;
}

int main()
{
    // initalization
    int array_size = 10;
    int *arr = new int[array_size]; 

    // adding elements to the array
    for(int i = 0; i < array_size; i++) {
        arr[i] = i;
        cout << arr[i] << " ";
    }
    cout << endl;

    // function call
    arr = extend_array(arr, array_size, 2);

    // print the new array out
    for(int i = 0; i < array_size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // avoiding memory leaks
    delete [] arr;
    

    return 0;
}