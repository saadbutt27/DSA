#include <iostream>
#include <cstring>
#include <string> // optional to write
#include <algorithm>
using namespace std;

void reverseString(char str[]) {
    int st = 0, end = strlen(str)-1;

    while (st < end) {
        swap(str[st++], str[end--]);
    }
}

int main() {
    // Character arrays - C strings
    // We can use them to store strings
    // To make a string we will add this null character '\0' at the end of the character array, which makes it a string
    // char str[] = { 'a', 'b', 'c'};
    // cout << str << endl; // Constant pointer, print the whole array combined
    // char str2[] = {'s', 'a', 'a', 'd', '\0'};
    // cout << str2 << " " << strlen(str2) << endl; // valid string
    // char str3[] = "usman";
    // cout << str3 << " " << strlen(str3) << endl; // valid string

    // Take input in a string/charcter array
    // cin.getline(str, len, delim?) -> used to store senetences(with spaces)
    // char name[100];
    // cout<< "Enter your name: ";
    // // cin >> name;
    // // cin.getline(name, 100);
    // cin.getline(name, 100, '$'); // If we want untile the user doesn't write $, do not stop taking input
    // cout << "Name: " << name << endl;
    // cout << strlen(name) << endl;

    // Strings in C++
    // String is a class here not a primitive datatype
    // Strings are dynamic in nature and can be resized at runtime
    // string str = "saad butt";
    // cout << str << endl;

    // str = "saad nisar";
    // cout << str << endl;

    // string str1 = "Saad";
    // string str2 = "Butt";
    // string str3 = str1 + str2; // concatenation

    // cout << str3 << endl;
    // cout << str3.length() << endl;

    // cout << (str1 == str2) << endl;
    // cout << (str1 > str2) << endl;
    // cout << (str1 < str2) << endl;

    // string str4;
    // // cin >> str4;
    // // getline(cin, str4);
    // cout << str4 << endl;

    string str5 = "apna college";
    // char str5[] = "apna college";

    // for(int i=0; i<str5.length(); i++) {
    //     cout << str5[i] << " ";
    // }
    for(char ch: str5) {
        cout << ch << " ";
    }
    cout << endl;

    // reverseString(str5);
    reverse(str5.begin(), str5.end());
    for(char ch: str5) {
        cout << ch << " ";
    }
    cout << endl;

    return 0;
}