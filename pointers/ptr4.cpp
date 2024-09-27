#include <iostream>
using namespace std;

int main() {
    // Pointer arithmetic
    int a = 10;
    int* ptr = &a;

    cout << ptr << endl;
    ptr--;
    cout << ptr << endl;
    ptr += 2;
    cout << ptr << endl;

    // addition of two pointers is not allowed
    // subtraction of two pointers of same DT is allowed
    int* ptr2;
    int* ptr1  = ptr2 + 2;

    cout << ptr1 << " " << ptr2  << " " << ptr1 - ptr2 << endl;
    // cout << ptr1 << " " << ptr2  << " " << ptr1 + ptr2 << endl;

    // comparison between pointers is also allowed
    cout << (ptr1 < ptr2) << endl;
    cout << (ptr1 >= ptr2) << endl;
    
    return 0;
}