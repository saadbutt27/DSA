#include <iostream>
#include <set>
#include <unordered_set>
using namespace std;

int main() {
    set<int> s;

    s.insert(1);
    s.insert(2);
    s.insert(3);

    s.emplace(4);
    s.emplace(5);

    s.insert(1);
    s.emplace(7);

    for (auto val: s) {
        cout << val << " ";
    }
    cout << endl;

    // cout << "Size = " << s.size() << endl;

    cout << "lower bound = " << *(s.lower_bound(4)) << endl;
    cout << "lower bound = " << *(s.lower_bound(6)) << endl;
    cout << "lower bound = " << *(s.lower_bound(8)) << endl;

    cout << "upper bound = " << *(s.upper_bound(4)) << endl;
    cout << "upper bound = " << *(s.upper_bound(7)) << endl;
    cout << "upper bound = " << *(s.upper_bound(10)) << endl;

    cout << endl;

    multiset<int> ms;
    ms.insert(1);
    ms.insert(2);
    ms.insert(3);

    ms.emplace(1);
    ms.emplace(2);

    for (auto val: ms) {
        cout << val << " ";
    }
    cout << endl;

    cout << endl;

    unordered_set<int> us;
    us.insert(1);
    us.insert(2);
    us.insert(3);

    us.emplace(1);
    us.emplace(2);

    for (auto val: us) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}