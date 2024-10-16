#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> s;

    s.push(1);
    s.push(2);
    s.push(3);

    s.emplace(4);
    s.emplace(5);

    cout << s.top() << endl;

    cout << "Size: " << s.size() << endl;

    stack<int> s2;
    s2.swap(s);
    cout << "Size 1: " << s.size() << endl;
    cout << "Size 2: " << s2.size() << endl;

    s.pop();
    cout << s.top() << endl;

    while (!s.empty()){
        /* code */
        cout << s.top() << endl;
        s.pop();
    }
    

    return 0;
}