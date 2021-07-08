#include <iostream>
#include <algorithm>
#include <time.h>

using namespace std;

int main() {
    srand(time(0));
    int size = rand() % 20 + 1;
    int arr[size];
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 100;
    }

    // sorting
    for(auto i : arr) {
        cout << i << " ";
    }
    cout << endl;
    sort(arr, arr + size);
    for(auto i : arr) {
        cout << i << " ";
    }
    cout << endl;

    //searching
    int element;
    if(rand() % 2) {
        element = rand() % 100;
    } else {
        element = arr[rand() % 20];
    }
    cout << "Element: " << element << endl;
    if(binary_search(arr, arr + size, element)) {
        cout << "Element is found" << endl;
    } else {
        cout << "Element is not found" << endl;
    }

    return 0;
}