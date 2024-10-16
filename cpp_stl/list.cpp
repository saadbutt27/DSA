#include <iostream>
#include <list>
using namespace std;

int main() {
    list<int> li;

    li.push_back(1);
    li.push_back(2);
    li.push_front(3);
    li.push_front(5);

    li.emplace_back(4);
    li.emplace_front(6);

    li.pop_back();
    li.pop_front();

    for (int val: li) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}