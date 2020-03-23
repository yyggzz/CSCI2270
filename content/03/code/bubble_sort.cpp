#include <iostream>

using namespace std;

void bubble_sort(int A[], int n)
{
    int temp;
    for(int k = 0; k < n-1; k++) {
        // Last k elements are already in place
        for(int i = 0; i < n-k-1; i++) {
            if(A[i] > A[i+1] ) {
                temp = A[i];
                A[i] = A[i+1];
                A[i + 1] = temp;
            }
        }
    }
}

void print_array(int A[], int n)
{
    for(int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

int main() 
{
    int A[10] = {4, 10, 2, 8, 9, 1, 3, 13, 19, 4};

    cout << "before: ";
    print_array(A, 10); // print array before sorting

    bubble_sort(A, 10); // call the sorting function

    cout << "after : ";
    print_array(A, 10); // print array after sorting

    return 0;
}