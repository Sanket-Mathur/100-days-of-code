// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


 // } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
    int maxArea(int M[MAX][MAX], int n, int m) {
        int maxAreaLocal = INT_MIN;
        vector<int> hist(m, 0);
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (M[i][j] == 0) {
                    hist[j] = 0;
                } else {
                    hist[j] += 1;
                    maxAreaLocal = max(maxAreaLocal, hist[j]);
                }
            }
            
            // int minHigh = INT_MAX, runLen = 0;
            // for (int j = 0; j < m; ++j) {
            //     if (hist[j] == 0) {
            //         runLen = 0;
            //         minHigh = INT_MAX;
            //     } else {
            //         runLen++;
            //         minHigh = min(minHigh, hist[j]);
            //         maxAreaLocal = max(maxAreaLocal, minHigh * runLen);
            //     }
            // }
            
            maxAreaLocal = max(maxAreaLocal, getMaxArea(hist));
        }
        
        return maxAreaLocal;
    }
    
    int getMaxArea(vector<int> hist) {
        stack<int> s;
        
        s.push(-1);
        int area = hist[0];
        int i = 0;
        
        vector<int> left_smaller(hist.size(), -1), right_smaller(hist.size(), hist.size());
        while (i < hist.size()) {
            while (!s.empty() && s.top() != -1 && hist[s.top()] > hist[i]) {
                right_smaller[s.top()] = i;
                s.pop();
            }
            
            if (i > 0 && hist[i] == hist[i-1]) {
                left_smaller[i] = left_smaller[i-1];
            } else {
                left_smaller[i] = s.top();
            }
            
            s.push(i);
            i++;
        }
        
        for (int j = 0; j < hist.size(); ++j) {
            area = max(area, hist[j] * (right_smaller[j] - left_smaller[j] - 1));
        }
        
        return area;
    }
};


// { Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}
  // } Driver Code Ends