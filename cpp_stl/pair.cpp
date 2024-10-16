#include <iostream>
#include <vector>
using namespace std;

int main() {
    pair<int, int> p = {3, 4};
    cout << p.first << endl;
    cout << p.second << endl;


    pair<string, int> p2 = {"Saad", 22};
    cout << p2.first << endl;
    cout << p2.second << endl;


    pair<int, pair<int, float>> p3 = {3, {3, 4.5f}};
    cout << p3.first << endl;
    cout << p3.second.first << endl;
    cout << p3.second.second << endl;

    // vector of pairs
    vector<pair<int, int>> vec = {{1,2}, {3,2}, {5,6}};

    vec.push_back({4, 5}); // assumes that datatype is already set 

    vec.emplace_back(6, 7); // creates in-place objects at the time of insertion
    
    // for (pair<int, int> p: vec) {
    for (auto p: vec) {
        cout << p.first << ", " << p.second << endl; 
    }
    cout << endl;

    return 0;
}