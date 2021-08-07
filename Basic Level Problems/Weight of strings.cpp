#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	cin.ignore();
	while (t--) {
	    string s1, s2;
	    getline(cin, s1);
	    getline(cin, s2);
	    
	    int value1 = 0, value2 = 0;
	    for (int i = 0; i < s1.length(); ++i) {
	        value1 += s1[i] - 96;
	    }
	    for (int i = 0; i < s2.length(); ++i) {
	        value2 += s2[i] - 96;
	    }
	    if (value1 == value2) {
	        cout << "equal" << endl;
	        continue;
	    }
	    cout << (value1 > value2 ? 1 : 2) << endl;
	}
	return 0;
}