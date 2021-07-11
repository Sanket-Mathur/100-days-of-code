#include <iostream>
#include <queue>
#include <string>

using namespace std;

void print_queue(queue<string> q) {
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main() {
    queue<string> line; 

    // insertion
    cout << "Inserting Bob, John, Watson, Mary" << endl;
    line.push("Bob");
    line.push("John");
    line.push("Watson");
    line.push("Mary");
    print_queue(line);

    cout << "Front and Back elements: " << line.front() << " " << line.back() << endl;

    // size of queue
    cout << "Size: " << line.size() << endl;
    cout << "Empty: " << line.empty() << endl;

    // deletion
    line.pop();
    print_queue(line);

    return 0;
}