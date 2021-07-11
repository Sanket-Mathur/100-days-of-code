#include <iostream>
#include <queue>

using namespace std;

void print_priority(priority_queue<int, vector<int>, greater<int>> pq) {
    while(!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
}

int main() {
    priority_queue<int, vector<int>, greater<int>> scheduler;

    // insertion
    scheduler.push(50);
    scheduler.push(20);
    scheduler.push(80);
    scheduler.push(10);
    scheduler.push(40);

    print_priority(scheduler);

    // deletion
    scheduler.pop();
    print_priority(scheduler);

    // size
    cout << "Size: " << scheduler.size() << endl;
    return 0;
}