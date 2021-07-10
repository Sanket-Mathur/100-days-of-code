#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print_vector(vector<int> v) {
    for(auto i : v) {
        cout << i << " ";
    }
    cout << endl;
} 

bool reverse_sort(int a, int b) {
    return b < a;
}

int main() {
    vector<int> numbers;
    for(int i = 0; i < 10; i++) {
        numbers.push_back(i);
    }

    // printing vector in normal and reverse order
    for(auto i = numbers.begin(); i != numbers.end(); i++) { // for(auto i = numbers.cbegin(); i != numbers.cend(); i++)
        cout << *i << " ";
    }
    cout << endl;
    for(auto i = numbers.rbegin(); i != numbers.rend(); i++) { // for(auto i = numbers.crbegin(); i != numbers.crend(); i++)
        cout << *i << " ";
    }
    cout << endl;

    // size of vector
    cout << "\nVector by Default" << endl;
    cout << "Size: " << numbers.size() << endl;
    cout << "Capacity: " << numbers.capacity() << endl; 
    cout << "Max Size: " << numbers.max_size() << endl;

    cout << "\nVector after Shrinking" << endl;
    numbers.shrink_to_fit();
    cout << "Size: " << numbers.size() << endl;
    cout << "Capacity: " << numbers.capacity() << endl; 
    cout << "Max Size: " << numbers.max_size() << endl;

    cout << "\nResizing the Vector to 5" << endl;
    numbers.resize(5);
    print_vector(numbers);

    // element access
    cout << "\nElement at 3: " << numbers.at(3) << endl; // numbers[3]
    cout << "Front and Back elements: " << numbers.front() << " " << numbers.back() << endl;
    
    // modification
    cout << "\nPopping element from back" << endl;
    numbers.pop_back();
    print_vector(numbers);

    // copying elements
    vector<int> modified(5);
    cout << "\nCopying Elements" << endl;
    modified.assign(numbers.begin(), numbers.end()); // copy(numbers.begin(), numbers.end(), back_inserter(modified)); OR modified = numbers
    print_vector(modified);

    // insertion and deletion
    modified.erase(modified.begin());
    modified.insert(modified.end(), 4);
    modified.insert(modified.end()-1, 5);
    print_vector(modified);

    // sorting
    cout << "\nSorting" << endl;
    sort(modified.begin(), modified.end());
    print_vector(modified);
    sort(modified.begin(), modified.end(), reverse_sort);
    print_vector(modified);

    // clearing
    cout << "\nClearing" << endl;
    modified.clear();
    print_vector(modified);

    return 0;
}