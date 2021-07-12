#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void print_vector(vector<int> v) {
    for(auto i : v) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    vector<int> heap = {20, 10, 50, 60, 40};
    
    // making heap
    make_heap(heap.begin(), heap.end());
    print_vector(heap);

    // pushing and popping
    heap.push_back(30);
    push_heap(heap.begin(), heap.end());
    print_vector(heap);
    pop_heap(heap.begin(), heap.end());
    heap.pop_back();
    print_vector(heap);

    // sorting
    sort_heap(heap.begin(), heap.end());
    print_vector(heap);

    // checking if still heap
    cout << is_heap(heap.begin(), heap.end()) << endl;

    return 0;
}