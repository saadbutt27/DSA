#include <iostream>
using namespace std;

int main() {
    // Array's name is actually the pointer to its first/0th element
    // Array pointer is a constant pointer
    int arr[] = {1, 2, 3, 4, 5};

    cout << arr << endl; // pointer
    cout << *arr << endl; // first index's value
    cout << *(arr+1) << endl; // first index's value
    cout << *(arr+3) << endl; // first index's value
    return 0;
}