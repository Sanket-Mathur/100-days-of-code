#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while (t--) {
	    long long int a, b, c, n;
	    cin >> a >> b >> c >> n;
	    
	    for (int i = 4; i <= n; ++i) {
	        long long int temp = a;
	        a = b;
	        b = c;
	        c = a + b + temp;
	    }
	    
	    cout << c << endl;
	}
	
	return 0;
}