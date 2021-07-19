#include <iostream>
#include <cmath>

using namespace std;

void print_array(int a[], int size) {
    // printing array
    for(int i = 0; i < size; i++) {
        cout << a[i] << " ";
        // cout << i[a] << " ";
    }
    cout << endl;
}

int main() {
    int arr[5];

    // taking array as input
    for(int i=0; i < 5; i++) {
        cin >> arr[i];
    }

    // passing array to function
    print_array(arr, sizeof(arr) / sizeof(arr[0]));

    // performing opertation in array
    for(int i=0; i < 5; i++) {
        arr[i] = pow(arr[i], 3);
    }
    print_array(arr, sizeof(arr) / sizeof(arr[0]));

    return 0;
}