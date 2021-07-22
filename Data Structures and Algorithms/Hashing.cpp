#include <iostream>

using namespace std;

int table[50][2];

int hashFunction(int value) {
    return (4*value + 10) % 50;
}

void insert(int value) {
    bool negative = value < 0;
    if (negative) {
        value = -value;
    }

    int iter = 0, start = hashFunction(value);
    int index = start;
    do {
        if (!table[index][negative ? 1 : 0] || table[index][negative ? 1 : 0] == value) {
            table[index][negative ? 1 : 0] = value;
            return;
        }
        iter++;
        index = hashFunction(value + iter*hashFunction(value));
    } while(index != start);
    cout << "Could not insert " << endl;
}

int search(int value) {
    bool negative = value < 0;
    if (negative) {
        value = -value;
    }

    int iter = 0, start = hashFunction(value);
    int index = start;
    do {
        if (table[index][negative ? 1 : 0] == value) {
            return index;
        } else if (!table[index][negative ? 1 : 0]) {
            return -1;
        }
        iter++;
        index = hashFunction(value + iter*hashFunction(value));
    } while(index != start);
    return -1;
}

void remove(int value) {
    int index = search(value); 
    bool negative = value < 0;
    
    if (index != -1) {
        table[index][negative ? 1 : 0] = 0;
    }
}

int main() {
    int elements[] = {2, 5, -80, -4, 20, 4, 18, -24};
    for (auto i : elements) {
        insert(i);
    }

    cout << search(20) << endl;
    cout << search(4) << endl;
    cout << search(-4) << endl;
    cout << search(24) << endl;

    remove(4);
    cout << search(4) << endl;
    cout << search(-4) << endl;

    return 0;
}