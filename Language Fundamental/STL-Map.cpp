#include <iostream>
#include <map>

using namespace std;

void print_map(map<char, int> m) {
    for(auto i : m) {
        cout << i.first << " - " << i.second << endl;
    }
    // begin, end, cbegin, cend, rbegin, rend, crbegin, crend also work
}

int main() {
    map<char, int> counter;

    // insertion
    counter.insert(pair<char, int>('a', 4));
    counter.insert(pair<char, int>('e', 2));
    counter.insert(pair<char, int>('i', 5));
    counter.insert(pair<char, int>('o', 0));
    counter.insert(pair<char, int>('u', 1));
    print_map(counter);

    // finding element
    cout << "Incrementing if element with e exists:" << endl;
    if(counter.find('e') != counter.end()) {
        counter.find('e')->second++;
    }
    print_map(counter);

    // size
    cout << "Size: " << counter.size() << endl;
    cout << "Max Size: " << counter.max_size() << endl;
    cout << "Empty: " << counter.empty() << endl;

    // accessing elements
    cout << "Lower and Upper bounds: " << counter.lower_bound('e')->first << " " << counter.upper_bound('e')->first << endl;
    cout << "Element at 4th Position(i.e 'o'): " << counter.at('o') << endl;
    // or counter[4]

    // deletion
    counter.erase('e');
    print_map(counter);

    // clearing map
    counter.clear();
    print_map(counter);

    return 0;
}