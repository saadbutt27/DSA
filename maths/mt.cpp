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

int main() {
    // int n = 47;
    // cout << n << " is " << isPrime(n) << endl;

    int n = 50;
    cout << "Count of primes form 1 to " << n << " is " << countPrimes(n) << endl;

    return 0;
}