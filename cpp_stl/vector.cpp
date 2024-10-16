#include <iostream>
#include <vector>
using namespace std;

int main() {

    vector<int> vec; // size = 0

    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);

    // vec.emplace_back(6);

    // vec.pop_back();
    
    cout << "Size: " << vec.size() << endl;
    cout << "Capacity: " << vec.capacity() << endl;

    cout << "vec: ";
    for (int cal: vec) {
        cout << cal << " ";
    }
    cout << endl;

    // cout << "value at index 2 is " << vec.at(2) << " " << vec[2] << endl;

    // cout << "front " << vec.front() << endl;
    // cout << "back " << vec.back() << endl;

    // vec.erase(vec.begin()); // erase first element
    // vec.erase(vec.begin() + 2); // erase 3rd element
    // vec.erase(vec.begin() + 1, vec.begin() + 3); // erase a range of elements(from 1st to 2nd element)
    // cout << "vec after erasing element: ";

    // vec.insert(vec.begin() + 2, 100); // insert 100 at index 2
    // cout << "vec after inserting element: ";

    // cout << "Vector is empty? " << vec.empty() << endl;

    // vec.clear();
    // cout << "vec after clearning: ";
    // for (int cal: vec) {
    //     cout << cal << " ";
    // }
    // cout << endl;

    // cout << "Vector is empty? " << vec.empty() << endl;

    // cout << "Size: " << vec.size() << endl;
    // cout << "Capacity: " << vec.capacity() << endl;

    cout << "vec.begin: " << *(vec.begin()) << endl;
    cout << "vec.end: " << *(vec.end()) << endl;

    vector<int>::iterator it;
    cout << "Using iterator: ";
    for (it = vec.begin(); it != vec.end(); it++) {
        cout << *(it) << " ";
    }
    cout << endl;

    cout << "Using reverse iterator: ";
    for (auto rit = vec.rbegin(); rit != vec.rend(); rit++) {
        cout << *(rit) << " ";
    }
    cout << endl;


    // vector<int> vec1 = {1, 2, 3};
    // cout << "vec1: ";
    // for (int val: vec1) {
    //     cout << val << " ";
    // }
    // cout << endl;

    // vector<int> vec2(10, -1);
    // cout << "vec2: ";
    // for (int val: vec2) {
    //     cout << val << " ";
    // }
    // cout << endl;

    // vector<int> vec3(vec2);
    // cout << "vec3: ";
    // for (int val: vec3) {
    //     cout << val << " ";
    // }
    // cout << endl;

    return 0;
}