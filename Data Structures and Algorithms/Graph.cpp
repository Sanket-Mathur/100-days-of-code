#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

class Node {
public:
    int value;
    list<Node*> edges;

    Node() : value(0) {}
    Node(int val) : value(val) {}

    void addEdge(Node *node) {
        edges.push_back(node);
    }
};

void BFS(Node *start) {
    vector<bool> visited(5, false);

    queue<Node*> queue;
    queue.push(start);

    visited[start->value] = true;
    while(!queue.empty()) {
        Node* curr = queue.front();
        cout << curr->value << " ";
        queue.pop();

        for(auto i = curr->edges.begin(); i != curr->edges.end(); ++i) {
            if (!visited[(*i)->value]) {
                queue.push(*i);
                visited[(*i)->value] = true;
            }
        }
    }
    cout << endl;
}

void DFS(Node *start) {
    vector<bool> visited(5, false);

    stack<Node*> stack;
    stack.push(start);

    visited[start->value] = true;
    while(!stack.empty()) {
        Node* curr = stack.top();
        cout << curr->value << " ";
        stack.pop();

        for(auto i = curr->edges.begin(); i != curr->edges.end(); ++i) {
            if (!visited[(*i)->value]) {
                stack.push(*i);
                visited[(*i)->value] = true;
            }
        }
    }
    cout << endl;
}

int main() {
    Node *n = new Node[5];
    for(int i = 0; i < 5; i++) {
        n[i] = Node(i);
    }

    n[0].addEdge(&n[2]);
    n[0].addEdge(&n[4]);
    n[2].addEdge(&n[1]);
    n[2].addEdge(&n[3]);
    n[3].addEdge(&n[0]);
    n[3].addEdge(&n[1]);

    /*
            0 -> 2 -> 1
            | ^  |   ^
            v  \ v /
            4    3
    */

    BFS(&n[0]);
    DFS(&n[0]);
    return 0;
}