#include <iostream>

using namespace std;

class Node {
public:
    int value;
    Node* prev;
    Node* next;
    Node() {
        value = -1;
        prev = nullptr;
        next = nullptr;
    }
    Node(int val) {
        value = val;
        prev = nullptr;
        next = nullptr;
    }
};

void insertEnd(Node *head, int value) {
    if (head->value == -1) {
        head->value = value;
        return;
    }
    Node *node = head;
    while (node->next) {
        node = node->next;
    }
    Node *newNode = new Node(value);
    newNode->prev = node;
    node->next = newNode;
}


Node* insertStart(Node *head, int value) {
    if (head->value == -1) {
        head->value = value;
        return head;
    }
    Node *newNode = new Node(value);
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
    return head;
}

void remove(Node *head, int value) {
    Node *node = head;
    while (node && node->value != value) {
        node = node->next;
    }
    if (!node) {
        cout << "Key not present" << endl;
    } else {
        node->next->prev = node->prev;
        node->prev->next = node->next;
        delete node;
    }
}

void print(Node *head) {
    if (head->value == -1) {
        cout << "List is empty!" << endl;
        return;
    }
    Node *node = head;
    while (node) {
        cout << node->value << " ";
        node = node->next;
    }
    cout << endl;
}

int main() {
    Node *head = new Node;

    print(head);
    insertEnd(head, 40);
    insertEnd(head, 60);
    insertEnd(head, 80);
    print(head);
    head = insertStart(head, 20);
    head = insertStart(head, 0);
    print(head);
    remove(head, 40);
    print(head);

    return 0;
}