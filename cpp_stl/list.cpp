#include <iostream>
#include <list>
using namespace std;

int main() {
    list<int> li;

    li.push_back(1);
    cout << "Size: " << li.size() << endl;
    li.push_back(2);
    cout << "Size: " << li.size() << endl;
    li.push_front(3);
    cout << "Size: " << li.size() << endl;
    li.push_front(5);

    li.emplace_back(4);
    li.emplace_front(6);

    li.pop_back();
    li.pop_front();

    for (int val: li) {
        cout << val << " ";
    }
    cout << endl;

    // cout << li[3] << endl; Not  possible

    // cout << "Capacity: " << li.capacity() << endl; Does not exist
    return 0;
}