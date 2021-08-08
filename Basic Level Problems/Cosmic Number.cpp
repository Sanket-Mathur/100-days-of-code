#include <iostream>
#include <stack>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
	    int num;
	    cin >> num;
	    
	    if (num == 0) {
	        cout << 0 << endl;
	        continue;
	    }
	    
	    int n = num;
	    
	    stack<int> digits;
	    while (num) {
	        if (num >= 10) {
	            digits.push(9);
	            num -= 9;
	        } else {
	            digits.push(num);
	            num = 0;
	        }
	    }
	    
	    while (!digits.empty()) {
	        cout << digits.top();
	        digits.pop();
	    }
	    for (int i = 0; i < n; ++i) {
	        cout << 0;
	    }
	    cout << endl;
	}
	return 0;
}