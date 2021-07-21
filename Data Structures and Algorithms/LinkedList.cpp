#include <iostream>

using namespace std;

template<typename T>
class Node {
public:
    T val;
    Node<T> *next;
    Node() {
        val = -1;
        next = nullptr;
    }
    Node(T val) {
        this->val = val;
        next = nullptr;
    }
};

template<typename T>
class LinkedList {
    Node<T> *head;
public:
    LinkedList() {
        // dummy node
        head = new Node<T>;
    }
    void insertNodeFront(T value) {
        Node<T> *node = new Node<T>(value);
        node->next = head->next;
        head->next = node;
    }
    void insertNodeBack(T value) {
        Node<T> *node = new Node<T>(value);
        Node<T> *last = head;
        while (last->next) {
            last = last->next;
        }
        last->next = node;
    }
    void insertNodeAfter(T value, T prev) {
        Node<T> *node = new Node<T>(value);
        Node<T> *loc = head;
        while(loc->val != prev && loc->next) {
            loc = loc->next;
        }
        node->next = loc->next;
        loc->next = node;
    }
    T deleteNodeFront() {
        if (isEmpty()) {
            cout << "LinkedList is empty!" << endl;
            return T();
        }
        Node<T> *node = head->next;
        head->next = head->next->next;

        T element = node->val;
        delete node;
        return element;
    }
    T deleteNodeBack() {
        if (isEmpty()) {
            cout << "LinkedList is empty!" << endl;
            return T();
        }
        Node<T> *secondlast = head;
        while (secondlast->next->next) {
            secondlast = secondlast->next;
        }
        T element = secondlast->next->val;
        delete secondlast->next;
        secondlast->next = nullptr;
        return element;
    }
    T deleteNodeAfter(T prev) {
        if (isEmpty()) {
            cout << "LinkedList is empty!" << endl;
            return T();
        }
        Node<T> *loc = head;
        while(loc->val != prev && loc->next->next) {
            loc = loc->next;
        }
        T element = loc->next->val;
        Node<T> *node = loc->next;
        loc->next = loc->next->next;
        delete node;
        return element;        
    }
    bool isEmpty() {
        return !head->next;
    }
    void print() {
        if (isEmpty()) {
            cout << "LinkedList is empty!" << endl;
            return;
        }
        Node<T> *node = head->next;
        while (node) {
            cout << node->val << " ";
            node = node->next;
        }
        cout << endl;
    }
    ~LinkedList() {
        Node<T> *node = head->next;
        while (head) {
            delete head;
            head = node;
            node = node->next;
        }
    }
};

int main() {
    LinkedList<char> ll;
    ll.insertNodeFront('e');
    ll.insertNodeFront('a');
    ll.insertNodeBack('o');
    ll.insertNodeBack('u');
    ll.insertNodeAfter('i', 'e');
    ll.print();

    cout << "Deleted: " << ll.deleteNodeFront() << endl;
    cout << "Deleted: " << ll.deleteNodeBack() << endl;
    cout << "Deleted: " << ll.deleteNodeAfter('e') << endl;
    ll.print();

    ll.deleteNodeFront();
    ll.deleteNodeFront();
    ll.deleteNodeFront();
    return 0;
}