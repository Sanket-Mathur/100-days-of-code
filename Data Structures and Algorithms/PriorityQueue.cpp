#include <iostream>

using namespace std;

template<typename T>
class Node {
public:
    T val;
    int priority;
    Node *next;
    Node() {
        val = -1;
        priority = 0;
        next = nullptr;
    }
    Node(T val, int priority) {
        this->val = val;
        this->priority = priority;
        next = nullptr;
    }
};

template<typename T>
class PriorityQueue {
    Node<T> *head;
public:
    PriorityQueue() {
        head = new Node<T>;
    }
    void enqueue(T val, int priority) {
        Node<T> *node = head;
        while (node->next && node->next->priority >= priority) {
            node = node->next;
        }
        Node<T> *newNode = new Node<T>(val, priority);
        newNode->next = node->next;
        node->next = newNode;
    }
    T dequeue() {
        if (isEmpty()) {
            cout << "Priority Queue is empty!" << endl;
            return T();
        }
        T result = head->next->val;
        head->next = head->next->next;
        return result;
    }
    bool isEmpty() {
        return !(head->next);
    }
    void print() {
        if(!head->next) {
            cout << "PriorityQueue is empty" << endl;
            return;
        }
        Node<T> *node = head->next;
        while(node) {
            cout << node->priority << "-" << node->val << " ";
            node = node->next;
        }
        cout << endl;
    }
    ~PriorityQueue() {
        Node<T> *node = head->next;
        while(head) {
            cout << "Deleting " << head->priority << "-" << head->val << endl;
            delete head;
            head = node;
            node = node->next;
        }
    }
};

int main() {
    PriorityQueue<int> pq;
    pq.print();
    pq.enqueue(5, 2);
    pq.print();
    pq.enqueue(4, 1);
    pq.print();
    pq.enqueue(2, 5);
    pq.print();
    pq.enqueue(12, 0);
    pq.print();
    pq.enqueue(8, 4);
    pq.print();
    cout << "Dequeued: " << pq.dequeue() << endl;
    cout << "Dequeued: " << pq.dequeue() << endl;
    cout << "Dequeued: " << pq.dequeue() << endl;
    cout << "Dequeued: " << pq.dequeue() << endl;
    cout << "Dequeued: " << pq.dequeue() << endl;
    pq.dequeue();

    return 0;
}