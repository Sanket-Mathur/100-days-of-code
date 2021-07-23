#include <iostream>
#include <algorithm>

using namespace std;

void selection_sort(int a[], int n) {
    int arr[n];
    copy(a, a+n, arr);

    for (int i = 0; i < n-1; i++) {
        int min = INT32_MAX, index = -1;
        for (int j = i; j < n; j++) {
            if (arr[j] < min) {
                min = arr[j];
                index = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[index];
        arr[index] = temp;
    }
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void bubble_sort(int a[], int n) {
    int arr[n];
    copy(a, a+n, arr);

    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insertion_sort(int a[], int n) {
    int arr[n];
    copy(a, a+n, arr);

    for (int i = 1; i < n; i++) {
        for (int j = i; j > 0; j--) {
            if (arr[j] < arr[j-1]) {
                int temp = arr[j-1];
                arr[j-1] = arr[j];
                arr[j] = temp;
            } else {
                break;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void merge(int[], int, int, int);
void merge_sort(int a[], int lo, int hi) {
    if (lo >= hi)
        return;
    
    int mid = (lo + hi) / 2;
    merge_sort(a, lo, mid);
    merge_sort(a, mid+1, hi);
    merge(a, lo, mid, hi);
}
void merge(int a[], int lo, int mid, int hi) {
    int first = lo, second = mid+1, p = 0;
    int tempArr[hi-lo+1];

    while (first <= mid && second <= hi) {
        if (a[first] > a[second]) 
            tempArr[p] = a[second++];
        else
            tempArr[p] = a[first++];
        p++;
    }
    while (first <= mid) 
        tempArr[p++] = a[first++];
    while (second <= hi)
        tempArr[p++] = a[second++];
    
    p = 0;
    for (int i = lo; i <= hi; i++) {
        a[i] = tempArr[p++];
    }
}
void merge_util(int a[], int n) {
    int arr[n];
    copy(a, a+n, arr);

    merge_sort(arr, 0, n-1);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void quick_sort(int a[], int lo, int hi) {
    if (lo >= hi)
        return;
    
    int pivot = a[hi], pi = (lo - 1);
    for (int i = lo; i < hi; i++) {
        if (a[i] < pivot) {
            pi++;
            int temp = a[pi];
            a[pi] = a[i];
            a[i] = temp;
        }
    } 
    pi++;
    int temp = a[pi];
    a[pi] = a[hi];
    a[hi] = temp;

    quick_sort(a, lo, pi - 1);
    quick_sort(a, pi + 1, hi);
}
void quick_util(int a[], int n) {
    int arr[n];
    copy(a, a+n, arr);

    quick_sort(arr, 0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void heap_sort(int a[], int n) {
    int arr[n];
    copy(a, a+n, arr);

    int temp[n];
    make_heap(arr, arr+n, greater<>{});
    for (int i = 0; i < n; i++) {
        temp[i] = arr[0];
        arr[0] = INT32_MAX;
        make_heap(arr, arr+n, greater<>{});
    }
    for (int i = 0; i < n; i++) {
        cout << temp[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {4, -9, 2, 10, 13, 6, 1, 16, 7, 17};
    int n = sizeof(arr) / sizeof(arr[0]);

    selection_sort(arr, n);
    bubble_sort(arr, n);
    insertion_sort(arr, n);
    merge_util(arr, n);
    quick_util(arr, n);
    heap_sort(arr, n);
    
    return 0;
}