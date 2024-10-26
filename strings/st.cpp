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

// bool isPlaindrome(char str[]) {
// bool isPlaindrome(string str) {
//     // m a d a m
//     int st = 0;
//     // int end = strlen(str)-1;
//     int end = str.length()-1;

//     while (st < end) {
//         if (str[st++] != str[end--]) {
//             return false;
//         }
//     }
//     return true;
// }

bool isAlphaNumeric(char c) {
    if ((c >= '0' && c <= '9') ||
        tolower(c) >= 'a' && tolower(c) <= 'z') {
            return true;
        } else {
            return false;
        }
}
bool isPalindrome(string s) {
    int st = 0, end = s.length()-1;

    while (st < end) {
        if (!isAlphaNumeric(s[st])) {
            st++; continue;
        }
        if (!isAlphaNumeric(s[end])) {
            end--; continue;
        }

        if (tolower(s[st]) != tolower(s[end])) {
            return false;
        }

        st++; end--;
    }

    return true;
}

string removeOccurrences(string s, string part) {
    // str.find(substring) => find the first occurence of a substring in a string
    // str.erase(start_pos, length) => erase the characters from a string
    while (s.length() > 0 && s.find(part) < s.length()) {
        s.erase(s.find(part), part.length());
    }
    
    return s;
}

bool isFreqSam(int freq1[], int freq2[]) {
    for (int i = 0; i < 26; i++) {
        if (freq1[i] != freq2[i]) {
            return false;
        }
    }
    return true;
}

bool checkInclusion(string s1, string s2) {
    // 1. store frequency of the characters in s1
    //        We will have only lowercase alphabets, so we can create a 26 length array or we can use unordered map
    int freq[26] = {0};
    for (int i=0; i<s1.length(); i++) {
        freq[s1[i]-'a']++;
    }   

    // 2. search s1 permutation in s2
    //      use window based approach ~ sliding window
    //      check s1.length() size windows -> window freq, match freq with window freq   
    int windowSize = s1.length();
    for (int i=0; i<s2.length(); i++) {
        int windowIdx = 0, idx = i;
        int windowFreq[26] = {0};

        while (windowIdx < windowSize && idx  < s2.length()) {
            windowFreq[s2[idx]-'a']++;
            windowIdx++, idx++;
        }

        if (isFreqSam(freq, windowFreq)) {
            return true;
        }
    }
    return false;
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

    // string str5 = "apna college";
    // char str5[] = "apna college";

    // for(int i=0; i<str5.length(); i++) {
    //     cout << str5[i] << " ";
    // }
    // for(char ch: str5) {
    //     cout << ch << " ";
    // }
    // cout << endl;

    // // reverseString(str5);
    // reverse(str5.begin(), str5.end());
    // for(char ch: str5) {
    //     cout << ch << " ";
    // }
    // cout << endl;

    // // char str6[] = "hello";
    // string str6 = "level";
    // cout << isPalindrome(str6) << endl;

    // string str7 = "daabcbaabcbc", part = "abc";
    // cout << str7 << " " << removeOccurrences(str7, part) << endl;

    string s1 = "ab", s2 = "eidbaooo";
    cout << s1 << " " << s2 << " " << checkInclusion(s1, s2) << endl;

    return 0;
}