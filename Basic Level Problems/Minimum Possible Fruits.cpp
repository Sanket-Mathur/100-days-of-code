#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
	    float q, p;
	    cin >> q >> p;
	    
	    int i=1;
        while(1) {
            if(ceil(i*p/100) < ceil(i*q/100)) {
                cout<<i<<endl;
                break;
            }
            i++;
        }
	}
	return 0;
}