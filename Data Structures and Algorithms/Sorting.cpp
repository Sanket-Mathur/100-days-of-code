#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <string.h>

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

void count_sort(int a[], int n) {
    int output[n], count[*max_element(a, a+n)+1];
    memset(count, 0, sizeof(count));

    for (int i = 0; i < n; i++)
        ++count[a[i]];
    for (int i = 1; i <= *max_element(a, a+n); ++i)
        count[i] += count[i - 1];
    for (int i = 0; i < n; i++) {
        output[count[a[i]] - 1] = a[i];
        --count[a[i]];
    }

    for (int i = 0; i < n; i++) {
        cout << output[i] << " ";
    }
    cout << endl;
}

void radix_sort(int a[], int n) {
    int arr[n];
    copy(a, a+n, arr);

    int m = *max_element(arr, arr+n);
    for(int exp = 1; m / exp > 0; exp *= 10) {
        int output[n];
        int i, count[10] = { 0 };
    
        for (i = 0; i < n; i++)
            count[(arr[i] / exp) % 10]++;    
        for (i = 1; i < 10; i++)
            count[i] += count[i - 1];    
        for (i = n - 1; i >= 0; i--) {
            output[count[(arr[i] / exp) % 10] - 1] = arr[i];
            count[(arr[i] / exp) % 10]--;
        }

        for (i = 0; i < n; i++)
            arr[i] = output[i];
    }
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void shell_sort(int a[], int n) {
    int arr[n];
    copy(a, a+n, arr);

    for (int h = n/2; h > 0; h /= 2) {
        for (int i = h; i < n; i++) {
            int temp = arr[i];
            int j = i;
            while (j >= h && arr[j - h] > temp) {
                arr[j] = arr[j - h];
                j -= h;
            }
            arr[j] = temp;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void tim_sort(int a[], int n) {
    int arr[n];
    copy(a, a+n, arr);
    int RUN = 4;

    for (int i = 0; i < n; i += RUN) {
        int left = i, right = min(i + RUN, n);
        for (int i = left + 1; i < right; i++) {
            for (int j = i; j > left; j--) {
                if (arr[j] < arr[j-1]) {
                    int temp = arr[j-1];
                    arr[j-1] = arr[j];
                    arr[j] = temp;
                } else {
                    break;
                }
            }
        }
    }

    for (int size = RUN; size < n; size *= 2) {
        for (int left = 0; left < n; left += 2*size) {
            int mid = left + size - 1;
            int right = min(left + 2*size - 1, n - 1);
            if (mid < right) {
                merge(arr, left, mid, right);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void comb_sort(int a[], int n) {
    int arr[n];
    copy(a, a+n, arr);

    int gap = n;
    bool swapped = true;
    while (gap != 1 || swapped) {
        gap = (gap * 10) / 13;
        if (gap < 1)
            gap = 1;
        
        swapped = false;
        for (int i = 0; i < n - gap; i++) {
            if (arr[i] > arr[i + gap]) {
                swapped = true;
                int temp = arr[i];
                arr[i] = arr[i + gap];
                arr[i + gap] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void pigeonhole_sort(int a[], int n) {
    int arr[n];
    copy(a, a+n, arr);

    int min = INT32_MAX, max = INT32_MIN;
    for (int i = 0; i < n; i++) {
        if (arr[i] < min) 
            min = arr[i];
        if (arr[i] > max)
            max = arr[i];
    }
    int range = max - min + 1;

    vector<int> pigeonholes[range];
    for (int i = 0; i < n; i++) {
        pigeonholes[arr[i] - min].push_back(arr[i]);
    }

    int index = 0;
    for (auto i : pigeonholes) {
        for (auto j : i) {
            arr[index++] = j;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void cycle_sort(int a[], int n) {
    int arr[n];
    copy(a, a+n, arr);

    for (int cycle = 0; cycle <= n - 2; cycle++) {
        int item = arr[cycle];
        int pos = cycle;
        for (int i = cycle + 1; i < n; i++) {
            if (arr[i] < item)
                pos++;
        }

        if (pos == cycle)
            continue;

        while (item == arr[pos]) {
            pos++;
        }
        if (pos != cycle) {
            int temp = item;
            item = arr[pos];
            arr[pos] = temp;
        }

        while (pos != cycle) {
            pos = cycle;
            for (int i = cycle + 1; i < n; i++) {
                if (arr[i] < item)
                    pos += 1;
            }

            while (item == arr[pos]) {
                pos++;
            }
            if (item != arr[pos]) {
                int temp = item;
                item = arr[pos];
                arr[pos] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void cocktail_sort(int a[], int n) {
    int arr[n];
    copy(a, a+n, arr);

    bool swapped = true;
    int start = 0, end = n - 1;

    while (swapped) {
        swapped = false;
        for (int i = start; i < end; i++) {
            if (arr[i] > arr[i + 1]) {
                swapped = true;
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
        end--;

        swapped = false;
        for (int i = end - 1; i >= start; i--) {
            if (arr[i] > arr[i + 1]) {
                swapped = true;
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
        start++;
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void strand_sort(list<int> &ip, list<int> &op) {
    if (ip.empty())
        return;

    list<int> sublist;
    sublist.push_back(ip.front());
    ip.pop_front();

    for (auto i = ip.begin(); i != ip.end(); ) {
        if (*i > sublist.back()) {
            sublist.push_back(*i);
            i = ip.erase(i);
        } else {
            i++;
        }
    }

    op.merge(sublist);
    strand_sort(ip, op);
}
void strand_util(int a[], int n) {
    list<int> ip, op;
     for (int i = 0; i < n; i++) {
        ip.push_back(a[i]);
    }

    strand_sort(ip, op);

    for(auto i : op) {
        cout << i << " ";
    }
    cout << endl;
} 

int main() {
    int arr[] = {4, 2, 10, 13, 6, 1, 16, 7, 17};
    int n = sizeof(arr) / sizeof(arr[0]);

    int no = 1;
    cout << no++ << ": ";
    selection_sort(arr, n);
    cout << no++ << ": ";
    bubble_sort(arr, n);
    cout << no++ << ": ";
    insertion_sort(arr, n);
    cout << no++ << ": ";
    merge_util(arr, n);
    cout << no++ << ": ";
    quick_util(arr, n);
    cout << no++ << ": ";
    heap_sort(arr, n);
    cout << no++ << ": ";
    count_sort(arr, n);
    cout << no++ << ": ";
    radix_sort(arr, n);
    cout << no++ << ": ";
    shell_sort(arr, n);
    cout << no++ << ": ";
    tim_sort(arr, n);
    cout << no++ << ": ";
    comb_sort(arr, n);
    cout << no++ << ": ";
    pigeonhole_sort(arr, n);
    cout << no++ << ": ";
    cycle_sort(arr, n);
    cout << no++ << ": ";
    cocktail_sort(arr, n);
    cout << no++ << ": ";
    strand_util(arr, n);
    
    return 0;
}