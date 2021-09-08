// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int countWays(int N, string S){
        int MOD = 1003;
        
        string oper = "";
        string boolean = "";
        for (int i = 0; i < N; ++i) {
            if (S[i] == 'T' || S[i] == 'F') {
                boolean += S[i];
            } else {
                oper += S[i];
            }
        }
        
        int n = boolean.length();
        int dpt[n][n];
        int dpf[n][n];
        
        for (int g = 0; g < n; ++g) {
            for (int i = 0, j = g; j < n; ++i, ++j) {
                dpt[i][j] = 0;
                dpf[i][j] = 0;
                if (g == 0) {
                    dpt[i][j] = boolean[i] == 'T' ? 1 : 0;
                    dpf[i][j] = boolean[i] == 'F' ? 1 : 0;
                } else {
                    for (int k = i; k < j; ++k) {
                        int ltc = dpt[i][k], rtc = dpt[k + 1][j];
                        int lfc = dpf[i][k], rfc = dpf[k + 1][j];
                        
                        if (oper[k] == '&') {
                            dpt[i][j] += (ltc * rtc) % MOD;
                            dpf[i][j] += (ltc * rfc + lfc * rtc + lfc * rfc) % MOD;
                        } else if (oper[k] == '|') {
                            dpt[i][j] += (ltc * rtc + ltc * rfc + lfc * rtc) % MOD;
                            dpf[i][j] += (lfc * rfc) % MOD;
                        } else {
                            dpt[i][j] += (ltc * rfc + lfc * rtc) % MOD;
                            dpf[i][j] += (ltc * rtc + lfc * rfc) % MOD;
                        }
                    }
                }
            }
        }
        
        return dpt[0][n-1] % MOD;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}  // } Driver Code Ends