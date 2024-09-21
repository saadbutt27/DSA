#include <iostream>
using namespace std;

bool powerOfTwo(int num) {
    // if (num < 1) return false;
    // int power = 1;
    
    // while (power < num) {
    //     if (power  == num) return true;
    //     power *= 2;
    // }
    // return false;
    if (num < 1) return false;
    
    while (num % 2 == 0) {
        num /= 2;
    }
    return (num == 1);
}

bool powerOfTwoBitwise(int num) {
    if (num < 1) return false;
    
    // while (num > 1) {
    //     cout << num << endl;
    //     if (num & 1) return false;
    //     num >>= 1;
    // }

    if ((num & (num - 1)) > 0) return false;
    return true;
}

int reverseNumber(int num) {
    int reversed = 0;
    while(num > 0) {
        int remainder = num % 10; // 3
        num /= 10; // 3

        reversed *= 10; // 20
        reversed += remainder; // 23
    }
    return reversed;
}

double myPow(double x, int n) {
    // Binary Exponentiation - O(logn)
    if (n == 0) return 1.0;
    if (x == 0) return 0.0;
    if (x == 1) return 1.0;
    if (x == -1 && n%2 == 0) return 1.0;
    if (x == -1 && n%2 != 0) return -1.0;

    long binForm = n;

    if (n < 0) {
        x = 1/x;
        binForm = -binForm;
    }

    double ans = 1;

    while (binForm > 0) {
        if (binForm % 2 == 1) {
            ans *= x;
        }
        x *= x; // x^2
        binForm /= 2;
    }  

    return ans;      
}

int main() {
    // for(int i=0; i<=70; i++)
    //     cout << i << ": " << powerOfTwoBitwise(i) << " 2^" << i << endl;

    // cout << powerOfTwoBitwise(32) << endl;
    // cout << powerOfTwoBitwise(12) << endl;
    // cout << (12 & (12 - 1)) << endl;

    // cout << (32 >> 1) << endl; 
    // cout << (16 >> 1) << endl; 
    // cout << (8 >> 1) << endl; 
    // cout << (4 >> 1) << endl; 
    // cout << (2 >> 1) << endl; 
    // cout << (1 >> 1) << endl; 

    cout << myPow(0, 5) << endl;
    return 0;
}