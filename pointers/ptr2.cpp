#include <iostream>
using namespace std;

void changeA(int* ptr) {
    // pass by referernce using pointers
    *ptr = 10;
}
void changeA2(int &b) {
    // pass by referernce using alias
    b = 20;
}

int main() {
    int a = 5;
    cout << a << endl; 

    changeA(&a);
    cout << a << endl; 

    changeA2(a);
    cout << a << endl; 
    
    return 0;
}