// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 

 // } Driver Code Ends
class Solution{
  public:
    /*You are required to complete below function */
    string multiplyStrings(string s1, string s2) {
        if (s1 == "0" || s2 == "0") {
            return s1 == "0" ? s1 : s2;
        }
        
        string result = "";
        int a, b, m;
        int carry1 = 0, carry2 = 0;
        bool neg = false;
        
        if (s1[0] == '-') neg = !neg;
        if (s2[0] == '-') neg = !neg;
        
        for (int i = s2.size() - 1; i >= (s2[0] == '-' ? 1 : 0); --i) {
            for (int j = s1.size() - 1; j >= (s1[0] == '-' ? 1 : 0); --j) {
                a = s1[j] - '0';
                b = s2[i] - '0';
                
                m = a*b + carry1;
                if (m <= 9) {
                    carry2 = add_digit(result, m + carry2, s2.size() - i - 1 + s1.size() - j - 1);
                    carry1 = 0;
                } else {
                    carry1 = m / 10;
                    m = m % 10;
                    carry2 = add_digit(result, m + carry2, s2.size() - i - 1 + s1.size() - j - 1);
                }
            }
            carry1 += carry2;
            while (carry1) {
                result += '0' + (carry1 % 10);
                carry1 = carry1 / 10;
            }
            carry2 = 0;
        }
        
        reverse(result.begin(), result.end());
        if (result[0] == '0') {
            result.erase(result.begin());
        }
        if (neg) {
            result = "-" + result;
        }
        
        return result;
    }
    int add_digit(string &result, int number, int pos) {
        int carry = number / 10;
        number %= 10;
        
        if (result.size() <= pos) {
            result += '0' + number;
        } else {
            int no = result[pos] - '0';
            no = no + number;
            carry += no / 10;
            no %= 10;
            result[pos] = '0' + no;
        }
        
        return carry;
    }
};

// { Driver Code Starts.
 
int main() {
     
    int t;
    cin>>t;
    while(t--)
    {
    	string a;
    	string b;
    	cin>>a>>b;
    	Solution obj;
    	cout<<obj.multiplyStrings(a,b)<<endl;
    }
     
}  // } Driver Code Ends