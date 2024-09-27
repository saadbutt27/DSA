#include <iostream>
using namespace std;

int main() {
    // A pointer will have the same DT as of the variable it is referencing
    int a = 10;
    int* ptr = &a;
    cout << ptr << " " << &a << " " << &ptr << endl;

    // float price = 100.54f;
    // float* ptr2 = &price;
    // cout << ptr2 << " " << &price << " " << &ptr2 << endl;
    
    int ** parPtr = &ptr;
    cout << &ptr << " " << parPtr << " " << &parPtr << endl;

    // Dereference operator (*): gives value at an address
    cout << *&a << " " << *ptr << endl;
    cout << ptr << " " << *parPtr << " " << **parPtr <<  endl;

    // NULL Pointer: A pointer that doesn't point to any loation in the memory
    // int** ptr3 = NULL;
    // cout << ptr3 << " " << &ptr << endl;

    int c = 5;
    int* p = &c;
    int** q = &p;

    cout << *p << " " << **q << endl;
    cout << p << " " << *q << endl;
    return 0;
}