#include <iostream>
#include <set>

using namespace std;

void print_set(set<int, less<int>> s) {
    for(auto i : s) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    set<int, less<int>> score;
    
    // insertion
    cout << "Inserting 20, 50, 40, 80" << endl;
    score.insert(20);
    score.insert(50);
    score.insert(40);
    score.insert(80);
    print_set(score);

    // printing
    for(auto i = score.begin(); i != score.end(); i++) { // for(auto i = score.cbegin(); i != score.cend(); i++) {
        cout << *i << " ";
    }
    cout << endl;
    for(auto i = score.rbegin(); i != score.rend(); i++) { // for(auto i = score.crbegin(); i != score.crend(); i++) {
        cout << *i << " ";
    }
    cout << endl;

    // size  
    cout << "Size: " << score.size() << endl;
    cout << "Max Size: " << score.max_size() << endl;

    // finding element
    if(score.find(40) != score.end()) {
        cout << "Found " << *score.find(40) << endl;
    }
    if(score.count(100) == 0) {
        cout << "100 doesn't exist" << endl;
    }

    cout << "Lower and Upper bound iterators: " << *score.lower_bound(40) << " " << *score.upper_bound(40) << endl;    // 

    // deletion
    score.erase(score.upper_bound(40));
    score.erase(20);
    print_set(score);

    return 0;
}