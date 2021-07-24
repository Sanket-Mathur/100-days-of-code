#include <iostream>

using namespace std;

class MinHeap {
    int *arr;
    int maxSize;
    int size;
public:
    MinHeap(int capacity) {
        maxSize = capacity;
        arr = new int[capacity];
        size = 0;
    }
    void heapify(int i) {
        int left = (2 * i + 1);
        int right = (2 * i + 2);
        int smallest = i;
        if (left < size && arr[left] < arr[i])
            smallest = left;
        if (right < size && arr[right] < arr[smallest])
            smallest = right;
        if (smallest != i) {
            int temp = arr[i];
            arr[i] = arr[smallest];
            arr[smallest] = temp;
            heapify(smallest);
        }
    }
    void insert(int value) {
        if (isFull()) {
            cout << "Heap is full! Cannot insert!" << endl;
            return;
        }
        arr[size++] = value;

        
        int i = size - 1;
        while (i != 0 && arr[parent(i)] > arr[i]) {
            int temp = arr[i];
            arr[i] = arr[parent(i)];
            arr[parent(i)] = temp;

            i = parent(i);
        }
    }
    int remove() {
        if (isEmpty()) {
            cout << "Heap is empty! Cannot remove!" << endl;
            return -1;
        }

        if (size == 1) {
            size--;
            return arr[0];
        }

        int root = arr[0];
        arr[0] = arr[size - 1];
        size--;
        heapify(0);

        return root;
    }
    int parent(int i) {
        return (i - 1) / 2;
    }
    bool isEmpty() {
        return (size == 0);
    }
    bool isFull() {
        return (size == maxSize);
    }
    void print() {
        if (isEmpty()) {
            cout << "Heap is empty!" << endl;
            return;
        }
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    MinHeap h(5);
    h.insert(4);
    h.insert(2);
    h.insert(6);
    h.insert(1);
    h.insert(10);
    h.insert(8);
    h.print();

    cout << "Removed: " << h.remove() << endl;
    h.print();
    cout << "Removed: " << h.remove() << endl;
    h.print();
    cout << "Removed: " << h.remove() << endl;
    h.print();

    return 0;
}