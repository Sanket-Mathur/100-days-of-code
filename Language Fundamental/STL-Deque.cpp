#include <iostream>
#include <deque>

using namespace std;

void print_deque(deque<int> d) {
    for(auto i : d) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    deque<int> numbers;

    // insertion and deletion
    for (int i = 5; i < 10; i++) {
        numbers.push_back(i);
    }
    for (int i = 4; i >= 0; i--) {
        numbers.push_front(i);
    }
    numbers.pop_back();
    numbers.pop_front();

    deque<int>::iterator it = numbers.begin();
    ++it;
    ++it;
    numbers.insert(it, 20);

    print_deque(numbers);

    // printing
    for(auto i = numbers.begin(); i != numbers.end(); i++) { // for(auto i = numbers.cbegin(); i != numbers.cend(); i++) {
        cout << *i << " ";
    }
    cout << endl;
    for(auto i = numbers.rbegin(); i != numbers.rend(); i++) { // for(auto i = numbers.crbegin(); i != numbers.crend(); i++) {
        cout << *i << " ";
    }
    cout << endl;
    cout << "Front and Back elements: " << numbers.front() << " " << numbers.back() << endl;

    // size of deque
    numbers.resize(5);
    cout << "\nSize: " << numbers.size() << endl;
    cout << "Max size: " << numbers.max_size() << endl;
    print_deque(numbers);

    numbers.assign(4, 10);
    print_deque(numbers);

    return 0;
}