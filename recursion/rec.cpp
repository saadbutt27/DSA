#include <iostream>
using namespace std;

int factorial(int n) {
    if (n == 0) {
        return 1;
    }

    return n * factorial(n-1);
}

int sum (int n) {
    if (n == 1) {
        return 1;
    }

    return n + sum(n-1);
}

int main() {

    cout << factorial(9) << endl;

    cout << sum(5) << endl;
    
    return 0;
}