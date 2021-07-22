#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

bool linear_search(int arr[], int n, int value) {
    for(int i = 0; i < n; i++) {
        if (arr[i] == value) {
            return true;
        }
    }
    return false;
}

bool binary_search(int arr[], int n, int value) {
    int beg = 0, end = n-1, mid;
    while(beg <= end) {
        mid = (beg + end) / 2;
        if (arr[mid] == value)
            return true;
        else if (arr[mid] > value)
            end = mid - 1;
        else
            beg = mid + 1;
    }
    return false;
}

bool jump_search(int arr[], int n, int value) {
    int m = abs(sqrt(n));
    for (int i = 0; i < n; i += m) {
        if (arr[i] == value) 
            return true;
        else if (arr[i] > value) {
            int prev = i - m;
            for (int j = prev; j < i; j++) {
                if (arr[j] == value)
                    return true;
            }
            return false;
        }
    }
    return false;
}

bool interpolation_search(int arr[], int lo, int hi, int value) {
    if (lo > hi || value < arr[lo] || value > arr[hi])
        return false;
    
    int pos = lo + (((double)(hi - lo) / (arr[hi] - arr[lo])) * (value - arr[lo]));
    if (arr[pos] == value)
        return true;
    else if (arr[pos] < value)
        return interpolation_search(arr, pos + 1, hi, value);
    return interpolation_search(arr, lo, pos - 1, value);
}

bool exponential_search(int arr[], int n, int value) {
    if (arr[0] == value)
        return true;
    
    int i = 1;
    while (i < n && arr[i] <= value) {
        i *= 2;
    }

    return interpolation_search(arr, i/2, min(i, n-1), value);
}

int main() {
    int arr[] = {9, 2, 1, 6, 12, 4, 16, 7, 3, 14, 24, 21, 8, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Unsorted array
    cout << "Valid Element: " << linear_search(arr, n, 12) << "\tInvalid Element: " << linear_search(arr, n, 22) << endl;

    // Sorted array
    sort(arr, arr+n);
    cout << "Valid Element: " << binary_search(arr, n, 12) << "\tInvalid Element: " << binary_search(arr, n, 22) << endl;
    cout << "Valid Element: " << jump_search(arr, n, 12) << "\tInvalid Element: " << jump_search(arr, n, 22) << endl;
    cout << "Valid Element: " << interpolation_search(arr, 0, n - 1, 12) << "\tInvalid Element: " << interpolation_search(arr, 0, n - 1, 22) << endl;
    cout << "Valid Element: " << exponential_search(arr, n, 12) << "\tInvalid Element: " << exponential_search(arr, n, 22) << endl;
    return 0;
}