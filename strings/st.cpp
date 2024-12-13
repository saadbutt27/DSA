#include <iostream>
#include <cstring>
#include <string> // optional to write
#include <algorithm>
#include <unordered_map>
#include <vector>
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

// string reverseWords(string s) {
//     string word; 
//     vector<string> words;
//     for (int i=0; i<s.size(); i++) {
//         if(s[i] == ' ' && !word.empty()) {
//             words.push_back(word);
//             word.clear();
//             continue;
//         }
//         if(s[i] == ' ') {
//             continue;
//         }
//         word += s[i];
//     }
//     if(!word.empty()) {
//         words.push_back(word);
//         word.clear();
//     }
//     s.clear();
//     for (int i = words.size() - 1; i >= 0; --i) {
//         s += words[i];
//         if (i > 0) {
//             s += " ";
//         }
//     }
//     return s;
// }
string reverseWords(string s) {
    // TC = O(n)
    int n = s.length();
    string ans = "";
    reverse(s.begin(), s.end());

    for (int i=0; i<n; i++) {
        string word = "";
        while (i < n && s[i] != ' ') {
            word += s[i++];
        }

        reverse(word.begin(), word.end());

        if (word.length() > 0)
            ans += " " + word;
    }

    return ans.substr(1);
}

int compress(vector<char>& chars) {
    // 1. find continuous characters and count them
    //      if count = 1, only character is replaced in the array
    //      else if count > 1, charcater an count(converted to char) will be replaced in the array
    // 2. replace count in original character array

    // TC = O(n), SC = O(1)
    int n = chars.size();
    int idx = 0; // pointer index to track replacements
    for (int i=0; i<n; i++) {
        char ch = chars[i];
        int count = 0; 

        // counting contiuous characters
        while (i<n && chars[i] == ch) {
            count++; i++;
        }

        chars[idx++] = ch;
        if (count > 1) {
            // chars[idx++] = (count + '0');
            string str = to_string(count);
            for (char dig : str) {
                chars[idx++] = dig;
            }
        }
        i--;
    }

    chars.resize(idx);
    return chars.size();
}

// Morse code dictionary with accurate character lengths
unordered_map<char, string> morse_code = {
    {'a', ".-"}, {'b', "-..."}, {'c', "-.-."}, {'d', "-.."}, {'e', "."}, {'f', "..-."}, {'g', "--."}, {'h', "...."},
    {'i', ".."}, {'j', ".---"}, {'k', "-.-"}, {'l', ".-.."}, {'m', "--"}, {'n', "-."}, {'o', "---"}, {'p', ".--."},
    {'q', "--.-"}, {'r', ".-."}, {'s', "..."}, {'t', "-"}, {'u', "..-"}, {'v', "...-"}, {'w', ".--"}, {'x', "-..-"},
    {'y', "-.--"}, {'z', "--.."}, {' ', "/"}  // Space is represented by '/'
};

// Function to calculate Morse code length
int morseCodeLength(const string &message) {
    int total_length = 0;

    // Split the message into words
    vector<string> words;
    string word = "";
    for (char c : message) {
        if (c == ' ') {
            if (!word.empty()) {
                words.push_back(word);
                word = "";
            }
        } else {
            word += tolower(c);
        }
    }
    if (!word.empty()) words.push_back(word);

    // Process each word
    for (size_t word_index = 0; word_index < words.size(); ++word_index) {
        int word_length = 0;

        for (size_t char_index = 0; char_index < words[word_index].length(); ++char_index) {
            char c = words[word_index][char_index];
            // cout << "character: " << c << endl;
            if (morse_code.find(c) != morse_code.end()) {
                string morse = morse_code[c];
                // cout << "morse: " << morse << endl;
                int char_length = 0;

                // Count the dashes (3 units each) and dots (1 unit each)
                for (char symbol : morse) {
                    if (symbol == '-') char_length += 3;
                    else if (symbol == '.') char_length += 1;
                }
                // cout << "char_length of dots and dashes: " << char_length << endl;

                // Add the gaps between symbols (dots/dashes) for the character
                char_length += morse.length() - 1;
                // cout << "char_length of gaps between fots and dashes: " << char_length << endl;

                word_length += char_length;
                // cout << "word_length: " << char_length << endl;

                // Add the gap between characters (3 units)
                if (char_index < words[word_index].length() - 1) {
                    word_length += 3;
                }
                // cout << "word_length with gap between characaters: " << char_length << endl;
            }
        }

        total_length += word_length;
        // cout << "total_length: " << total_length << endl; 

        // Add the gap between words (7 units)
        if (word_index < words.size() - 1) {
            total_length += 7;
        }
        // cout << "total_length with gap between words: " << total_length << endl; 
    }

    return total_length;
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

    // string s1 = "ab", s2 = "eidbaooo";
    // cout << s1 << " " << s2 << " " << checkInclusion(s1, s2) << endl;

    // string s = "  hello world  ";
    // cout << s << endl << reverseWords(s) << endl;

    // vector<char> chars = {'a', 'a', 'b', 'c', 'c', 'c', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b'};
    // for (char ch : chars) cout << ch << " ";
    // cout << endl;
    // cout << chars.size() << " " << compress(chars) << endl;
    // for (char ch : chars) cout << ch << " ";
    // cout << endl;

    int n;
    cin >> n;  // Number of messages
    cin.ignore();  // Ignore newline after integer input

    for (int i = 0; i < n; i++) {
        string message;
        getline(cin, message);
        
        // Convert the message to lowercase
        for (char &c : message) {
            c = tolower(c);
        }

        // Calculate the Morse code length and print the result
        int length = morseCodeLength(message);
        cout << message << ": length = " << length << endl;
    }

    return 0;
}