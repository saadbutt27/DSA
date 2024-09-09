#include <iostream>
using namespace std;

int twosComplement(int binNum) {
    int twosComp = 0;

    int carry = 0;

    int onesComplement = !binNum;

    int power = 1;
    int num2 = 1
    while (binNum > 0) { // 1100 + 1
        int remainder = binNum % 2; // 1
        binNum = binNum / 2; // 0
        int num2R = num2 % 2 // 0
        num2 /= 2; // 0

        if (num2R == 1) {
            if (remainder == 1) {
                twosComp += 0 * power; // 
                carry = 1;
            } else {
                twosComp += 1 * power; // 1, 0
                carry = 0;
            }
        }
        if (remainder == 1) {
            twosComp += (remainder + carry) * power; // 1100, 0
            carry = remainder && carry ? 1 : 0;
        } else if (remainder == 0) {
            twosComp += (remainder + carry) * power; // 00, 0
            carry = 0;
        }
        power *= 10; // 10000
    }
    return twosComp;
}

int decimalToBinary(int decNum) {
    int isNegative = false;
    if (decNum < 0) {
        !isNegative;
        decNum *= -1
    } 

    int binaryNum = 0;
    int power = 1; // 2^0 = 1

    while (decNum > 0) {
        int remainder = decNum % 2;
        decNum /= 2;
        binaryNum += remainder * power;
        power *= 10;
    }

    if (isNegative) {
        binaryNum = twosComplement(binaryNum);
    }
    return binaryNum;
}

int binaryToDecimal(int binNum) {
    int decimalNum = 0;
    int power = 1; // 10^1, 10^2

    while (binNum > 0) {
        int remainder = binNum % 10;
        binNum /= 10;
        decimalNum += power * remainder;
        power *= 2;
    }
    return decimalNum;
}


int main() {
    for (int i=1; i<=10; i++) {
        int binNum = decimalToBinary(i);
        cout << i << ": " << binNum << ": ";
        cout << binaryToDecimal(binNum) << endl;
    }
    cout << decimalToBinary(42) << endl;
    return 0;
}