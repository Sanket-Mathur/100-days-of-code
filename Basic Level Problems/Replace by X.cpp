#include <iostream>
#include <string>
using namespace std;

int main() {
	int t;
	cin >> t;
	cin.ignore();
	while (t--) {
	    string s, pattern;
	    getline(cin, s);
	    getline(cin, pattern);
	    
	    while (s.find(pattern) != string::npos) {
	        s.replace(s.find(pattern), pattern.length(), "X");
	    }
	    
	    bool X = false;
	    for (int i = 0; i < s.length(); ++i) {
	        if (s[i] == 'X') {
	            if (!X) {
	                X = true;
	                cout << s[i];
	            }
	        } else {
	            X = false;
	            cout << s[i];
	        }
	    }
	    cout << endl;
	}
	return 0;
}