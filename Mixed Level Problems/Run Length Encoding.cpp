// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

string encode(string src);    
 
int main() {
	
	int T;
	cin>>T;
	while(T--)
	{
		string str;
		cin>>str;
		
		cout<<encode(str)<<endl;
	}
	return 0;
}// } Driver Code Ends


/*You are required to complete this function */

string encode(string src)
{
    int cnt = 1;
    string result = "";
    result += src[0];
    
    for (int i = 1; i < src.length(); ++i) {
        if (src[i] != src[i-1]) {
            result += to_string(cnt);
            result += src[i];
            cnt = 1;
        } else {
            cnt++;
        }
    }
    result += to_string(cnt);
    
    return result;
}     
 
