#include <iostream>
#include <vector>
using namespace std;

string isPrime(int n) {
    for (int i=2; i*i <= n; i++) {
        if (n % i == 0) return "Not Prime";
    }
    return "Prime";
}

int countPrimes(int n) {
    // TC = O(NLog(LogN)), SC = O(N)
    int count = 0;
    vector<bool> isPrime(n+1, true);

    for (int i=2; i<n; i++) {
        if (isPrime[i]) {
            count++;
            for (int j=i*2; j<n; j=j+i) {
                isPrime[j] = false;
            }
        }
    }

    return count;
}

void printDigits(int n) {
    int count = 0;
    int sum = 0;

    // TC = O(log10(n)) =-> 10 is base because we are dividing the number by 10
    while (n != 0) {
        int dig = n % 10;
        cout << dig << " ";
        count++;
        sum += dig;

        n /= 10;
    }
    cout << endl;

    cout << "Total digits = " << count << endl;
    cout << "Sum of digits = " << sum << endl;
}

int main() {
    // int n = 47;
    // cout << n << " is " << isPrime(n) << endl;

    // int n = 50;
    // cout << "Count of primes form 1 to " << n << " is " << countPrimes(n) << endl;

    int n = 285452;
    printDigits(n);

    cout << (int)(log10(n) + 1) << endl;

    return 0;
}