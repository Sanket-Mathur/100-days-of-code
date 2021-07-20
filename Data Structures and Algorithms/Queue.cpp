#include <iostream>

using namespace std;

template<typename T>
class QueueArr {
    T *queue;
    int front, rear;
    int maxSize;
public:
    QueueArr(int maxSize) {
        front = -1;
        rear = -1;
        this->maxSize = maxSize;
        queue = new T[maxSize];
    }
    void enqueue(T value) {
        if(isFull()) {
            cout << "Queue is full! Cannot push!" << endl;
            return;
        }
        cout << "before puch: " << front << " " << rear << endl;
        if (front == maxSize-1 && rear != 0) front = -1;
        else if (rear == -1) rear = 0;
        queue[++front] = value;
        cout << "after puch: " << front << " " << rear << endl;
    }
    T dequeue() {
        if(isEmpty()) {
            cout << "Queue is empty! Cannot pop!" << endl;
            return T();
        }
        T popped = queue[rear];

        if (rear == front) front = rear = -1;
        else if (rear == maxSize-1) rear = 0;
        else rear++;

        return popped;
    }
    T peek() {
        if(isEmpty()) {
            cout << "Queue is empty! Cannot peek!" << endl;
            return T();
        }
        return queue[rear];
    }
    bool isEmpty() {
        return front == -1;
    }
    bool isFull() {
        return front == rear-1 || (front == maxSize-1 && rear == 0);
    }
    void print() {
        if(isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Queue: ";
        if (front >= rear) {
            for(int i = front; i >= rear; i--)
                cout << queue[i] << " ";
        } else {
            for(int i = front; i >= 0; i--) 
                cout << queue[i] << " ";
            for(int i = maxSize - 1; i >= rear; i--)
                cout << queue[i] << " ";
        }
        cout << endl;
    }
    ~QueueArr() {
        delete queue;
    }
};

int main() {
    QueueArr<int> q1(2);
    q1.print();

    q1.enqueue(2);
    q1.print();
    q1.enqueue(4);
    q1.print();
    q1.enqueue(3);

    cout << "Dequeued " << q1.dequeue() << endl;
    q1.print();

    q1.enqueue(10);
    q1.print();

    cout << "Dequeued " << q1.dequeue() << endl;
    q1.print();
    q1.dequeue();

    q1.peek();

    return 0;
}