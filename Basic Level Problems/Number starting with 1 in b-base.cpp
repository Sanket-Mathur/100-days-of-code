#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
	    int n, b;
	    cin >> n >> b;
	    
	    if (b > 1) {
	        while (n >= b) {
	            n /= b;
	        }
	        if (n == 1) {
	            cout << "Yes" << endl;
	        } else {
	            cout << "No" << endl;
	        }
	    } else {
	        cout << "No" << endl;
	    }
	    
	}
	return 0;
}