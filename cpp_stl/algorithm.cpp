#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool comparator(pair<int, int> p1, pair<int, int> p2) {
    if (p1.second < p2.second) return true;
    else if (p1.second > p2.second) return false;
    
    if (p1.first < p2.first) return true;
    else return false;
}

int main() {
    // int arr[] = {3, 5, 1, 8, 2};
    // sort(arr, arr + 5);

    // for (int val: arr) {
    //     cout << val << " "; 
    // }
    // cout << endl;
    // sort(arr, arr + 5, greater<int>());

    // for (int val: arr) {
    //     cout << val << " "; 
    // }
    // cout << endl;

    // vector<int> vec = {3, 5, 1, 8, 2};
    // sort(vec.begin(), vec.end());

    // for (int val: vec) {
    //     cout << val << " "; 
    // }
    // cout << endl;

    // vector<pair<int, int>> vec = {{3, 1}, {2, 1}, {7, 1}, {5, 2}};
    // The pairs are sorted on the basis of first values by default
    // sort(vec.begin(), vec.end(), comparator);


    // vector<int> vec = {1, 2, 3, 4, 5};
    // // reverse(vec.begin(), vec.end());
    // reverse(vec.begin()+1, vec.begin()+3);

    // for (auto p: vec) {
    //     // cout << p.first << ", " << p.second << " | "; 
    //     cout << p << " "; 
    // }
    // cout << endl;

    // cout << *(max_element(vec.begin(), vec.end())) <<  endl;
    // cout << *(min_element(vec.begin(), vec.end())) <<  endl;

    // cout << binary_search(vec.begin(), vec.end(), 4) <<  endl;
    // cout << binary_search(vec.begin(), vec.end(), 9) <<  endl;

    // string s = "abc";
    // next_permutation(s.begin(), s.end());
    // cout << s << endl;

    // s = "bca";
    // prev_permutation(s.begin(), s.end());
    // cout << s << endl;

    // cout << min(4, 7) << endl;
    // cout << max(4, 7) << endl;

    // int a = 10;
    // int b = 5;
    // swap(a, b);

    // cout << a << " " << b << endl;

    cout << __builtin_popcount(15) << endl;
    cout << __builtin_popcountl(15) << endl;
    cout << __builtin_popcountll(15) << endl;

    return 0;
}