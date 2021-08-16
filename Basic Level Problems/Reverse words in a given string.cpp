// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        stack<string> collection;
        string temp = "";
        for (int i = 0; i < S.size(); ++i) {
            if (S[i] == '.') {
                collection.push(temp);
                temp = "";
            } else {
                temp += S[i];
            }
        }
        collection.push(temp);
        
        temp = "";
        while (!collection.empty()) {
            temp += collection.top();
            collection.pop();
            if (!collection.empty())
                temp += ".";
        }
        
        return temp;
    } 
};

// { Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}  // } Driver Code Ends