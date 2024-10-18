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

    vector<pair<int, int>> vec = {{3, 1}, {2, 1}, {7, 1}, {5, 2}};
    sort(vec.begin(), vec.end(), comparator);

    // The pairs are sorted on the basis of first values by default

    for (auto p: vec) {
        cout << p.first << ", " << p.second << " | "; 
    }
    cout << endl;
    
    return 0;
}