#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q;

    q.push(1);
    q.push(2);
    q.push(3);

    q.emplace(4);
    q.emplace(5);

    while (!q.empty()){
        /* code */
        cout << q.front() << endl;
        q.pop();
    }

    cout << "Size: " << q.size() << endl;

    queue<int> q1;
    q1.push(1);    
    q1.push(2);    
    cout << "Size: " << q1.size() << endl;
    q1.swap(q);
    cout << "Size: " << q1.size() << endl;
    cout << "Size: " << q.size() << endl;
    
    return 0;
}