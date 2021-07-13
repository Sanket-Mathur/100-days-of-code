#include <iostream>
#include <set>

using namespace std;

void print_multiset(multiset<int> m) {
    for(auto i : m) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    multiset<int> collection;

    // insertion
    cout << "Inserting 20, 30, 60, 20, 10" << endl;
    collection.insert(20);
    collection.insert(30);
    collection.insert(60);
    collection.insert(20);
    collection.insert(10);
    print_multiset(collection);

    // printing
    for(auto i = collection.begin(); i != collection.end(); i++) { // for(auto i = collection.cbegin(); i != collection.cend(); i++) {
        cout << *i << " ";
    }
    cout << endl;
    for(auto i = collection.rbegin(); i != collection.rend(); i++) { // for(auto i = collection.crbegin(); i != collection.crend(); i++) {
        cout << *i << " ";
    }
    cout << endl;

    // size  
    cout << "Size: " << collection.size() << endl;
    cout << "Max Size: " << collection.max_size() << endl;

    // deletion
    cout << "Erasing 20 and 60" << endl;
    collection.erase(20);
    collection.erase(60);
    print_multiset(collection);

    return 0;
}