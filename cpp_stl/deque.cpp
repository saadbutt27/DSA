#include <iostream>
#include <deque>
using namespace std;

int main() {
    deque <int> dq = {-1, 0};

    dq.push_back(1);
    dq.push_back(2);
    dq.push_front(3);
    dq.push_front(5);

    dq.emplace_back(4);
    dq.emplace_front(6);

    dq.pop_back();
    dq.pop_front();

    for (int val: dq) {
        cout << val << " ";
    }
    cout << endl;

    cout << "Size: " << dq.size() << endl;
    // cout << "Capacity: " << dq.capacity() << endl; // does not exist

    cout << dq[3] << endl;
    return 0;
}