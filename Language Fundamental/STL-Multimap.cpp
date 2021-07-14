#include <iostream>
#include <map>

using namespace std;

void print_multimap(multimap<long, int> m) {
    cout << "Map" << endl;
    for(auto i : m) {
        cout << i.first << " " << i.second << endl;
    }
}

int main() {
    multimap<long, int> discount;  

    // insertion
    cout << "Inserting some pairs in the map" << endl;
    discount.insert(pair<long, int> (123456, 40));
    discount.insert(pair<long, int> (124897, 20));
    discount.insert(pair<long, int> (247865, 60));
    discount.insert(pair<long, int> (123456, 60));
    print_multimap(discount);

    // printing
    cout << "First Elements of pairs" << endl;
    for(auto i = discount.begin(); i != discount.end(); i++) { // for(auto i = discount.cbegin(); i != discount.cend(); i++) {
        cout << i->first << " ";
    }
    cout << endl;
    cout << "Second Elements of pairs in reverse order" << endl;
    for(auto i = discount.rbegin(); i != discount.rend(); i++) { // for(auto i = discount.crbegin(); i != discount.crend(); i++) {
        cout << i->second << " ";
    }
    cout << endl;

    // size
    cout << "Size: " << discount.size() << endl;
    cout << "Max Size: " << discount.max_size() << endl;

    // finding elements
    cout << "Discount of 124897: " << discount.find(124897)->second << endl;
    cout << "Count of pairs with key 123456: " << discount.count(123456) << endl;

    // deletion
    cout << "Deleting 124897" << endl;
    discount.erase(124897);
    print_multimap(discount);

    return 0;
}