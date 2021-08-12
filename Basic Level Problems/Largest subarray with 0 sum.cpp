// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int maxLen(int A[], int n);

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++)
            cin >> A[i];
        cout << maxLen(A, N) << endl;
    }
}
// } Driver Code Ends


/*You are required to complete this function*/

int maxLen(int A[], int n)
{
    unordered_map<int, int> sums;
    int maxlen = 0, sum = 0;
    for (int i = 0; i < n; ++i) {
        if (sums.find(sum) != sums.end()) {
            maxlen = max(maxlen, i - sums.find(sum)->second);
        } else {
            sums.insert(pair<int, int> (sum, i));
        }
        sum += A[i];
    }
    if (sums.find(sum) != sums.end()) {
        maxlen = max(maxlen, n - sums.find(sum)->second);
    }
    return maxlen;
}
