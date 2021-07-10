#include <iostream>
#include <list>

using namespace std;

void print_list(list<int> l) {
    for(auto i : l) {
        cout << i << " ";
    }
    cout << endl;
}

bool greaterThan6(int x) {
    return x > 6;
}

int main() {
    list<int> linkedlist;

    // insertion and deletion
    for(int i = 5; i < 10; i++) {
        linkedlist.push_back(i);
    }
    for(int i = 4; i >= 0; i--) {
        linkedlist.push_front(i);
    }
    print_list(linkedlist);

    linkedlist.pop_front();
    linkedlist.pop_back();
    print_list(linkedlist);
    
    linkedlist.remove(5);
    linkedlist.remove_if(greaterThan6);
    linkedlist.insert(linkedlist.begin(), 40);
    print_list(linkedlist);

    // printing list 
    cout << "\nPrinting in same and reverse order" << endl;
    for(auto i = linkedlist.begin(); i != linkedlist.end(); i++) { // for(auto i = linkedlist.cbegin(); i != linkedlist.cend(); i++)
        cout << *i << " ";
    }
    cout << endl;
    for(auto i = linkedlist.rbegin(); i != linkedlist.rend(); i++) { // for(auto i = linkedlist.crbegin(); i != linkedlist.crend(); i++)
        cout << *i << " ";
    }
    cout << endl;

    cout << "\nFront and Back element: " << linkedlist.front() << " " << linkedlist.back() << endl;

    // reversing the list
    cout << "\nReversed List: ";
    linkedlist.reverse();
    print_list(linkedlist);

    // sorting list
    cout << "\nSorted List: ";
    linkedlist.sort();
    print_list(linkedlist);

    return 0;
}