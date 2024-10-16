#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    priority_queue<int> pq;

    pq.push(5);
    pq.push(3);
    pq.push(10);

    pq.emplace(4);

    cout << "Size: " << pq.size() << endl; 

    while (!pq.empty()){
        /* code */
        cout << pq.top() << endl;
        pq.pop();
    }

    priority_queue<int, vector<int>, greater<int>> rpq;

    rpq.push(5);
    rpq.push(3);
    rpq.push(10);

    rpq.emplace(4);

    cout << "Size: " << rpq.size() << endl;

    while (!rpq.empty()){
        /* code */
        cout << rpq.top() << endl;
        rpq.pop();
    }

    return 0;
}