#include <iostream>

using namespace std;

template<typename T>
class StackArr {
    T *stack;
    int size;
    int maxSize;
public:
    StackArr(T maxSize) {
        size = 0;
        this->maxSize = maxSize;
        stack = new T[maxSize];
    }
    void push(T value) {
        if(isFull()) {
            cout << "Stack is full! Cannot push!" << endl;
            return;
        }
        stack[size++] = value;
    }
    T pop() {
        if(isEmpty()) {
            cout << "Stack is empty! Cannot pop!" << endl;
            return T();
        }
        return stack[--size];
    }
    T peek() {
        if(isEmpty()) {
            cout << "Stack is empty! Cannot peek!" << endl;
            return T();
        }
        return stack[size - 1];
    }
    bool isEmpty() {
        return size == 0;
    }
    bool isFull() {
        return size == maxSize;
    }
    void print() {
        if(isEmpty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << "Stack: ";
        for(int i = 0; i < size; i++) {
            cout << stack[i] << " ";
        }
        cout << endl;
    }
};

template<typename T>
class Node {
public:
    T val;
    Node *next;
    Node() : val(), next(nullptr) {}
};

template<typename T>
class StackLL {
    Node<T> *head;
public:
    StackLL() {
        head = nullptr;
    }
    void push(T value) {
        Node<T> *node = new Node<T>;
        node->val = value;
        node->next = head;
        head = node;
    }
    T pop() {
        if(isEmpty()) {
            cout << "Stack is empty! Cannot pop!" << endl;
            return T();
        }
        T top = head->val;
        head = head->next;
        return top;
    }
    T peek() {
        if(isEmpty()) {
            cout << "Stack is empty! Cannot peek!" << endl;
            return T();
        }
        return head->val;
    }
    bool isEmpty() {
        return !head;
    }
    void print() {
        if(isEmpty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        Node<T> *node = head;
        cout << "Stack: ";
        while(node) {
            cout << node->val << " ";
            node = node->next;
        }
        cout << endl;
    }
    ~StackLL() {
        while(head) {
            Node<T> *node = head->next;
            delete head;
            head = node;
        }
        cout << "Deleted Stack" << endl;
    }
};

int main() {
    StackArr<int> s1(2);
    s1.print();

    s1.push(2);
    s1.print();
    s1.push(4);
    s1.print();
    s1.push(3);

    cout << "Popped " << s1.pop() << endl;
    s1.print();
    cout << "Popped " << s1.pop() << endl;
    s1.print();
    s1.pop();

    s1.peek();

    StackLL<int> s2;
    s2.push(5);
    s2.push(10);
    s2.push(20);
    s2.print();
    cout << "Popped " << s2.pop() << endl;
    cout << "Popped " << s2.pop() << endl;
    cout << "Popped " << s2.pop() << endl;
    s2.pop();
    s2.print();
    return 0;
}