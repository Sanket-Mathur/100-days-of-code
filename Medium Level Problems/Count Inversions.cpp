// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int inversionCount(long long arr[], long long N)
    {
        long long temp[N];
        return mergeSort(arr, temp, 0, N - 1);
    }
    long long int mergeSort(long long arr[], long long temp[], long long low, long long high) {
        long long int inv = 0, mid;
        if (low < high) {
            mid = (low + high) / 2;
            inv += mergeSort(arr, temp, low, mid);
            inv += mergeSort(arr, temp, mid + 1, high);
            inv += merge(arr, temp, low, mid + 1, high);
        }
        return inv;
    }
    long long int merge(long long arr[], long long temp[], long long low, long long mid, long long high) {
        long long int inv = 0;
        long long i = low, j = mid, k = low;
        while (i <= mid - 1 && j <= high) {
            if (arr[i] <= arr[j]) {
                temp[k++] = arr[i++];
            } else {
                temp[k++] = arr[j++];
                inv += mid - i;
            }
        }
        while (i <= mid - 1)
            temp[k++] = arr[i++];
        while (j <= high) 
            temp[k++] = arr[j++];
        
        for (int i = low; i <= high; ++i) 
            arr[i] = temp[i];
        
        return inv;
    }

};

// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends